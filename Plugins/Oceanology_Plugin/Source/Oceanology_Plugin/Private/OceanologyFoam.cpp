#include "OceanologyFoam.h"

FOceanologyFoam::FOceanologyFoam() {
    this->FoamDistortionIntensity = 0.00f;
    this->FoamDistortionScale = 0.00f;
    this->FoamDistortionSpeed = 0.00f;
    this->FoamNormals = 0.00f;
    this->UVBubbles = 0.00f;
    this->UVFoam = 0.00f;
    this->BubblesNormals = 0.00f;
    this->T_BubblesColor = NULL;
    this->T_BubblesNormals = NULL;
    this->T_FoamColor = NULL;
    this->T_FoamNormals = NULL;
}

