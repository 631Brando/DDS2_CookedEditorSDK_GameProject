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

int32 GetPieSlotCount(const UInventoryComponent& Inventory)
{
    const UWorld* World = Inventory.GetWorld();
    const AActor* Owner = Inventory.GetOwner();
    if (!PieTransfersEnabled() || !World || World->WorldType != EWorldType::PIE ||
        World->GetNetMode() != NM_Standalone || !Owner || !Owner->HasAuthority() ||
        Inventory.UnboundSize || !Inventory.ItemTypeRestriction.IsNone() ||
        !Inventory.WornClothes.IsEmpty() || !Inventory.ConfigDatabase)
    {
        return 0;
    }

    const FContainerConfig* Config = Inventory.ConfigDatabase->FindRow<FContainerConfig>(
        Inventory.InventoryConfig, TEXT("Standalone PIE inventory"), false);
    if (!Config || Config->BaseConcealedSlots != 0)
    {
        return 0;
    }
    const int64 Count = static_cast<int64>(Config->BaseContainerSize) + Inventory.CustomSizeBoost;
    return Count > 0 && Count <= MAX_int32 ? static_cast<int32>(Count) : 0;
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

const FItemData* FindOrdinaryItem(const UInventoryComponent& Inventory, const FInventoryObjectData& Item)
{
    if (!Inventory.ItemDatabase || Item.ItemId.IsNone() || Item.ItemId == TEXT("DYN-SUBSTANCE-PACK") ||
        !Item.SubstanceContents.SubstanceID.IsNone() || Item.SubstanceContents.MixGuid.IsValid() ||
        Item.SubstanceContents.GramAmount != 0.0f || !FMath::IsFinite(Item.CurHealth))
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
    const int32 Slots = GetPieSlotCount(*this);
    if (Quantity <= 0 || InventoryData.CurStack != Quantity || !IsSlotInGrid(IndexOverride, Slots) ||
        !HasConsistentSlots(*this, Slots))
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
}

bool UInventoryComponent::CheckIndexOccupied(int32 IndexToCheck)
{
    const int32 Slots = GetPieSlotCount(*this);
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
    const int32 Slots = GetPieSlotCount(*this);
    if (!IsSlotInGrid(TargetIndex, Slots) || !CheckStackQuantityExists(ItemToMove, MoveQuantity))
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
    const int32 Slots = GetPieSlotCount(*this);
    const FInventoryObjectData* Item = StoredItems.Find(StackGuid);
    // Refuse splits before the widget can debit the source. Only full stacks are supported.
    if (Quantity <= 0 || !Item || Item->CurStack != Quantity || !HasConsistentSlots(*this, Slots))
    {
        return false;
    }
    const FItemData* Row = FindOrdinaryItem(*this, *Item);
    return Row && Quantity <= Row->InventoryMaxStack;
}

int32 UInventoryComponent::GetInventoryLenght()
{
    return GetPieSlotCount(*this);
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
    return 0;
}

int32 UInventoryComponent::GetInventoryItemSpace(FName ItemId)
{
    return 0;
}

int32 UInventoryComponent::GetInventoryStackSpace(FName ItemId)
{
    return 0;
}

int32 UInventoryComponent::GetInventoryStackSpaceDynamic(FInventoryObjectData ObjectData)
{
    return 0;
}

int32 UInventoryComponent::GetInventoryConceladSlotCount()
{
    return 0;
}

void UInventoryComponent::GetInventoryGrid(TArray<FInventoryGridData>& OutGridData)
{
    OutGridData.Reset();
    const int32 Slots = GetPieSlotCount(*this);
    if (!HasConsistentSlots(*this, Slots))
    {
        return;
    }
    OutGridData.SetNum(Slots);
    for (int32 Index = 0; Index < Slots; ++Index)
    {
        FInventoryGridData& Cell = OutGridData[Index];
        Cell.ObjectData.IndexPlacement = Index;
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
    return GetPieSlotCount(*this) > 0 && FindOrdinaryItem(*this, Object1) &&
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
}

bool UInventoryComponent::HasInventorySpaceForTransaction(FName ItemId, int32 ItemCount, TArray<FGuid> SourceGuids, TArray<int32> SourceQuantities)
{
    return false;
}

