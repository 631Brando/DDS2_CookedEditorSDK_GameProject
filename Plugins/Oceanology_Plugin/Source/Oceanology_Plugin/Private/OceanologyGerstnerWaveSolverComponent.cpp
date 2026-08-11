#include "OceanologyGerstnerWaveSolverComponent.h"
#include "Net/UnrealNetwork.h"

UOceanologyGerstnerWaveSolverComponent::UOceanologyGerstnerWaveSolverComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->Summarize = EOceanologyGerstnerWaveSummarize::Waves_8;
}

void UOceanologyGerstnerWaveSolverComponent::UpdateOceanWavesByPresetResult_Implementation(const FOceanologyWaterPresetResult& WaterPresetResult, const FOceanologyOceanPresetResult& OceanPresetResult) {
}

void UOceanologyGerstnerWaveSolverComponent::UpdateLakeWavesByPresetResult_Implementation(const FOceanologyWaterPresetResult& WaterPresetResult, const FOceanologyLakePresetResult& LakePresetResult) {
}

double UOceanologyGerstnerWaveSolverComponent::MultiplyWave(const double Value) {
    return 0.0;
}

FVector UOceanologyGerstnerWaveSolverComponent::GerstnerWavesQuadruple(const FVector& Position, const double Amplitude, const double Steepness, const double Speed, const double WaveLength, const double Direction, const double NumWaves, const double DirectionOffset) {
    return FVector{};
}

FVector UOceanologyGerstnerWaveSolverComponent::GerstnerWave(const FVector& Position, const double Direction, const double Speed, const double WaveLength, const double Amplitude, const double Steepness, const double NumWaves) {
    return FVector{};
}

double UOceanologyGerstnerWaveSolverComponent::DivideWave(const double Value) {
    return 0.0;
}

FVector UOceanologyGerstnerWaveSolverComponent::DirectionWave(const double Direction) {
    return FVector{};
}

void UOceanologyGerstnerWaveSolverComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(UOceanologyGerstnerWaveSolverComponent, GlobalDisplacement);
    DOREPLIFETIME(UOceanologyGerstnerWaveSolverComponent, BaseOffset);
    DOREPLIFETIME(UOceanologyGerstnerWaveSolverComponent, Wave_1);
    DOREPLIFETIME(UOceanologyGerstnerWaveSolverComponent, Wave_2);
    DOREPLIFETIME(UOceanologyGerstnerWaveSolverComponent, Wave_3);
    DOREPLIFETIME(UOceanologyGerstnerWaveSolverComponent, Wave_4);
    DOREPLIFETIME(UOceanologyGerstnerWaveSolverComponent, Summarize);
}


