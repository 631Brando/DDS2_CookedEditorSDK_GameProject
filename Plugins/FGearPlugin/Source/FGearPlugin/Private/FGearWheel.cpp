#include "FGearWheel.h"

UFGearWheel::UFGearWheel(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->mIsActive = true;
    this->mSide = FGearWheelSide::WS_LEFT;
    this->mConvexShape = NULL;
}

void UFGearWheel::setWidth(float F) {
}

void UFGearWheel::setWheelSide(FGearWheelSide S) {
}

void UFGearWheel::setSuspensionUpTravel(float F) {
}

void UFGearWheel::setSuspensionSpring(float F) {
}

void UFGearWheel::setSuspensionPreload(float F) {
}

void UFGearWheel::setSuspensionDownTravel(float F) {
}

void UFGearWheel::setSpringCoeff(float F) {
}

void UFGearWheel::SetSpeed(float S) {
}

void UFGearWheel::setRollScale(float F) {
}

void UFGearWheel::setRelaxationDamper(float F) {
}

void UFGearWheel::SetRadius(float F) {
}

void UFGearWheel::setPressure(float F) {
}

void UFGearWheel::setOverturnScale(float F) {
}

void UFGearWheel::setMass(float F) {
}

void UFGearWheel::setLngScale(float F) {
}

void UFGearWheel::setLngFriction(float F) {
}

void UFGearWheel::setLatScale(float F) {
}

void UFGearWheel::setLatFriction(float F) {
}

void UFGearWheel::setLateralOffsets(float Forward, float Spacer, float rim) {
}

void UFGearWheel::setInherentDrag(float F) {
}

void UFGearWheel::setFrictionFactor(float F) {
}

void UFGearWheel::setEnable(bool B) {
}

void UFGearWheel::setCurrentSteer(float S) {
}

void UFGearWheel::setCompressionDamper(float F) {
}

void UFGearWheel::setBraking(float B) {
}

void UFGearWheel::setBrakeTorque(float F) {
}

void UFGearWheel::setBoneName(const FString& NewName) {
}

void UFGearWheel::setAlignScale(float F) {
}

void UFGearWheel::setAdditionalDrag(float F) {
}

bool UFGearWheel::IsEnabled() const {
    return false;
}

bool UFGearWheel::isASRActive() const {
    return false;
}

bool UFGearWheel::isABSActive() const {
    return false;
}

bool UFGearWheel::hasDrive() const {
    return false;
}

bool UFGearWheel::hasContact() const {
    return false;
}

FGearWheelSide UFGearWheel::getWheelSide() const {
    return FGearWheelSide::WS_LEFT;
}

float UFGearWheel::getWheelRPMToKMH() const {
    return 0.0f;
}

FQuat UFGearWheel::getWheelRotation() const {
    return FQuat{};
}

FVector UFGearWheel::getWheelPosition() const {
    return FVector{};
}

float UFGearWheel::getSuspensionTotalLength() const {
    return 0.0f;
}

float UFGearWheel::getSuspensionSpring() const {
    return 0.0f;
}

float UFGearWheel::getSuspensionCompressRatio() const {
    return 0.0f;
}

float UFGearWheel::getSuspensionCompressedLength() const {
    return 0.0f;
}

float UFGearWheel::getSpeed() const {
    return 0.0f;
}

float UFGearWheel::getSlipRatio() const {
    return 0.0f;
}

float UFGearWheel::getSlipAngle() const {
    return 0.0f;
}

float UFGearWheel::getRPM() const {
    return 0.0f;
}

FHitResult UFGearWheel::getRayHit() const {
    return FHitResult{};
}

float UFGearWheel::getRadius() const {
    return 0.0f;
}

float UFGearWheel::getPressure() const {
    return 0.0f;
}

float UFGearWheel::getPitch() const {
    return 0.0f;
}

float UFGearWheel::getLongitudinalSlip() const {
    return 0.0f;
}

FVector UFGearWheel::getLongitudinalForce() const {
    return FVector{};
}

FVector UFGearWheel::getLocalHubPosition() const {
    return FVector{};
}

float UFGearWheel::getLateralSlip() const {
    return 0.0f;
}

FVector UFGearWheel::getLateralForce() const {
    return FVector{};
}

float UFGearWheel::getKMHSpeed() const {
    return 0.0f;
}

float UFGearWheel::getInherentDrag() const {
    return 0.0f;
}

FVector UFGearWheel::getHubPosition() const {
    return FVector{};
}

float UFGearWheel::getGroundSpeed() const {
    return 0.0f;
}

float UFGearWheel::getGroundRpm() const {
    return 0.0f;
}

FVector UFGearWheel::getGlobalRight() const {
    return FVector{};
}

FVector UFGearWheel::getGlobalForward() const {
    return FVector{};
}

float UFGearWheel::getFrictionFactor() const {
    return 0.0f;
}

float UFGearWheel::getFeedbackTorque() const {
    return 0.0f;
}

float UFGearWheel::getCurrentSteer() const {
    return 0.0f;
}

float UFGearWheel::getCurrentLoad() const {
    return 0.0f;
}

FVector UFGearWheel::getCombinedTorque() const {
    return FVector{};
}

float UFGearWheel::getBraking() const {
    return 0.0f;
}

UFGearAxle* UFGearWheel::getAxle() const {
    return NULL;
}

float UFGearWheel::getAdditionalDrag() const {
    return 0.0f;
}


