#include "PlayerFactorsComponent.h"

UPlayerFactorsComponent::UPlayerFactorsComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->FactorStatusDatabase = NULL;
}

void UPlayerFactorsComponent::RemoveFactorDose(FName FactorStatusID, float Dose) {
}

TArray<FFactorStatusListItem> UPlayerFactorsComponent::GetFactorStatusList(bool FilterHidden) {
    return TArray<FFactorStatusListItem>();
}

float UPlayerFactorsComponent::GetCurrentFactorPower(FName FactorStatusID) {
    return 0.0f;
}

float UPlayerFactorsComponent::GetCurrentFactorDose(FName FactorStatusID) {
    return 0.0f;
}



void UPlayerFactorsComponent::AddFactorDose(FName FactorStatusID, float Dose) {
}


