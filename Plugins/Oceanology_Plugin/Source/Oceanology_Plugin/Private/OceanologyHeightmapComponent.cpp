#include "OceanologyHeightmapComponent.h"

UOceanologyHeightmapComponent::UOceanologyHeightmapComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bUseRenderTarget = false;
    this->HeightmapTexture = NULL;
    this->HeightmapRenderTarget = NULL;
    this->bUseCustomRVTBaker = true;
    this->BuildLevels = 3;
    this->BakedHeightmap = NULL;
    this->JumpFloodMaterialInstance = NULL;
    this->CopyUVsMaterialInstance = NULL;
    this->ComputeSDFMaterialInstance = NULL;
    this->BlurMaterialInstance = NULL;
    this->ComposeMaterialInstance = NULL;
}

void UOceanologyHeightmapComponent::SetupWaterMinMax() {
}

void UOceanologyHeightmapComponent::SetupWater() {
}

void UOceanologyHeightmapComponent::SetupLandscapeOrGroundMesh() {
}

void UOceanologyHeightmapComponent::SaveHeightmapRenderTarget() {
}

void UOceanologyHeightmapComponent::SaveHeightmap(UTexture2D* NewHeightmap) {
}

void UOceanologyHeightmapComponent::Init() {
}


