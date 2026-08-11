#include "HideoutMaster.h"

AHideoutMaster::AHideoutMaster(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->HideoutDatabase = NULL;
    this->EquipmentDatabase = NULL;
    this->CraftingStationDatabase = NULL;
    this->SubstanceDatabase = NULL;
    this->CraftingRecipiesDatabase = NULL;
    this->CheatCraftSpeedMultiplier = 1.00f;
    this->CraftingTickEnabled = false;
    this->CraftFillDuplicated = true;
}


void AHideoutMaster::UpdateEquipmentProperties() {
}

bool AHideoutMaster::UpdateDeployedEquipmentTransform(FHideoutDeployedEqData EqData, FGuid EqGuid) {
    return false;
}

void AHideoutMaster::UpdateCraftingFlow(float TimeElapsed) {
}



void AHideoutMaster::SetCraftingTickEnabled(bool TickEnabled, float TimeElapsed) {
}

void AHideoutMaster::SetCheatCraftMultiplier(float NewMultiplier) {
}


void AHideoutMaster::RemoveSubstance(FName SubstanceID, float RemoveAmount, bool RemoveAll) {
}

void AHideoutMaster::RemoveMix(FGuid MixGuid, float RemoveAmount, bool RemoveAll) {
}

void AHideoutMaster::RemoveDeployedEquipment(FGuid EqGuid) {
}

void AHideoutMaster::PurgeAllSubstanceStorage() {
}


void AHideoutMaster::OutputCraftingQueryItem(FGuid ItemGuid, bool Simulation, float SpeedOverride, float CartelSpeedMultiplier) {
}




void AHideoutMaster::LoopCraftingQuery(FGuid ItemGuid) {
}


float AHideoutMaster::GetTotalWasteAmount() {
    return 0.0f;
}

float AHideoutMaster::GetTotalStorageMass() {
    return 0.0f;
}

float AHideoutMaster::GetTotalStorageFreeSpace() {
    return 0.0f;
}

void AHideoutMaster::GetSubstanceStorageSize(FName SubstanceID, bool DedicatedOnly, float& TotalStored, float& MaxStorage) {
}

void AHideoutMaster::GetSubstanceList(TArray<FStoredSubstanceData>& SubstanceList) {
}

void AHideoutMaster::GetMixStorageSize(FGuid MixGuid, bool DedicatedOnly, float& TotalStored, float& MaxStorage) {
}

TArray<FMixingQueryItem> AHideoutMaster::GetMixingQuery(FGuid EquipmentGuid, bool SkipFiltering) {
    return TArray<FMixingQueryItem>();
}

float AHideoutMaster::GetMaxGeneralStorage() {
    return 0.0f;
}

TArray<FPropertyListItem> AHideoutMaster::GetHideoutTotalProperties() {
    return TArray<FPropertyListItem>();
}

float AHideoutMaster::GetHideoutPropertyValue(FName PropertyID) {
    return 0.0f;
}

TArray<FPropertyListItem> AHideoutMaster::GetHideoutDefaultProperties() {
    return TArray<FPropertyListItem>();
}

TArray<FStoredSubstanceData> AHideoutMaster::GetDrugStock() {
    return TArray<FStoredSubstanceData>();
}

TArray<FPropertyListItem> AHideoutMaster::GetDeployedEquipmentProperties() {
    return TArray<FPropertyListItem>();
}

int32 AHideoutMaster::GetDeployedEqCount(const FName& EquipmentID) {
    return 0;
}

void AHideoutMaster::GetCraftingQuery(FGuid EquipmentGuid, bool SkipFiltering, TArray<FCraftingQueryItem>& OutQuery) {
}

FGuid AHideoutMaster::GetCraftDuplicate(FName RecipieID, FGuid StationGuid) {
    return FGuid{};
}

float AHideoutMaster::GetCategoryMaxStorage(FGuid CategoryGuid) {
    return 0.0f;
}

void AHideoutMaster::GatherCraftingSationMaps() {
}

void AHideoutMaster::CraftingTick(float deltaTime, bool Simulation) {
}


int32 AHideoutMaster::CheckMaxCrafterQuerySpace(FGuid CrafterGuid, bool HasLabTech) {
    return 0;
}

bool AHideoutMaster::CheckCanFitSubstance(FName SubstanceID, float SubstanceAmount) {
    return false;
}

bool AHideoutMaster::CheckCanFitMix(FName MixGuid, float MixAmount) {
    return false;
}

bool AHideoutMaster::CanDeployEquipmentCount(const FName& EquipmentID, const int32& Quantity) {
    return false;
}

void AHideoutMaster::CancelCraftingQuery(FGuid QueryGuid) {
}

void AHideoutMaster::AddSubstance(FName SubstanceID, float SubstanceAmount, bool SkipUpdate, float& Leftover) {
}

void AHideoutMaster::AddMixingQueue(FMixingQueryItem MixQueryConfig) {
}

void AHideoutMaster::AddMix(FGuid MixGuid, float MixAmount, bool SkipUpdate) {
}

FGuid AHideoutMaster::AddDeployedEquipment(FHideoutDeployedEqData EqData, FGuid GuidOverride, int32 Quantity) {
    return FGuid{};
}

void AHideoutMaster::AddCraftingQueue(FName RecipieID, FGuid CraftingStationGuid, int32 Quantity, float EqSpeedMultiplier, bool InsertFirst) {
}


