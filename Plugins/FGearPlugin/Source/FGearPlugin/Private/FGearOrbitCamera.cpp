#include "FGearOrbitCamera.h"

UFGearOrbitCamera::UFGearOrbitCamera(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->mDriftMode = false;
    this->mFreeze = false;
    this->mSpring = 1.00f;
    this->mDistance = 600.00f;
    this->mTargetZOffset = 0.00f;
    this->mTiltAngle = 15.00f;
}

void UFGearOrbitCamera::setTiltAngle(float T) {
}

void UFGearOrbitCamera::setTargetZOffset(float Z) {
}

void UFGearOrbitCamera::setSpring(float S) {
}

void UFGearOrbitCamera::setRotationOffset(float Angle) {
}

void UFGearOrbitCamera::setOrbitMode(bool orbit) {
}

void UFGearOrbitCamera::setFreeze(bool F) {
}

void UFGearOrbitCamera::setDriftMode(bool dm) {
}

void UFGearOrbitCamera::setDistance(float D) {
}

void UFGearOrbitCamera::injectMouseDZ(float mz) {
}

void UFGearOrbitCamera::injectMouseDY(float my) {
}

void UFGearOrbitCamera::injectMouseDX(float mx) {
}


