#include "FGearEffects.h"

UFGearEffects::UFGearEffects(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->mStopEffectsWhenSleeping = false;
    this->mStopEngineSoundWhenSleeping = false;
    this->mLongSlipThreshold = 0.20f;
    this->mLatSlipThreshold = 0.20f;
    this->mEnableTireSmoke = true;
    this->mEnableSkidmarks = true;
    this->mSkidmarkMaterial = NULL;
    this->mMaxMarks = 128;
    this->mMarkWidth = 0.00f;
    this->mGroundOffset = 0.01f;
    this->mMinDistance = 0.00f;
    this->mBaseVolume = 1.00f;
    this->mEngineVolume = 0.30f;
    this->mSkidVolume = 0.20f;
    this->mEngineHigh = NULL;
    this->mEngineHighBasePitch = 1.00f;
    this->mEngineHighPitchScale = 1.00f;
    this->mEngineHighInnerRadius = 1000.00f;
    this->mEngineHighFalloffDistance = 1000.00f;
    this->mEngineHighComponent = NULL;
    this->mEngineLow = NULL;
    this->mEngineLowBasePitch = 1.00f;
    this->mEngineLowPitchScale = 1.00f;
    this->mEngineLowInnerRadius = 1000.00f;
    this->mEngineLowFalloffDistance = 1000.00f;
    this->mEngineLowComponent = NULL;
    this->mEnableSkidclip = true;
    this->mSkidclipInnerRadius = 1000.00f;
    this->mSkidclipFalloffDistance = 2000.00f;
    this->mSkidSoundComponent = NULL;
    this->mBackfireInterval = 0.10f;
    this->mBackfireLimit = 1000.00f;
    this->mFireRpmRatio = 25.00f;
    this->mFireGearChange = 80.00f;
    this->mFireLimiter = 50.00f;
    this->mDefaultPhysicalMaterial = NULL;
}

void UFGearEffects::setStopEffectsWhenSleeping(bool stopEffects, bool stopEngineSound) {
}

void UFGearEffects::setSkidVolume(float V) {
}

void UFGearEffects::setEngineVolume(float V) {
}

void UFGearEffects::setEnableSkidmarks(bool E) {
}

void UFGearEffects::setBaseVolume(float V) {
}

void UFGearEffects::onWake(AFGearVehicle* Vehicle) {
}

void UFGearEffects::onSleep(AFGearVehicle* Vehicle) {
}

bool UFGearEffects::getStopEngineSoundWhenSleeping() const {
    return false;
}

bool UFGearEffects::getStopEffectsWhenSleeping() const {
    return false;
}

float UFGearEffects::getSkidVolume() const {
    return 0.0f;
}

float UFGearEffects::getEngineVolume() const {
    return 0.0f;
}

bool UFGearEffects::getEnableSkidmarks() const {
    return false;
}

float UFGearEffects::getBaseVolume() const {
    return 0.0f;
}


