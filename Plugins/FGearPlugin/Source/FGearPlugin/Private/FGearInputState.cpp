#include "FGearInputState.h"

FFGearInputState::FFGearInputState() {
    this->mTick = 0;
    this->mThrottle = 0.00f;
    this->mSteer = 0.00f;
    this->mBrake = 0.00f;
    this->mClutch = 0.00f;
    this->mThrottleState = 0;
    this->mGear = 0;
    this->mHandbrake = false;
}

