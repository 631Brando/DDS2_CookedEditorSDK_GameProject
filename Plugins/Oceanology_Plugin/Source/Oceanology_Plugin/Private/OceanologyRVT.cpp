#include "OceanologyRVT.h"

FOceanologyRVT::FOceanologyRVT() {
    this->BoxMaxEdgeFalloff = 0.00f;
    this->DepthForDFFoam = 0.00f;
    this->DepthForMask = 0.00f;
    this->DepthForStillShore = 0.00f;
    this->DepthForSurfaceScattering = 0.00f;
    this->WaterZMax = 0.00f;
    this->WaterZMin = 0.00f;
    this->T_Heightmap = NULL;
}

