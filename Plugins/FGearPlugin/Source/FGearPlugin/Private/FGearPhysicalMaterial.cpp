#include "FGearPhysicalMaterial.h"

UFGearPhysicalMaterial::UFGearPhysicalMaterial() {
    this->mReceiveSkidmark = true;
    this->mFriction = 1.00f;
    this->mRoughness = 0.00f;
    this->mSmokeParticle = NULL;
    this->mSkidClip = NULL;
}


