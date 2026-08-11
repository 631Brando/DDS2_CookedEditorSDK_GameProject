#include "FGearArcadeAssists.h"

UFGearArcadeAssists::UFGearArcadeAssists(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->mRecoverAssists = false;
    this->mUnderSteerRecoverPower = 0.00f;
    this->mOverSteerRecoverPower = 0.00f;
    this->mMinRecoverAssistSpeed = 5.00f;
    this->mFullRecoverAssistSpeed = 50.00f;
    this->mAntirollBars = false;
    this->mFrontAntiRollPower = 0.00f;
    this->mRearAntiRollPower = 0.00f;
    this->mTractionAssist = false;
    this->mTractionAssistRatio = 0.00f;
    this->mTractionAssistMaxSpeed = 15.00f;
    this->mDriftAssist = false;
    this->mDriftAssistFrontRatio = 0.00f;
    this->mDriftAssistRearRatio = 0.00f;
    this->mTorqueSplitter = false;
    this->mTorqueSplitterRatio = 0.00f;
    this->mTorqueSplitterResponseTime = 100.00f;
    this->mBikeHelper = false;
    this->mAntiRollSpring = 125000000.00f;
    this->mDamperSmooth = 1.00f;
    this->mMinLeanSpeed = 20.00f;
    this->mMaxLeanAngle = 45.00f;
    this->mMaxPitchAngle = 75.00f;
    this->mLeanInAir = true;
    this->mCruiseControl = false;
    this->mCruiseSpeed = 0.00f;
}

void UFGearArcadeAssists::setTractionAssist(bool Enable) {
}

void UFGearArcadeAssists::setTorqueSplitter(bool Enable) {
}

void UFGearArcadeAssists::setRecoverAssists(bool Enable) {
}

void UFGearArcadeAssists::setMinLeanSpeed(float V) {
}

void UFGearArcadeAssists::setMaxPitchAngle(float V) {
}

void UFGearArcadeAssists::setMaxLeanAngle(float V) {
}

void UFGearArcadeAssists::setLeanInAir(bool Enable) {
}

void UFGearArcadeAssists::setInstantSpeed(float kmhSpeed, int32 gear) {
}

void UFGearArcadeAssists::setDriftAssist(bool Enable) {
}

void UFGearArcadeAssists::setDamperSmooth(float V) {
}

void UFGearArcadeAssists::setCruiseControl(bool Active, float kmhSpeed) {
}

void UFGearArcadeAssists::setBikeHelper(bool Enable) {
}

void UFGearArcadeAssists::setAntiRollSpring(float V) {
}

void UFGearArcadeAssists::setAntirollBars(bool Enable) {
}


