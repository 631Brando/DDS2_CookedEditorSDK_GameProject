#include "OceanologyFlipbook.h"

FOceanologyFlipbook::FOceanologyFlipbook() {
    this->DistantWaterScale = 0.00f;
    this->FarNormalFresnelPower = 0.00f;
    this->FrameRateFar = 0.00f;
    this->FrameRateNear = 0.00f;
    this->NearNormalStrength = 0.00f;
    this->NearWaterScale = 0.00f;
    this->NormalLongDistanceStrength = 0.00f;
    this->NormalMidDistanceForce = 0.00f;
    this->T_FarNormalWater = NULL;
    this->T_WaterNormals = NULL;
}

