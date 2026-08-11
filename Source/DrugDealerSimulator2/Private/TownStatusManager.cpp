#include "TownStatusManager.h"

ATownStatusManager::ATownStatusManager(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->DrugDatabase = NULL;
    this->TownDatabase = NULL;
    this->CurTownReputationLevel = 0.00f;
}



void ATownStatusManager::SetDrugSaleEnabled(FName DrugID, bool IsEnabled) {
}

void ATownStatusManager::SetDrugPrice(FName DrugID, int32 DrugPrice) {
}

void ATownStatusManager::SetDrugDemand(FName DrugID, FName DistrictID, float DemandAmount, bool ForceCreate) {
}

void ATownStatusManager::RemoveDrugDemand(FName DrugID, FName DistrictID, float DemandAmount) {
}

bool ATownStatusManager::HasDrugOffer() {
    return false;
}

void ATownStatusManager::GetTownReputation(int32& ReputationLevel, float& ReputationValue) {
}

bool ATownStatusManager::GetDrugSaleEnabled(FName DrugID) {
    return false;
}

int32 ATownStatusManager::GetDrugPrice(FName DrugID) {
    return 0;
}

float ATownStatusManager::GetDrugMultiplier(FName DrugID) {
    return 0.0f;
}

void ATownStatusManager::GetDrugDemandList(FName DistrictID, TArray<FDrugDemandListResult>& OutList) {
}

float ATownStatusManager::GetDrugDemand(FName DrugID, FName DistrictID) {
    return 0.0f;
}

void ATownStatusManager::ChangeTownReputation(float ReputationChange) {
}

float ATownStatusManager::CalcMaxReputationPool() {
    return 0.0f;
}

void ATownStatusManager::AddDrugDemand(FName DrugID, FName DistrictID, float DemandAmount, bool ForceCreate) {
}


