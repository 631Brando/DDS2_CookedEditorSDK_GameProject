#include "FGearAxle.h"

UFGearAxle::UFGearAxle(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->mDifferentialType = FGearDifferentialType::DF_OPEN;
    this->mDiffStrength = 0.25f;
    this->mTorqueShare = 0.50f;
    this->mMaxSteerAngle = 0.00f;
    this->mAckermanCoeff = 1.00f;
    this->mAckermanReferenceIndex = 1;
    this->mHasHandbrake = false;
    this->mCamberAngle = 0.00f;
    this->mToeAngle = 0.00f;
}

void UFGearAxle::setWheelOptions(UFGearWheelOptions* wo) {
}

void UFGearAxle::setTorqueShare(float F) {
}

void UFGearAxle::setToeAngle(float F) {
}

void UFGearAxle::setTargetSteer(float S) {
}

void UFGearAxle::setRightWheel(UFGearWheel* W) {
}

void UFGearAxle::setMaxSteerAngle(float F) {
}

void UFGearAxle::setLeftWheel(UFGearWheel* W) {
}

void UFGearAxle::setHasHandBrake(bool B) {
}

void UFGearAxle::setDiffStrength(float F) {
}

void UFGearAxle::setDifferentialType(FGearDifferentialType dt) {
}

void UFGearAxle::setCamberAngle(float F) {
}

void UFGearAxle::setAckermanReferenceIndex(int32 I) {
}

void UFGearAxle::setAckermanCoeff(float F) {
}

bool UFGearAxle::hasSteering() const {
    return false;
}

bool UFGearAxle::hasHandBrake() const {
    return false;
}

float UFGearAxle::getWheelRPMToKMH() const {
    return 0.0f;
}

UFGearWheelOptions* UFGearAxle::getWheelOptions() const {
    return NULL;
}

float UFGearAxle::getTrackWidth() const {
    return 0.0f;
}

float UFGearAxle::getTorqueShare() const {
    return 0.0f;
}

float UFGearAxle::getToeAngle() const {
    return 0.0f;
}

float UFGearAxle::getRPM() const {
    return 0.0f;
}

UFGearWheel* UFGearAxle::getRightWheel() const {
    return NULL;
}

float UFGearAxle::getNormalizedSteering() const {
    return 0.0f;
}

float UFGearAxle::getMaxSteerAngle() const {
    return 0.0f;
}

float UFGearAxle::getMaxRpm() const {
    return 0.0f;
}

FVector UFGearAxle::getLocalCenter() const {
    return FVector{};
}

UFGearWheel* UFGearAxle::getLeftWheel() const {
    return NULL;
}

float UFGearAxle::getKMHSpeed() const {
    return 0.0f;
}

int32 UFGearAxle::getIndex() const {
    return 0;
}

FVector UFGearAxle::getGlobalCenter() const {
    return FVector{};
}

float UFGearAxle::getFeedbackTorque() const {
    return 0.0f;
}

float UFGearAxle::getDrivetrainFriction() const {
    return 0.0f;
}

float UFGearAxle::getDiffStrength() const {
    return 0.0f;
}

FGearDifferentialType UFGearAxle::getDifferentialType() const {
    return FGearDifferentialType::DF_OPEN;
}

float UFGearAxle::getCurRpm() const {
    return 0.0f;
}

float UFGearAxle::getCamberAngle() const {
    return 0.0f;
}

int32 UFGearAxle::getAckermanReferenceIndex() const {
    return 0;
}

float UFGearAxle::getAckermanCoeff() const {
    return 0.0f;
}

void UFGearAxle::applyWheelOptions() {
}


