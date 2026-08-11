#include "OceanologyUnderwaterComponent.h"
#include "Net/UnrealNetwork.h"

UOceanologyUnderwaterComponent::UOceanologyUnderwaterComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bAutoActivate = true;
    this->UnderwaterMode = EOceanologyUnderwaterMode::Underwater;
    this->UserOverrideUnderwaterMaterial = false;
    this->UnderwaterMaterial = NULL;
    this->VolumetricFogMaterial = NULL;
    this->OceanologyWater = NULL;
    this->UnderwaterMID = NULL;
    this->VolumetricFogMID = NULL;
    this->BubblesMID = NULL;
}

void UOceanologyUnderwaterComponent::InitBubbles() {
}

void UOceanologyUnderwaterComponent::Init() {
}

UMaterialInstanceDynamic* UOceanologyUnderwaterComponent::GetVolumetricFogMID() {
    return NULL;
}

UMaterialInstanceDynamic* UOceanologyUnderwaterComponent::GetUnderwaterMID() {
    return NULL;
}

UMaterialInstanceDynamic* UOceanologyUnderwaterComponent::GetBubblesMID() {
    return NULL;
}

void UOceanologyUnderwaterComponent::CreateOrUpdateVolumetricFogMID() {
}

void UOceanologyUnderwaterComponent::CreateOrUpdateUnderwaterMID() {
}

void UOceanologyUnderwaterComponent::CreateOrUpdateBubblesMID() {
}

void UOceanologyUnderwaterComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(UOceanologyUnderwaterComponent, UnderwaterMode);
    DOREPLIFETIME(UOceanologyUnderwaterComponent, Underwater);
    DOREPLIFETIME(UOceanologyUnderwaterComponent, VolumetricFog);
    DOREPLIFETIME(UOceanologyUnderwaterComponent, MaskUnderwater);
    DOREPLIFETIME(UOceanologyUnderwaterComponent, WaterProjection);
    DOREPLIFETIME(UOceanologyUnderwaterComponent, BubblesSettings);
    DOREPLIFETIME(UOceanologyUnderwaterComponent, OceanologyWater);
}


