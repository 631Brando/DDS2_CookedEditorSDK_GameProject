#include "OceanAudioComponent.h"

UOceanAudioComponent::UOceanAudioComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bAutoActivate = false;
    this->Mode = EOceanAudioMode::None;
    this->DebugEnabled = false;
    this->OceanologyWater = NULL;
}

void UOceanAudioComponent::PlaySoundFX() {
}


