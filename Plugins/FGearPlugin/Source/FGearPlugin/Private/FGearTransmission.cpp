#include "FGearTransmission.h"

UFGearTransmission::UFGearTransmission(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->mAutoChange = true;
    this->mAutoReverse = true;
    this->mAutoClutch = true;
    this->mRevMatching = true;
    this->mChangeTime = 100.00f;
    this->mGearUpRatio = 90.00f;
    this->mGearDownRatio = 80.00f;
    this->mGearUpVelocityBias = 1.00f;
    this->mGearDownVelocityBias = 1.00f;
    this->mClutchTime = 100.00f;
    this->mClutchScale = 100.00f;
    this->mGearRatios.AddDefaulted(2);
    this->mFinalGearRatio = 3.00f;
    this->mClutchAssist = false;
    this->mClutchScaleMin = 0.00f;
    this->mClutchScaleMax = 0.00f;
}

void UFGearTransmission::setThrottleState(int32 ts) {
}

void UFGearTransmission::setRevMatching(bool B) {
}

void UFGearTransmission::setPauseTime(float F) {
}

void UFGearTransmission::setGearUpVelocityBias(float F) {
}

void UFGearTransmission::setGearUpRatio(float F) {
}

void UFGearTransmission::setGearRatio(int32 gear, float Ratio) {
}

void UFGearTransmission::setGearDownVelocityBias(float F) {
}

void UFGearTransmission::setGearDownRatio(float F) {
}

void UFGearTransmission::setGearCount(int32 Size) {
}

void UFGearTransmission::setFinalGearRatio(float F) {
}

void UFGearTransmission::setCurrentGear(int32 gear, bool Force) {
}

void UFGearTransmission::setClutchTime(float T) {
}

void UFGearTransmission::setClutchState(float cs) {
}

void UFGearTransmission::setClutchScale(float cs) {
}

void UFGearTransmission::setChangeTime(float T) {
}

void UFGearTransmission::setAutoReverse(bool B) {
}

void UFGearTransmission::setAutoClutch(bool B) {
}

void UFGearTransmission::setAutoChange(bool B) {
}

void UFGearTransmission::refreshParameters() {
}

bool UFGearTransmission::isRevMatching() const {
    return false;
}

bool UFGearTransmission::isChanging() const {
    return false;
}

bool UFGearTransmission::isAutoReverse() const {
    return false;
}

bool UFGearTransmission::isAutoClutch() const {
    return false;
}

bool UFGearTransmission::isAutoChange() const {
    return false;
}

float UFGearTransmission::getTransmissionRatio() const {
    return 0.0f;
}

TArray<float> UFGearTransmission::getMaxSpeeds() const {
    return TArray<float>();
}

int32 UFGearTransmission::getMaxGear() const {
    return 0;
}

float UFGearTransmission::getGearUpVelocityBias() const {
    return 0.0f;
}

float UFGearTransmission::getGearUpRatio() const {
    return 0.0f;
}

float UFGearTransmission::getGearRatio(int32 gear) const {
    return 0.0f;
}

float UFGearTransmission::getGearMaxSpeed(int32 gear) const {
    return 0.0f;
}

float UFGearTransmission::getGearDownVelocityBias() const {
    return 0.0f;
}

float UFGearTransmission::getGearDownRatio() const {
    return 0.0f;
}

int32 UFGearTransmission::getGearCount() const {
    return 0;
}

float UFGearTransmission::getFinalGearRatio() const {
    return 0.0f;
}

int32 UFGearTransmission::getCurGear() const {
    return 0;
}

float UFGearTransmission::getClutchTime() const {
    return 0.0f;
}

float UFGearTransmission::getClutchState() const {
    return 0.0f;
}

float UFGearTransmission::getClutchScale() const {
    return 0.0f;
}

float UFGearTransmission::getChangeTime() const {
    return 0.0f;
}

void UFGearTransmission::gearUp(bool skipN) {
}

void UFGearTransmission::gearDown(bool skipN) {
}


