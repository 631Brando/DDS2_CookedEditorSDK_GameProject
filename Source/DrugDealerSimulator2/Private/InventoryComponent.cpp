#include "InventoryComponent.h"
#include "Math/UnrealMathUtility.h"
#include "Dom/JsonObject.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"
#include "AutoItemConvertion.h"
#include "ItemConvertionOutput.h"
#include "ContainerConfig.h"
#include "ItemPropertyData.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"
#include "Misc/CommandLine.h"
#include "Misc/Parse.h"
#include "PieOrdinaryCraft.h"

// ---------------------------------------------------------------------------------------------
// REDACTED - implementations withheld.
//
// Every declaration below matches the real InventoryComponent.cpp exactly: same signatures, same
// order, same parameter names. Only the bodies are removed. This is the form that is safe to
// share: the real implementation came from the game's developer privately and is not ours to
// redistribute.
//
// It is a valid translation unit - each stub returns a defined value and clears its out-params, so
// nothing reads indeterminate memory. The stubs give Blueprints a class with the correct
// reflected API to bind against. The opt-in transfers below are SDK test implementations
// for ordinary whole stacks in standalone PIE.
//
// The constructor keeps its member initialisation, which is plain defaults rather than logic;
// stripping it would leave fields indeterminate instead of merely empty.
// ---------------------------------------------------------------------------------------------

namespace
{
bool PieTransfersEnabled()
{
#if WITH_EDITOR
    static const bool Enabled = FParse::Param(FCommandLine::Get(), TEXT("DDS2PIEInventoryTransfers"));
    return Enabled;
#else
    return false;
#endif
}

struct FPieGridSize
{
    int32 Total = 0;
    int32 Concealed = 0;

    int32 Ordinary() const { return Total - Concealed; }
};

FPieGridSize GetPieGridSize(const UInventoryComponent& Inventory)
{
    const UWorld* World = Inventory.GetWorld();
    const AActor* Owner = Inventory.GetOwner();
    if (!PieTransfersEnabled() || !World || World->WorldType != EWorldType::PIE ||
        World->GetNetMode() != NM_Standalone || !Owner || !Owner->HasAuthority() ||
        Inventory.UnboundSize || !Inventory.ItemTypeRestriction.IsNone() ||
        !Inventory.WornClothes.IsEmpty() || !Inventory.ConfigDatabase)
    {
        return {};
    }

    const FContainerConfig* Config = Inventory.ConfigDatabase->FindRow<FContainerConfig>(
        Inventory.InventoryConfig, TEXT("Standalone PIE inventory"), false);
    if (!Config)
    {
        return {};
    }
    const int64 Count = static_cast<int64>(Config->BaseContainerSize) + Inventory.CustomSizeBoost;
    if (Count <= 0 || Count > MAX_int32 ||
        Config->BaseConcealedSlots < 0 || Config->BaseConcealedSlots > Count)
    {
        return {};
    }
    return {static_cast<int32>(Count), Config->BaseConcealedSlots};
}

bool IsSlotInGrid(int32 Index, int32 SlotCount)
{
    return Index >= 0 && Index < SlotCount;
}

bool HasConsistentSlots(const UInventoryComponent& Inventory, int32 SlotCount)
{
    if (SlotCount <= 0 || Inventory.StoredItems.Num() != Inventory.AssignedIndexes.Num())
    {
        return false;
    }
    for (const auto& Slot : Inventory.AssignedIndexes)
    {
        const FInventoryObjectData* Item = Inventory.StoredItems.Find(Slot.Value);
        if (!IsSlotInGrid(Slot.Key, SlotCount) || !Slot.Value.IsValid() || !Item ||
            Item->StackGuid != Slot.Value || Item->IndexPlacement != Slot.Key || Item->CurStack <= 0)
        {
            return false;
        }
    }
    return true;
}

bool HasOrdinaryPayload(const FInventoryObjectData& Item)
{
    return !Item.ItemId.IsNone() && Item.ItemId != TEXT("DYN-SUBSTANCE-PACK") &&
        Item.SubstanceContents.SubstanceID.IsNone() && !Item.SubstanceContents.MixGuid.IsValid() &&
        Item.SubstanceContents.GramAmount == 0.0f && FMath::IsFinite(Item.CurHealth);
}

const FItemData* FindOrdinaryItem(const UInventoryComponent& Inventory, const FInventoryObjectData& Item)
{
    if (!Inventory.ItemDatabase || !HasOrdinaryPayload(Item))
    {
        return nullptr;
    }
    const FItemData* Row = Inventory.ItemDatabase->FindRow<FItemData>(
        Item.ItemId, TEXT("Standalone PIE inventory"), false);
    return Row && Row->ItemCategory != EItemCategory::Keys && Row->InventoryMaxStack > 0 ? Row : nullptr;
}

bool IsSameStackPayload(const FInventoryObjectData& Left, const FInventoryObjectData& Right)
{
    return Left.ItemId == Right.ItemId && Left.CurHealth == Right.CurHealth &&
        Left.CurUsesLeft == Right.CurUsesLeft && Left.ItemTimeoutStatus == Right.ItemTimeoutStatus &&
        Left.SubstanceContents.SubstanceID == Right.SubstanceContents.SubstanceID &&
        Left.SubstanceContents.MixGuid == Right.SubstanceContents.MixGuid &&
        Left.SubstanceContents.GramAmount == Right.SubstanceContents.GramAmount;
}
}

UInventoryComponent::UInventoryComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->BaseQuickSlotCount = 0;
    this->IsPlayerInventory = false;
    this->UsesClothes = false;
    this->UnboundSize = false;
    this->ClothesSlotDT = NULL;
    this->ItemDatabase = NULL;
    this->ConfigDatabase = NULL;
    this->PropertyDatabase = NULL;
    this->ItemConvertionDatabase = NULL;
    this->CustomSizeBoost = 0;
    PrimaryComponentTick.bCanEverTick = true;
}

void UInventoryComponent::AddNewItem(FName ItemId, int32 Quantity, bool CheckOnly, const FString& TimeoutStatus, int32& Leftover)
{
    Leftover = 0;
    if (!PieTransfersEnabled())
    {
        return;
    }

    Leftover = FMath::Max(Quantity, 0);
    const FPieGridSize Grid = GetPieGridSize(*this);
    if (Quantity <= 0 || IsPlayerInventory || !HasConsistentSlots(*this, Grid.Total))
    {
        return;
    }

    FInventoryObjectData NewStack;
    NewStack.ItemId = ItemId;
    const FItemData* Row = FindOrdinaryItem(*this, NewStack);
    if (!Row)
    {
        return;
    }
    if (ItemConvertionDatabase)
    {
        if (ItemConvertionDatabase->GetRowStruct() != FAutoItemConvertion::StaticStruct())
        {
            return;
        }
        const FAutoItemConvertion* Conversion = ItemConvertionDatabase->FindRow<FAutoItemConvertion>(
            ItemId, TEXT("Standalone PIE stock"), false);
        if (Conversion && Conversion->InstantItemConvertion)
        {
            return;
        }
    }

    NewStack.CurHealth = Row->InventoryMaxHealth;
    NewStack.CurUsesLeft = Row->InventoryMaxUses;
    NewStack.ItemTimeoutStatus = TimeoutStatus;
    NewStack.SubstanceContents = Row->DefaultSubContents;
    if (!HasOrdinaryPayload(NewStack))
    {
        return;
    }

    // Fill compatible stacks first, then allocate free ordinary cells.
    for (int32 Index = 0; Index < Grid.Ordinary() && Leftover > 0; ++Index)
    {
        const FGuid* Guid = AssignedIndexes.Find(Index);
        if (!Guid)
        {
            continue;
        }
        FInventoryObjectData& Stack = StoredItems.FindChecked(*Guid);
        if (Stack.CurStack < Row->InventoryMaxStack && IsSameStackPayload(Stack, NewStack))
        {
            const int32 Added = FMath::Min(Leftover, Row->InventoryMaxStack - Stack.CurStack);
            Leftover -= Added;
            if (!CheckOnly)
            {
                Stack.CurStack += Added;
            }
        }
    }
    for (int32 Index = 0; Index < Grid.Ordinary() && Leftover > 0; ++Index)
    {
        if (AssignedIndexes.Contains(Index))
        {
            continue;
        }
        const int32 Added = FMath::Min(Leftover, Row->InventoryMaxStack);
        Leftover -= Added;
        if (!CheckOnly)
        {
            NewStack.StackGuid = FGuid::NewGuid();
            NewStack.IndexPlacement = Index;
            NewStack.CurStack = Added;
            StoredItems.Add(NewStack.StackGuid, NewStack);
            AssignedIndexes.Add(Index, NewStack.StackGuid);
        }
    }

    if (!CheckOnly && Leftover < Quantity && !BlockInventoryUpdate)
    {
        InventoryUpdated();
        ItemAdded(ItemId, Quantity - Leftover);
    }
}

void UInventoryComponent::AddNewItemArray(TArray<FName> ItemIds, TArray<int32> Quantities)
{
}

void UInventoryComponent::AddSpecificItem(FInventoryObjectData InventoryData, bool CheckOnly, int32& Leftover, int32 Quantity, int32 IndexOverride)
{
    Leftover = 0;
    if (!PieTransfersEnabled())
    {
        return;
    }

    Leftover = Quantity;
    const FPieGridSize Grid = GetPieGridSize(*this);
    if (Quantity <= 0 || InventoryData.CurStack != Quantity || !IsSlotInGrid(IndexOverride, Grid.Ordinary()) ||
        !HasConsistentSlots(*this, Grid.Total))
    {
        return;
    }
    const FItemData* Row = FindOrdinaryItem(*this, InventoryData);
    if (!Row || Quantity > Row->InventoryMaxStack)
    {
        return;
    }

    if (const FGuid* TargetGuid = AssignedIndexes.Find(IndexOverride))
    {
        FInventoryObjectData& Target = StoredItems.FindChecked(*TargetGuid);
        if (!IsSameStackPayload(Target, InventoryData) || Target.CurStack > Row->InventoryMaxStack - Quantity)
        {
            return;
        }
        if (!CheckOnly)
        {
            Target.CurStack += Quantity;
        }
    }
    else if (!CheckOnly)
    {
        InventoryData.StackGuid = FGuid::NewGuid();
        InventoryData.IndexPlacement = IndexOverride;
        StoredItems.Add(InventoryData.StackGuid, InventoryData);
        AssignedIndexes.Add(IndexOverride, InventoryData.StackGuid);
    }

    Leftover = 0;
    if (!CheckOnly && !BlockInventoryUpdate)
    {
        InventoryUpdated();
        ItemAdded(InventoryData.ItemId, Quantity);
    }
}

FItemData UInventoryComponent::GetDynamicPackageMeta(FInventoryObjectData ObjectData)
{
    return FItemData();
}

FString UInventoryComponent::CreateInventoryContentString(const TArray<FInventoryObjectData>& InventoryData)
{
    return FString();
}

TArray<FInventoryObjectData> UInventoryComponent::DecodeInventoryContentString(const FString& JsonString)
{
    return TArray<FInventoryObjectData>();
}

void UInventoryComponent::AddMoney(FName CurrencyID, EMoneyDenomination Denomination, int32 Quantity)
{
}

int32 UInventoryComponent::CountPlayerMoney(FName CurrencyID)
{
    return 0;
}

void UInventoryComponent::ChargePlayerMoney(FName CurrencyID, int32 Quantity)
{
}

void UInventoryComponent::CountItems(FName ItemId, FName ItemSpecialType, bool SumAmounts, int32& OutNumber)
{
    OutNumber = 0;
    const FPieGridSize Grid = GetPieGridSize(*this);
    if (!PieOrdinaryCraft::IsEnabled(GetOwner()) || (ItemId.IsNone() && ItemSpecialType.IsNone()) ||
        !HasConsistentSlots(*this, Grid.Total))
    {
        return;
    }
    int64 Total = 0;
    for (const auto& Entry : StoredItems)
    {
        const FInventoryObjectData& Stack = Entry.Value;
        if (const FItemData* Row = FindOrdinaryItem(*this, Stack))
        {
            if ((!ItemId.IsNone() && Stack.ItemId == ItemId) ||
                (!ItemSpecialType.IsNone() && Row->ItemSpecialType == ItemSpecialType))
            {
                Total += static_cast<int64>(Stack.CurStack) *
                    (SumAmounts ? FMath::Max(0, Stack.CurUsesLeft) : 1);
                if (Total >= MAX_int32)
                {
                    OutNumber = MAX_int32;
                    return;
                }
            }
        }
    }
    OutNumber = static_cast<int32>(Total);
}

bool UInventoryComponent::CheckIndexOccupied(int32 IndexToCheck)
{
    const int32 Slots = GetPieGridSize(*this).Total;
    return IsSlotInGrid(IndexToCheck, Slots) && HasConsistentSlots(*this, Slots) &&
        AssignedIndexes.Contains(IndexToCheck);
}

void UInventoryComponent::MoveItem(FGuid ItemToMove, int32 TargetIndex, int32 MoveQuantity, bool& CanMove, int32& StackLeft)
{
    CanMove = false;
    StackLeft = 0;
    if (!PieTransfersEnabled())
    {
        return;
    }
    StackLeft = MoveQuantity;
    const FPieGridSize Grid = GetPieGridSize(*this);
    if (!IsSlotInGrid(TargetIndex, Grid.Ordinary()) || !CheckStackQuantityExists(ItemToMove, MoveQuantity))
    {
        return;
    }

    FInventoryObjectData& Source = StoredItems.FindChecked(ItemToMove);
    const int32 SourceIndex = Source.IndexPlacement;
    if (SourceIndex != TargetIndex)
    {
        if (const FGuid* TargetGuid = AssignedIndexes.Find(TargetIndex))
        {
            FInventoryObjectData& Target = StoredItems.FindChecked(*TargetGuid);
            const FItemData* Row = FindOrdinaryItem(*this, Source);
            if (!Row || !IsSameStackPayload(Target, Source) ||
                Target.CurStack > Row->InventoryMaxStack - MoveQuantity)
            {
                return;
            }
            Target.CurStack += MoveQuantity;
            StoredItems.Remove(ItemToMove);
        }
        else
        {
            Source.IndexPlacement = TargetIndex;
            AssignedIndexes.Add(TargetIndex, ItemToMove);
        }
        AssignedIndexes.Remove(SourceIndex);
        if (!BlockInventoryUpdate)
        {
            InventoryUpdated();
        }
    }
    StackLeft = 0;
    CanMove = true;
}

bool UInventoryComponent::RemoveStack(FGuid StackGuid)
{
    return false;
}

bool UInventoryComponent::SwitchStacks(FGuid Stack01, FGuid Stack02)
{
    return false;
}

bool UInventoryComponent::RemoveStackQuantity(FGuid StackGuid, int32 Quantity)
{
    if (!CheckStackQuantityExists(StackGuid, Quantity))
    {
        return false;
    }
    const FInventoryObjectData& Item = StoredItems.FindChecked(StackGuid);
    const FName ItemId = Item.ItemId;
    AssignedIndexes.Remove(Item.IndexPlacement);
    StoredItems.Remove(StackGuid);
    if (!BlockInventoryUpdate)
    {
        InventoryUpdated();
        ItemRemoved(ItemId, Quantity);
    }
    return true;
}

void UInventoryComponent::RemoveItemQuantity(FName ItemId, int32 Quantity, int32& RemovedTotal)
{
    RemovedTotal = 0;
    const FPieGridSize Grid = GetPieGridSize(*this);
    if (!PieOrdinaryCraft::IsEnabled(GetOwner()) || ItemId.IsNone() || Quantity <= 0 ||
        !HasConsistentSlots(*this, Grid.Total))
    {
        return;
    }
    for (auto It = StoredItems.CreateIterator(); It && RemovedTotal < Quantity; ++It)
    {
        FInventoryObjectData& Stack = It.Value();
        if (Stack.ItemId != ItemId || !FindOrdinaryItem(*this, Stack))
        {
            continue;
        }
        const int32 Removed = FMath::Min(Stack.CurStack, Quantity - RemovedTotal);
        Stack.CurStack -= Removed;
        RemovedTotal += Removed;
        if (Stack.CurStack == 0)
        {
            AssignedIndexes.Remove(Stack.IndexPlacement);
            It.RemoveCurrent();
        }
    }
    if (RemovedTotal > 0 && !BlockInventoryUpdate)
    {
        InventoryUpdated();
        ItemRemoved(ItemId, RemovedTotal);
    }
}

bool UInventoryComponent::UseStackItem(FGuid StackGuid)
{
    return false;
}

int32 UInventoryComponent::UseItemType(FName SpecialTypeID, int32 UseQuantity)
{
    return 0;
}

bool UInventoryComponent::CheckStackExists(FGuid StackGuid)
{
    return false;
}

bool UInventoryComponent::CheckStackQuantityExists(FGuid StackGuid, int32 Quantity)
{
    const FPieGridSize Grid = GetPieGridSize(*this);
    const FInventoryObjectData* Item = StoredItems.Find(StackGuid);
    // Refuse splits before the widget can debit the source. Only full stacks are supported.
    if (Quantity <= 0 || !Item || Item->CurStack != Quantity ||
        !IsSlotInGrid(Item->IndexPlacement, Grid.Ordinary()) || !HasConsistentSlots(*this, Grid.Total))
    {
        return false;
    }
    const FItemData* Row = FindOrdinaryItem(*this, *Item);
    return Row && Quantity <= Row->InventoryMaxStack;
}

int32 UInventoryComponent::GetInventoryLenght()
{
    return GetPieGridSize(*this).Total;
}

int32 UInventoryComponent::GetQuickSlotNum()
{
    return 0;
}

TArray<FInventoryGridData> UInventoryComponent::GetQuickSlotList()
{
    return TArray<FInventoryGridData>();
}

TArray<FQuestSlotListItem> UInventoryComponent::GetQuestItemList()
{
    return TArray<FQuestSlotListItem>();
}

FName UInventoryComponent::GetQuickSlotItem(int32 Index)
{
    return NAME_None;
}

FInventoryObjectData UInventoryComponent::GetQuickSlotItemData(int32 Index)
{
    return FInventoryObjectData();
}

void UInventoryComponent::AddQuestItem(FName ItemId, int32 Quantity)
{
}

bool UInventoryComponent::HasQuestItem(FName ItemId, int32 Quantity)
{
    return false;
}

void UInventoryComponent::RemoveQuestItem(FName ItemId, int32 Quantity)
{
}

void UInventoryComponent::RemoveAllQuestItems(FName ItemId)
{
}

void UInventoryComponent::PurgeQuestItems()
{
}

void UInventoryComponent::SetCustomSizeBoost(int32 SizeBoost)
{
}

void UInventoryComponent::SetBlockInventoryUpdate(bool BlockState)
{
}

int32 UInventoryComponent::GetInventoryFreeSpace()
{
    const FPieGridSize Grid = GetPieGridSize(*this);
    if (!PieOrdinaryCraft::IsEnabled(GetOwner()) || !HasConsistentSlots(*this, Grid.Total))
    {
        return 0;
    }
    int32 Empty = Grid.Ordinary();
    for (const auto& Slot : AssignedIndexes)
    {
        Empty -= Slot.Key < Grid.Ordinary() ? 1 : 0;
    }
    return Empty;
}

int32 UInventoryComponent::GetInventoryItemSpace(FName ItemId)
{
    return 0;
}

int32 UInventoryComponent::GetInventoryStackSpace(FName ItemId)
{
    const FPieGridSize Grid = GetPieGridSize(*this);
    if (!PieOrdinaryCraft::IsEnabled(GetOwner()) || !HasConsistentSlots(*this, Grid.Total))
    {
        return 0;
    }
    FInventoryObjectData Probe;
    Probe.ItemId = ItemId;
    const FItemData* Row = FindOrdinaryItem(*this, Probe);
    if (!Row)
    {
        return 0;
    }
    Probe.SubstanceContents = Row->DefaultSubContents;
    if (!HasOrdinaryPayload(Probe))
    {
        return 0;
    }
    int64 Space = 0;
    for (const auto& Entry : StoredItems)
    {
        const FInventoryObjectData& Stack = Entry.Value;
        if (Stack.ItemId == ItemId && Stack.IndexPlacement < Grid.Ordinary() &&
            Stack.CurHealth == 0.0f && Stack.CurUsesLeft == 0 && HasOrdinaryPayload(Stack))
        {
            Space += FMath::Max(0, Row->InventoryMaxStack - Stack.CurStack);
        }
    }
    return static_cast<int32>(FMath::Min<int64>(Space, MAX_int32));
}

int32 UInventoryComponent::GetInventoryStackSpaceDynamic(FInventoryObjectData ObjectData)
{
    return 0;
}

int32 UInventoryComponent::GetInventoryConceladSlotCount()
{
    return GetPieGridSize(*this).Concealed;
}

void UInventoryComponent::GetInventoryGrid(TArray<FInventoryGridData>& OutGridData)
{
    OutGridData.Reset();
    const FPieGridSize Grid = GetPieGridSize(*this);
    if (!HasConsistentSlots(*this, Grid.Total))
    {
        return;
    }
    OutGridData.SetNum(Grid.Total);
    for (int32 Index = 0; Index < Grid.Total; ++Index)
    {
        FInventoryGridData& Cell = OutGridData[Index];
        Cell.ObjectData.IndexPlacement = Index;
        Cell.Concealed = Index >= Grid.Ordinary();
        if (const FGuid* Guid = AssignedIndexes.Find(Index))
        {
            Cell.ObjectData = StoredItems.FindChecked(*Guid);
            Cell.Occupied = true;
        }
    }
}

int32 UInventoryComponent::GetInventoryDamagedSlotCount()
{
    return 0;
}

bool UInventoryComponent::CompareItemsStackable(FInventoryObjectData Object1, FInventoryObjectData Object2)
{
    return GetPieGridSize(*this).Ordinary() > 0 && FindOrdinaryItem(*this, Object1) &&
        FindOrdinaryItem(*this, Object2) && IsSameStackPayload(Object1, Object2);
}

void UInventoryComponent::PurgeInventory()
{
}

FInventoryObjectData UInventoryComponent::ConstructInventoryDefaults(FName SourceItemID)
{
    return FInventoryObjectData();
}

FInventoryGridData UInventoryComponent::GetSpecialSlotContent(FName SlotID)
{
    return FInventoryGridData();
}

bool UInventoryComponent::TrySetSpecialSlotContent(FName SlotID, FInventoryObjectData content)
{
    return false;
}

void UInventoryComponent::GetSpecialSlotsList(TArray<FSpecialSlotListItem>& OutSlots)
{
    OutSlots.Reset();
}

void UInventoryComponent::RemoveSpecialSlotItem(FName SlotID)
{
}

void UInventoryComponent::SpecialSlotDamage(FName SlotID, float Damage, bool DestroyOnZero)
{
}

void UInventoryComponent::QuickSlotDamage(int32 Index, float Damage, bool DestroyOnZero)
{
}

FInventoryGridData UInventoryComponent::GetClothesSlotContent(FName SlotID)
{
    return FInventoryGridData();
}

bool UInventoryComponent::TrySetClothesSlotContent(FName SlotID, FInventoryObjectData content)
{
    return false;
}

void UInventoryComponent::RemoveClothItem(FName SlotID)
{
}

void UInventoryComponent::GetWornAllClothes(TArray<FInventoryObjectData>& OutClothes)
{
    OutClothes.Reset();
}

void UInventoryComponent::GetClothSlotsList(TArray<FSpecialSlotListItem>& OutSlots)
{
    OutSlots.Reset();
}

void UInventoryComponent::GetClothesStats(TArray<FPropertyListItem>& AllProperties)
{
    AllProperties.Reset();
}

void UInventoryComponent::SetDefaultClothes()
{
}

void UInventoryComponent::AddClothDamage(FName SlotID, float Damage)
{
}

void UInventoryComponent::GetInventoryWeight(float& WeightTotal, FInventoryWeightDetails& WeightDetails)
{
    WeightTotal = 0.0f;
    WeightDetails = FInventoryWeightDetails();
    const FPieGridSize Grid = GetPieGridSize(*this);
    if (!HasConsistentSlots(*this, Grid.Total))
    {
        return;
    }
    double TotalGrams = 0.0;
    for (const auto& Entry : StoredItems)
    {
        const FInventoryObjectData& Stack = Entry.Value;
        const FItemData* Row = FindOrdinaryItem(*this, Stack);
        if (!Row || !FMath::IsFinite(Row->InventoryWeightGrams) || Row->InventoryWeightGrams < 0.0f)
        {
            return;
        }
        TotalGrams += static_cast<double>(Row->InventoryWeightGrams) * Stack.CurStack;
    }
    if (TotalGrams <= MAX_flt)
    {
        WeightTotal = static_cast<float>(TotalGrams);
        WeightDetails.WeightItems = WeightTotal;
    }
}

bool UInventoryComponent::HasInventorySpaceForTransaction(FName ItemId, int32 ItemCount, TArray<FGuid> SourceGuids, TArray<int32> SourceQuantities)
{
    return false;
}

