#include "OceanologyInfiniteOcean.h"
#include "Components/DecalComponent.h"
#include "Net/UnrealNetwork.h"
#include "OceanAudioComponent.h"
#include "OceanologyInfiniteComponent.h"

AOceanologyInfiniteOcean::AOceanologyInfiniteOcean(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->InfiniteComponent = CreateDefaultSubobject<UOceanologyInfiniteComponent>(TEXT("Infinite"));
    this->DLWetnessComponent = CreateDefaultSubobject<UDecalComponent>(TEXT("DLWetness"));
    this->OceanAudioUnderwaterComponent = CreateDefaultSubobject<UOceanAudioComponent>(TEXT("OceanAudioUnderwater"));
    this->Preset = NULL;
    this->PresetMode = EOceanologyWaterPresetMode::UsePresetDirectly;
    this->PresetInclusionGroups.AddDefaulted(25);
    this->EnableWetness = true;
    this->ShorelineWetnessMaterial = NULL;
    this->ShorelineWetnessMID = NULL;
    this->DLWetnessComponent->SetupAttachment(RootComponent);
    this->OceanAudioUnderwaterComponent->SetupAttachment(RootComponent);
}

void AOceanologyInfiniteOcean::LoadPreset(UOceanologyOceanPreset* InPreset) {
}

void AOceanologyInfiniteOcean::InitShorelineWetness() {
}

UMaterialInstanceDynamic* AOceanologyInfiniteOcean::GetShorelineWetnessMID() {
    return NULL;
}

void AOceanologyInfiniteOcean::ForceFollow() {
}

void AOceanologyInfiniteOcean::CreateOrUpdateShorelineWetnessMID() {
}

void AOceanologyInfiniteOcean::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(AOceanologyInfiniteOcean, Wetness);
}


