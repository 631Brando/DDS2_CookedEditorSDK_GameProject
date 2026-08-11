#include "OceanologyWaveSolverComponent.h"
#include "Net/UnrealNetwork.h"

UOceanologyWaveSolverComponent::UOceanologyWaveSolverComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bAutoActivate = true;
    this->WaveTimeMode = EOceanologyWaveTimeMode::ServerTimeForReplication;
    this->WaveSolverUpdateInterval = 0.00f;
    this->Owner = NULL;
    this->MPC_Waves = NULL;
    this->GameTimeInSeconds = 0.00f;
    this->SimulateWaves = true;
    this->FirstWaterInstance = NULL;
}

void UOceanologyWaveSolverComponent::UpdateWavesByPresetResult_Implementation(AOceanologyWaterParent* Water, const FOceanologyWaterPresetResult& WaterPresetResult) {
}

void UOceanologyWaveSolverComponent::UpdateWaves_Implementation() {
}

void UOceanologyWaveSolverComponent::StopWaveSimulation() {
}

void UOceanologyWaveSolverComponent::StartWaveSimulation() {
}

bool UOceanologyWaveSolverComponent::IsUsingMPC_Waves() const {
    return false;
}

void UOceanologyWaveSolverComponent::InitWaves_Implementation(AOceanologyWaterParent* InOwner, const bool InUsingMPC_Waves) {
}

FVector UOceanologyWaveSolverComponent::GetWaveHeightAtLocation_Implementation(const FVector& Location) {
    return FVector{};
}

double UOceanologyWaveSolverComponent::GetMinWaveHeight_Implementation() {
    return 0.0;
}

double UOceanologyWaveSolverComponent::GetMaxWaveHeight_Implementation() {
    return 0.0;
}

double UOceanologyWaveSolverComponent::GetGlobalWaveDirection_Implementation() {
    return 0.0;
}

void UOceanologyWaveSolverComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(UOceanologyWaveSolverComponent, Owner);
}


