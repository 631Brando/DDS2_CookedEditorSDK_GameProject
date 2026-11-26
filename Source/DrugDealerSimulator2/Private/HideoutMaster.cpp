#include "HideoutMaster.h"
#include "CraftRecipeeData.h"
#include "CraftStationClassData.h"
#include "HideoutData.h"
#include "HideoutEquipmentData.h"
#include "PieOrdinaryCraft.h"
#include "SubstanceData.h"

namespace
{
const FName SubstanceStorage(TEXT("HIDEOUT-SUBSTANCE-STORAGE"));

TArray<FPropertyListItem> MakePropertyList(const TMap<FName, float>& Properties)
{
    TArray<FPropertyListItem> Result;
    Result.Reserve(Properties.Num());
    for (const auto& Property : Properties)
    {
        FPropertyListItem& Item = Result.AddDefaulted_GetRef();
        Item.PropertyID = Property.Key;
        Item.PropertyValue = Property.Value;
    }
    return Result;
}

template <typename RowType>
const RowType* FindCraftRow(const UDataTable* Table, FName Id)
{
    return Table && Table->GetRowStruct() == RowType::StaticStruct()
        ? Table->FindRow<RowType>(Id, TEXT("Standalone PIE ordinary craft"), false)
        : nullptr;
}

const FCraftRecipeeData* FindOrdinaryRecipe(const AHideoutMaster& Hideout, FName RecipeId)
{
    const auto* Recipe = FindCraftRow<FCraftRecipeeData>(Hideout.CraftingRecipiesDatabase, RecipeId);
    if (!Recipe || Recipe->OutputItems.Num() != 1 || !Recipe->InputSubstances.IsEmpty() ||
        !Recipe->OutputSubstances.IsEmpty() || !Recipe->OutputChanceItems.IsEmpty() ||
        !Recipe->RequiredFeatures.IsEmpty() || !Recipe->RequiredEquipment.IsEmpty() ||
        Recipe->WasteAmount != 0.0f || !FMath::IsFinite(Recipe->BaseCraftTime) || Recipe->BaseCraftTime <= 0.0f)
    {
        return nullptr;
    }
    const auto Output = Recipe->OutputItems.CreateConstIterator();
    if (Output.Key().IsNone() || Output.Value() <= 0)
    {
        return nullptr;
    }
    for (const auto& Input : Recipe->InputItems)
    {
        if (Input.Key.IsNone() || Input.Value <= 0)
        {
            return nullptr;
        }
    }
    return Recipe;
}

float GetLotDuration(const AHideoutMaster& Hideout, const FCraftRecipeeData& Recipe, FGuid Station, float Speed)
{
    const auto* Deployed = Hideout.DeployedEquipment.Find(Station);
    const auto* Equipment = Deployed
        ? FindCraftRow<FHideoutEquipmentData>(Hideout.EquipmentDatabase, Deployed->EquipmentID)
        : nullptr;
    if (Equipment)
    {
        if (const float* Multiplier = Hideout.CraftingStationSpeedMap.Find(Equipment->EquipmentCraftingStationID))
        {
            Speed *= *Multiplier;
        }
    }
    const float Duration = Speed > 0.0f ? Recipe.BaseCraftTime / Speed : Recipe.BaseCraftTime;
    return FMath::IsFinite(Duration) && Duration > 0.0f ? Duration : Recipe.BaseCraftTime;
}
}

AHideoutMaster::AHideoutMaster(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->HideoutDatabase = NULL;
    this->EquipmentDatabase = NULL;
    this->CraftingStationDatabase = NULL;
    this->SubstanceDatabase = NULL;
    this->CraftingRecipiesDatabase = NULL;
    this->CheatCraftSpeedMultiplier = 1.00f;
    this->CraftingTickEnabled = false;
    this->CraftFillDuplicated = true;
    if (PieOrdinaryCraft::IsRequested())
    {
        PrimaryActorTick.bCanEverTick = true;
    }
}

void AHideoutMaster::Tick(float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);
    if (CraftingTickEnabled)
    {
        CraftingTick(DeltaSeconds, false);
    }
}

void AHideoutMaster::UpdateEquipmentProperties() {
    if (!PieOrdinaryCraft::IsEnabled(this))
    {
        return;
    }
    CurEquipmentProperties.Reset();
    for (const auto& Entry : DeployedEquipment)
    {
        const auto* Row = FindCraftRow<FHideoutEquipmentData>(EquipmentDatabase, Entry.Value.EquipmentID);
        if (Row)
        {
            for (const auto& Property : Row->EquipmentProperties)
            {
                CurEquipmentProperties.FindOrAdd(Property.Key) += Property.Value;
            }
        }
    }
    HideoutPropertiesChanged();
}

bool AHideoutMaster::UpdateDeployedEquipmentTransform(FHideoutDeployedEqData EqData, FGuid EqGuid) {
    return false;
}

void AHideoutMaster::UpdateCraftingFlow(float TimeElapsed) {
}



void AHideoutMaster::SetCraftingTickEnabled(bool TickEnabled, float TimeElapsed) {
    if (PieOrdinaryCraft::IsEnabled(this))
    {
        CraftingTickEnabled = TickEnabled;
        SetActorTickEnabled(TickEnabled);
    }
}

void AHideoutMaster::SetCheatCraftMultiplier(float NewMultiplier) {
    if (PieOrdinaryCraft::IsEnabled(this) && FMath::IsFinite(NewMultiplier) && NewMultiplier > 0.0f)
    {
        CheatCraftSpeedMultiplier = NewMultiplier;
    }
}


void AHideoutMaster::RemoveSubstance(FName SubstanceID, float RemoveAmount, bool RemoveAll) {
    if (!PieOrdinaryCraft::IsEnabled(this) || (!RemoveAll && (!FMath::IsFinite(RemoveAmount) || RemoveAmount <= 0.0f)))
    {
        return;
    }
    FStoredSubstanceData* Stock = StoredSubstances.Find(SubstanceID);
    if (!Stock)
    {
        return;
    }
    if (RemoveAll || RemoveAmount >= Stock->StoredAmount)
    {
        StoredSubstances.Remove(SubstanceID);
    }
    else
    {
        Stock->StoredAmount -= RemoveAmount;
    }
    SubstanceStorageChanged();
}

void AHideoutMaster::RemoveMix(FGuid MixGuid, float RemoveAmount, bool RemoveAll) {
}

void AHideoutMaster::RemoveDeployedEquipment(FGuid EqGuid) {
    if (!PieOrdinaryCraft::IsEnabled(this))
    {
        return;
    }
    const FHideoutDeployedEqData* Equipment = DeployedEquipment.Find(EqGuid);
    if (!Equipment)
    {
        return;
    }
    for (const auto& Entry : CraftingQuery)
    {
        if (Entry.Value.CraftingStationGuid == EqGuid)
        {
            return;
        }
    }
    const FName Id = Equipment->EquipmentID;
    DeployedEquipment.Remove(EqGuid);
    if (int32* Count = DeployedEqQuantities.Find(Id))
    {
        if (*Count <= 1)
        {
            DeployedEqQuantities.Remove(Id);
        }
        else
        {
            --*Count;
        }
    }
    UpdateEquipmentProperties();
}

void AHideoutMaster::PurgeAllSubstanceStorage() {
}


void AHideoutMaster::OutputCraftingQueryItem(FGuid ItemGuid, bool Simulation, float SpeedOverride, float CartelSpeedMultiplier) {
    if (Simulation || !PieOrdinaryCraft::IsEnabled(this) || PieOutputAttempt != ItemGuid || !ItemGuid.IsValid())
    {
        return;
    }
    FCraftingQueryItem* Item = CraftingQuery.Find(ItemGuid);
    const auto* Recipe = Item ? FindOrdinaryRecipe(*this, Item->CraftID) : nullptr;
    if (!Recipe || Item->CraftingQuantity <= 0)
    {
        return;
    }
    PieOutputAttempt.Invalidate();
    if (--Item->CraftingQuantity == 0)
    {
        CraftingQuery.Remove(ItemGuid);
        CraftingQueryPriority.Remove(ItemGuid);
    }
    else
    {
        Item->CraftingTimer = GetLotDuration(*this, *Recipe, Item->CraftingStationGuid, SpeedOverride * CartelSpeedMultiplier);
    }
    CraftingQueryChanged();
}




void AHideoutMaster::LoopCraftingQuery(FGuid ItemGuid) {
    if (PieOrdinaryCraft::IsEnabled(this) && ItemGuid.IsValid() && PieOutputAttempt == ItemGuid)
    {
        if (FCraftingQueryItem* Item = CraftingQuery.Find(ItemGuid))
        {
            Item->CraftingTimer = 2.0f;
            PieOutputAttempt.Invalidate();
            CraftingQueryChanged();
        }
    }
}


float AHideoutMaster::GetTotalWasteAmount() {
    return 0.0f;
}

float AHideoutMaster::GetTotalStorageMass() {
    float Used = 0.0f;
    if (PieOrdinaryCraft::IsEnabled(this))
    {
        for (const auto& Entry : StoredSubstances)
        {
            Used += Entry.Value.StoredAmount;
        }
        for (const auto& Entry : StoredMixes)
        {
            Used += Entry.Value.StoredAmount;
        }
    }
    return Used;
}

float AHideoutMaster::GetTotalStorageFreeSpace() {
    if (!PieOrdinaryCraft::IsEnabled(this))
    {
        return 0.0f;
    }
    const float Free = GetMaxGeneralStorage() - GetTotalStorageMass();
    return FMath::IsFinite(Free) ? Free : -1.0f;
}

void AHideoutMaster::GetSubstanceStorageSize(FName SubstanceID, bool DedicatedOnly, float& TotalStored, float& MaxStorage) {
    if (!PieOrdinaryCraft::IsEnabled(this))
    {
        return;
    }
    const FStoredSubstanceData* Stock = StoredSubstances.Find(SubstanceID);
    TotalStored = Stock ? Stock->StoredAmount : 0.0f;
    MaxStorage = Stock ? Stock->StoredMaxAdd : 0.0f;
    if (!DedicatedOnly || !Stock)
    {
        MaxStorage += GetMaxGeneralStorage();
    }
}

void AHideoutMaster::GetSubstanceList(TArray<FStoredSubstanceData>& SubstanceList) {
    if (!PieOrdinaryCraft::IsEnabled(this))
    {
        return;
    }
    SubstanceList.Reset(StoredMixes.Num() + StoredSubstances.Num());
    for (const auto& Entry : StoredMixes)
    {
        SubstanceList.Add(Entry.Value);
    }
    for (const auto& Entry : StoredSubstances)
    {
        FStoredSubstanceData& Record = SubstanceList.Add_GetRef(Entry.Value);
        if (Record.SubstanceID.IsNone())
        {
            Record.SubstanceID = Entry.Key;
        }
    }
}

void AHideoutMaster::GetMixStorageSize(FGuid MixGuid, bool DedicatedOnly, float& TotalStored, float& MaxStorage) {
}

TArray<FMixingQueryItem> AHideoutMaster::GetMixingQuery(FGuid EquipmentGuid, bool SkipFiltering) {
    return TArray<FMixingQueryItem>();
}

float AHideoutMaster::GetMaxGeneralStorage() {
    return GetHideoutPropertyValue(SubstanceStorage);
}

TArray<FPropertyListItem> AHideoutMaster::GetHideoutTotalProperties() {
    const auto* Row = PieOrdinaryCraft::IsEnabled(this)
        ? FindCraftRow<FHideoutData>(HideoutDatabase, HideoutID) : nullptr;
    if (!Row)
    {
        return {};
    }
    TMap<FName, float> Total = Row->HideoutProperties;
    for (const auto& Entry : CurEquipmentProperties)
    {
        Total.FindOrAdd(Entry.Key) += Entry.Value;
    }
    return MakePropertyList(Total);
}

float AHideoutMaster::GetHideoutPropertyValue(FName PropertyID) {
    if (!PieOrdinaryCraft::IsEnabled(this))
    {
        return 0.0f;
    }
    const auto* Row = FindCraftRow<FHideoutData>(HideoutDatabase, HideoutID);
    const float Base = Row ? Row->HideoutProperties.FindRef(PropertyID) : 0.0f;
    return Base + CurEquipmentProperties.FindRef(PropertyID);
}

TArray<FPropertyListItem> AHideoutMaster::GetHideoutDefaultProperties() {
    const auto* Row = PieOrdinaryCraft::IsEnabled(this)
        ? FindCraftRow<FHideoutData>(HideoutDatabase, HideoutID) : nullptr;
    return Row ? MakePropertyList(Row->HideoutProperties) : TArray<FPropertyListItem>();
}

TArray<FStoredSubstanceData> AHideoutMaster::GetDrugStock() {
    TArray<FStoredSubstanceData> Result;
    if (PieOrdinaryCraft::IsEnabled(this))
    {
        for (const auto& Entry : StoredSubstances)
        {
            const auto* Row = FindCraftRow<FSubstanceData>(SubstanceDatabase, Entry.Value.SubstanceID);
            if (Row && !Row->SubstanceDrugID.IsNone())
            {
                Result.Add(Entry.Value);
            }
        }
        for (const auto& Entry : StoredMixes)
        {
            Result.Add(Entry.Value);
        }
    }
    return Result;
}

TArray<FPropertyListItem> AHideoutMaster::GetDeployedEquipmentProperties() {
    return PieOrdinaryCraft::IsEnabled(this) ? MakePropertyList(CurEquipmentProperties) : TArray<FPropertyListItem>();
}

int32 AHideoutMaster::GetDeployedEqCount(const FName& EquipmentID) {
    return PieOrdinaryCraft::IsEnabled(this) ? DeployedEqQuantities.FindRef(EquipmentID) : 0;
}

void AHideoutMaster::GetCraftingQuery(FGuid EquipmentGuid, bool SkipFiltering, TArray<FCraftingQueryItem>& OutQuery) {
    if (!PieOrdinaryCraft::IsEnabled(this))
    {
        return;
    }
    OutQuery.Reset();
    for (const FGuid& Id : CraftingQueryPriority)
    {
        if (const FCraftingQueryItem* Item = CraftingQuery.Find(Id))
        {
            if (SkipFiltering || Item->CraftingStationGuid == EquipmentGuid)
            {
                OutQuery.Add(*Item);
            }
        }
    }
}

FGuid AHideoutMaster::GetCraftDuplicate(FName RecipieID, FGuid StationGuid) {
    if (PieOrdinaryCraft::IsEnabled(this))
    {
        for (const FGuid& Id : CraftingQueryPriority)
        {
            if (const FCraftingQueryItem* Item = CraftingQuery.Find(Id))
            {
                if (Item->CraftID == RecipieID && Item->CraftingStationGuid == StationGuid)
                {
                    return Id;
                }
            }
        }
    }
    return FGuid{};
}

float AHideoutMaster::GetCategoryMaxStorage(FGuid CategoryGuid) {
    return 0.0f;
}

void AHideoutMaster::GatherCraftingSationMaps() {
}

void AHideoutMaster::CraftingTick(float deltaTime, bool Simulation) {
    if (Simulation || !PieOrdinaryCraft::IsEnabled(this) || bPieCraftTickInProgress ||
        !FMath::IsFinite(deltaTime) || deltaTime <= 0.0f)
    {
        return;
    }
    const float Step = deltaTime * CheatCraftSpeedMultiplier;
    if (!FMath::IsFinite(Step) || Step <= 0.0f)
    {
        return;
    }
    const TArray<FGuid> Priority = CraftingQueryPriority;
    TSet<FGuid> VisitedStations;
    TGuardValue<bool> Guard(bPieCraftTickInProgress, true);
    // Output and queue notifications can synchronously modify the map.
    for (const FGuid& Id : Priority)
    {
        FCraftingQueryItem* Item = CraftingQuery.Find(Id);
        if (!Item || !Id.IsValid() || Item->CraftGuid != Id || Item->CraftingQuantity <= 0 ||
            !Item->CraftingStationGuid.IsValid() || VisitedStations.Contains(Item->CraftingStationGuid))
        {
            continue;
        }
        const FGuid Station = Item->CraftingStationGuid;
        VisitedStations.Add(Station);
        const FName Recipe = Item->CraftID;
        if (!DeployedEquipment.Contains(Station) || !FindOrdinaryRecipe(*this, Recipe))
        {
            continue;
        }
        Item->CraftingTimer = FMath::Max(0.0f, Item->CraftingTimer - Step);
        if (Item->CraftingTimer == 0.0f)
        {
            Item->CraftingTimer = 1.0f;
            TGuardValue<FGuid> Attempt(PieOutputAttempt, Id);
            TryOutputCraft(Recipe, Id, Station, false);
        }
    }
}


int32 AHideoutMaster::CheckMaxCrafterQuerySpace(FGuid CrafterGuid, bool HasLabTech) {
    if (!PieOrdinaryCraft::IsEnabled(this))
    {
        return 0;
    }
    const auto* Equipment = DeployedEquipment.Find(CrafterGuid);
    const auto* Station = Equipment
        ? FindCraftRow<FCraftStationClassData>(CraftingStationDatabase, Equipment->EquipmentID)
        : nullptr;
    if (!Station)
    {
        return 0;
    }
    int64 Free = static_cast<int64>(Station->MaxSimProcesses) * (HasLabTech ? 2 : 1);
    for (const auto& Entry : CraftingQuery)
    {
        if (Entry.Value.CraftingStationGuid == CrafterGuid)
        {
            Free -= FMath::Max(0, Entry.Value.CraftingQuantity);
        }
    }
    return static_cast<int32>(FMath::Clamp<int64>(Free, 0, 9999));
}

bool AHideoutMaster::CheckCanFitSubstance(FName SubstanceID, float SubstanceAmount) {
    return PieOrdinaryCraft::IsEnabled(this) && FMath::IsFinite(SubstanceAmount) &&
        SubstanceAmount >= 0.0f && FindCraftRow<FSubstanceData>(SubstanceDatabase, SubstanceID) &&
        SubstanceAmount <= GetTotalStorageFreeSpace();
}

bool AHideoutMaster::CheckCanFitMix(FName MixGuid, float MixAmount) {
    return false;
}

bool AHideoutMaster::CanDeployEquipmentCount(const FName& EquipmentID, const int32& Quantity) {
    const auto* Row = PieOrdinaryCraft::IsEnabled(this) && Quantity > 0
        ? FindCraftRow<FHideoutEquipmentData>(EquipmentDatabase, EquipmentID) : nullptr;
    if (!Row)
    {
        return false;
    }
    const int64 After = static_cast<int64>(GetDeployedEqCount(EquipmentID)) + Quantity;
    return After <= MAX_int32 && (Row->QuantityLimit <= 0 || After <= Row->QuantityLimit);
}

void AHideoutMaster::CancelCraftingQuery(FGuid QueryGuid) {
}

void AHideoutMaster::AddSubstance(FName SubstanceID, float SubstanceAmount, bool SkipUpdate, float& Leftover) {
    if (!PieOrdinaryCraft::IsEnabled(this))
    {
        return;
    }
    Leftover = FMath::IsFinite(SubstanceAmount) && SubstanceAmount > 0.0f ? SubstanceAmount : 0.0f;
    if (Leftover == 0.0f || !CheckCanFitSubstance(SubstanceID, SubstanceAmount))
    {
        return;
    }
    FStoredSubstanceData& Stock = StoredSubstances.FindOrAdd(SubstanceID);
    Stock.SubstanceID = SubstanceID;
    Stock.StoredAmount += SubstanceAmount;
    Leftover = 0.0f;
    if (!SkipUpdate)
    {
        SubstanceStorageChanged();
    }
}

void AHideoutMaster::AddMixingQueue(FMixingQueryItem MixQueryConfig) {
}

void AHideoutMaster::AddMix(FGuid MixGuid, float MixAmount, bool SkipUpdate) {
}

FGuid AHideoutMaster::AddDeployedEquipment(FHideoutDeployedEqData EqData, FGuid GuidOverride, int32 Quantity) {
    // Each record represents one deployed actor and its inventory identity.
    if (Quantity != 1 || !CanDeployEquipmentCount(EqData.EquipmentID, Quantity))
    {
        return {};
    }
    const FGuid Id = GuidOverride.IsValid() ? GuidOverride : FGuid::NewGuid();
    if (DeployedEquipment.Contains(Id))
    {
        return {};
    }
    ++DeployedEqQuantities.FindOrAdd(EqData.EquipmentID);
    DeployedEquipment.Add(Id, MoveTemp(EqData));
    UpdateEquipmentProperties();
    return Id;
}

void AHideoutMaster::AddCraftingQueue(FName RecipieID, FGuid CraftingStationGuid, int32 Quantity, float EqSpeedMultiplier, bool InsertFirst) {
    if (!PieOrdinaryCraft::IsEnabled(this) || Quantity <= 0 || !CraftingStationGuid.IsValid() ||
        !DeployedEquipment.Contains(CraftingStationGuid))
    {
        return;
    }
    const auto* Recipe = FindOrdinaryRecipe(*this, RecipieID);
    if (!Recipe)
    {
        return;
    }
    const FGuid Duplicate = CraftFillDuplicated && !InsertFirst
        ? GetCraftDuplicate(RecipieID, CraftingStationGuid) : FGuid();
    if (FCraftingQueryItem* Existing = CraftingQuery.Find(Duplicate))
    {
        if (Existing->CraftingQuantity <= 0 || Existing->CraftingQuantity > MAX_int32 - Quantity)
        {
            return;
        }
        Existing->CraftingQuantity += Quantity;
    }
    else
    {
        FCraftingQueryItem Item;
        Item.CraftID = RecipieID;
        Item.CraftingStationGuid = CraftingStationGuid;
        Item.CraftGuid = FGuid::NewGuid();
        Item.CraftingTimer = GetLotDuration(*this, *Recipe, CraftingStationGuid, EqSpeedMultiplier);
        Item.CraftingQuantity = Quantity;
        CraftingQuery.Add(Item.CraftGuid, Item);
        if (InsertFirst)
        {
            CraftingQueryPriority.Insert(Item.CraftGuid, 0);
        }
        else
        {
            CraftingQueryPriority.Add(Item.CraftGuid);
        }
    }
    CraftingQueryChanged();
}


