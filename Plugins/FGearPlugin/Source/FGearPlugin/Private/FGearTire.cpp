#include "FGearTire.h"

UFGearTire::UFGearTire() {
    this->mCombineMode = FGearForceCombineMode::GRIP;
    this->mReferenceLoad = 3000.00f;
    this->mReferenceTirePressure = 2.00f;
    this->mForceSymmetry = false;
}


