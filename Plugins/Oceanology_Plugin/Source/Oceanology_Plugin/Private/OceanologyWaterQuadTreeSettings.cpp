#include "OceanologyWaterQuadTreeSettings.h"

FOceanologyWaterQuadTreeSettings::FOceanologyWaterQuadTreeSettings() {
    this->TileSize = 0.00f;
    this->TessellationFactor = 0;
    this->LODScale = 0.00f;
    this->ForceUpdateCount = 0;
    this->CheckForUpdateInterval = 0.00f;
    this->ForceCollapseDensityLevel = 0;
    this->MaxWaveHeightMultiplier = 0.00f;
    this->bUseFarMesh = false;
    this->FarDistanceMeshExtent = 0.00f;
    this->FarDistanceCenterMeshExtent = 0.00f;
    this->FarDistanceMeshHeightOffset = 0.00f;
}

