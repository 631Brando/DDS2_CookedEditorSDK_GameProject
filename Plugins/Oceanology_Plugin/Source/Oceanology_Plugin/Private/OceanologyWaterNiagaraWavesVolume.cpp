#include "OceanologyWaterNiagaraWavesVolume.h"
#include "NiagaraComponent.h"

AOceanologyWaterNiagaraWavesVolume::AOceanologyWaterNiagaraWavesVolume(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bEnableAutoLODGeneration = false;
    this->NiagaraWavesComponent = CreateDefaultSubobject<UNiagaraComponent>(TEXT("NiagaraWaves"));
    this->OceanologyWater = NULL;
    this->NiagaraWaves = NULL;
    this->NiagaraWavesComponent->SetupAttachment(RootComponent);
}

void AOceanologyWaterNiagaraWavesVolume::ReloadSettings() {
}

void AOceanologyWaterNiagaraWavesVolume::DebugBounds() {
}


