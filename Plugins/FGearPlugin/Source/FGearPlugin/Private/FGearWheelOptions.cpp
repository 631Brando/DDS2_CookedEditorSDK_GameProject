#include "FGearWheelOptions.h"

UFGearWheelOptions::UFGearWheelOptions(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->mTireModelClass = NULL;
    this->mTireModel = NULL;
    this->mLateralFriction = 1.00f;
    this->mLongitudinalFriction = 1.00f;
    this->mLateralScale = 1.00f;
    this->mLongitudinalScale = 1.00f;
    this->mOverturnScale = 0.00f;
    this->mRollMomentScale = 0.00f;
    this->mSelfAlignScale = 0.00f;
    this->mTirePressure = 2.00f;
    this->mRadius = 0.25f;
    this->mWidth = 0.20f;
    this->mForwardOffset = 0.00f;
    this->mSpacerOffset = 0.00f;
    this->mRimOffset = 0.00f;
    this->mCastOffset = 0.00f;
    this->mMass = 10.00f;
    this->mBrakeTorque = 1000.00f;
    this->mSuspensionUpTravel = 0.10f;
    this->mSuspensionDownTravel = 0.10f;
    this->mSuspensionSpring = 20.00f;
    this->mCompressionDamper = 1000.00f;
    this->mRelaxationDamper = 1000.00f;
    this->mSuspensionPreload = 0.00f;
}

void UFGearWheelOptions::setWidth(float F) {
}

void UFGearWheelOptions::setTirePressure(float F) {
}

void UFGearWheelOptions::setTireModel(UFGearTire* T) {
}

void UFGearWheelOptions::setSuspensionUpTravel(float F) {
}

void UFGearWheelOptions::setSuspensionSpring(float F) {
}

void UFGearWheelOptions::setSuspensionPreload(float F) {
}

void UFGearWheelOptions::setSuspensionDownTravel(float F) {
}

void UFGearWheelOptions::setSpacerOffset(float F) {
}

void UFGearWheelOptions::setSelfAlignScale(float F) {
}

void UFGearWheelOptions::setRollMomentScale(float F) {
}

void UFGearWheelOptions::setRimOffset(float F) {
}

void UFGearWheelOptions::setRelaxationDamper(float F) {
}

void UFGearWheelOptions::SetRadius(float F) {
}

void UFGearWheelOptions::setOverturnScale(float F) {
}

void UFGearWheelOptions::setMass(float F) {
}

void UFGearWheelOptions::setLongitudinalScale(float F) {
}

void UFGearWheelOptions::setLongitudinalFriction(float F) {
}

void UFGearWheelOptions::setLateralScale(float F) {
}

void UFGearWheelOptions::setLateralFriction(float F) {
}

void UFGearWheelOptions::setForwardOffset(float F) {
}

void UFGearWheelOptions::setCompressionDamper(float F) {
}

void UFGearWheelOptions::setCastOffset(float F) {
}

void UFGearWheelOptions::setBrakeTorque(float F) {
}

float UFGearWheelOptions::GetWidth() const {
    return 0.0f;
}

float UFGearWheelOptions::getTirePressure() const {
    return 0.0f;
}

UFGearTire* UFGearWheelOptions::getTireModel() const {
    return NULL;
}

float UFGearWheelOptions::getSuspensionUpTravel() const {
    return 0.0f;
}

float UFGearWheelOptions::getSuspensionSpring() const {
    return 0.0f;
}

float UFGearWheelOptions::getSuspensionPreload() const {
    return 0.0f;
}

float UFGearWheelOptions::getSuspensionDownTravel() const {
    return 0.0f;
}

float UFGearWheelOptions::getSpacerOffset() const {
    return 0.0f;
}

float UFGearWheelOptions::getSelfAlignScale() const {
    return 0.0f;
}

float UFGearWheelOptions::getRollMomentScale() const {
    return 0.0f;
}

float UFGearWheelOptions::getRimOffset() const {
    return 0.0f;
}

float UFGearWheelOptions::getRelaxationDamper() const {
    return 0.0f;
}

float UFGearWheelOptions::getRadius() const {
    return 0.0f;
}

float UFGearWheelOptions::getOverturnScale() const {
    return 0.0f;
}

float UFGearWheelOptions::GetMass() const {
    return 0.0f;
}

float UFGearWheelOptions::getLongitudinalScale() const {
    return 0.0f;
}

float UFGearWheelOptions::getLongitudinalFriction() const {
    return 0.0f;
}

float UFGearWheelOptions::getLateralScale() const {
    return 0.0f;
}

float UFGearWheelOptions::getLateralFriction() const {
    return 0.0f;
}

float UFGearWheelOptions::getForwardOffset() const {
    return 0.0f;
}

float UFGearWheelOptions::getCompressionDamper() const {
    return 0.0f;
}

float UFGearWheelOptions::getCastOffset() const {
    return 0.0f;
}

float UFGearWheelOptions::getBrakeTorque() const {
    return 0.0f;
}


