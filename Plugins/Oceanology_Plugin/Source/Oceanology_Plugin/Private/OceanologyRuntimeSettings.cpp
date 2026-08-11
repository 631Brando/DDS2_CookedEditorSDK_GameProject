#include "OceanologyRuntimeSettings.h"
#include "OceanologyGerstnerWaveSolverComponent.h"

UOceanologyRuntimeSettings::UOceanologyRuntimeSettings() {
    this->LakeWaveSolverClass = UOceanologyGerstnerWaveSolverComponent::StaticClass();
    this->OceanWaveSolverClass = UOceanologyGerstnerWaveSolverComponent::StaticClass();
}


