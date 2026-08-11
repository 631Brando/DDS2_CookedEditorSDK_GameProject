#include "FGearAutoDrive.h"

AFGearAutoDrive::AFGearAutoDrive(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->mActive = false;
    this->mSpline = NULL;
    this->mStuckResetTime = 5.00f;
    this->mResetZOffset = 0.50f;
    this->mSpeedByAngleCurve = NULL;
    this->mSpeedCoeffCurve = NULL;
    this->mSteeringDistance = 10.00f;
    this->mBrakingDistance = 12.00f;
    this->mSteeringLimit = 60.00f;
    this->mForwardCheckDistance = 2.50f;
    this->mSideCheckDistance = 2.50f;
    this->mCrossCheckDistance = 3.50f;
    this->mAvoidanceDistance = 5.00f;
    this->mDebug = false;
    this->mDebugThickness = 3.00f;
}

void AFGearAutoDrive::setSpline(AFGearSpline* S) {
}

void AFGearAutoDrive::SetActive(bool B) {
}

void AFGearAutoDrive::myTick(float dt) {
}

bool AFGearAutoDrive::IsActive() const {
    return false;
}

float AFGearAutoDrive::getCurrentSplineParam() const {
    return 0.0f;
}


