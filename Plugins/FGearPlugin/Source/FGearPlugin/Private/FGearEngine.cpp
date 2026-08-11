#include "FGearEngine.h"

UFGearEngine::UFGearEngine(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->mTorqueCurve = NULL;
    this->mTorqueScale = 1.00f;
    this->mFrictionTorque = 50.00f;
    this->mIdleRpm = 1000.00f;
    this->mLimitRpm = 6500.00f;
    this->mLimiterTime = 100.00f;
    this->mEngineInertia = 0.25f;
}

void UFGearEngine::setTorqueScale(float F) {
}

void UFGearEngine::setTorqueCurve(UCurveFloat* Curve) {
}

void UFGearEngine::setThrottle(float pedal) {
}

void UFGearEngine::setRunning(bool B) {
}

void UFGearEngine::setRpm(float F) {
}

void UFGearEngine::setLimitRpm(float F) {
}

void UFGearEngine::setLimiterTime(float F) {
}

void UFGearEngine::setLimiter(float L) {
}

void UFGearEngine::setIdleRpm(float F) {
}

void UFGearEngine::setFrictionTorque(float F) {
}

void UFGearEngine::setEngineInertia(float F) {
}

void UFGearEngine::resetRpm() {
}

bool UFGearEngine::IsRunning() const {
    return false;
}

bool UFGearEngine::isLimiterOn() const {
    return false;
}

float UFGearEngine::getTorqueScale() const {
    return 0.0f;
}

UCurveFloat* UFGearEngine::getTorqueCurve() const {
    return NULL;
}

float UFGearEngine::getTorque() const {
    return 0.0f;
}

float UFGearEngine::getThrottle() const {
    return 0.0f;
}

float UFGearEngine::getRpmRatio() const {
    return 0.0f;
}

float UFGearEngine::getRPM() const {
    return 0.0f;
}

float UFGearEngine::getLimitRpm() const {
    return 0.0f;
}

float UFGearEngine::getLimiterTime() const {
    return 0.0f;
}

float UFGearEngine::getIdleRpm() const {
    return 0.0f;
}

float UFGearEngine::getFrictionTorque() const {
    return 0.0f;
}

float UFGearEngine::getEngineInertia() const {
    return 0.0f;
}

void UFGearEngine::calculatePeakTorqueRpm() {
}

void UFGearEngine::calculateMaxPower(float& maxPower, float& maxPowerRpm) {
}


