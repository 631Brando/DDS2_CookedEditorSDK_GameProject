#include "OceanologyWaterMeshComponent.h"

UOceanologyWaterMeshComponent::UOceanologyWaterMeshComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bAutoActivate = true;
    this->bHasPerInstanceHitProxies = true;
    this->WaterMaterialInstance = NULL;
    this->WaterFarDistanceMaterialInstance = NULL;
}

bool UOceanologyWaterMeshComponent::IsEnabled() const {
    return false;
}


