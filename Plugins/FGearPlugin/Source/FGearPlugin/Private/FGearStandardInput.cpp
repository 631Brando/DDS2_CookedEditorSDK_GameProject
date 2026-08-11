#include "FGearStandardInput.h"

UFGearStandardInput::UFGearStandardInput(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->mEnabled = true;
    this->mInputType = FGearInputSystemType::LEGACY;
    this->mCombinedAxis = true;
    this->mControllerType = FGearControllerType::KEYBOARD;
    this->mShifterType = FGearShifterType::AUTO;
    this->mSteerSensivity = 5.00f;
    this->mSteerSpeedCurve = NULL;
    this->mSteerLimitCurve = NULL;
    this->mSteerInputGravity = 1.50f;
    this->mSteerRange = 100.00f;
    this->mSteerDeadzone = 0.01f;
    this->mSteeringAssist = 0.00f;
    this->mSteeringAssistThresholdAngle = 1.00f;
    this->mThrottleSensivity = 3.00f;
    this->mThrottleRange = 100.00f;
    this->mThrottleDeadzone = 0.01f;
    this->mThrottleEngagement = NULL;
    this->mBrakingSensivity = 3.00f;
    this->mBrakingRange = 100.00f;
    this->mBrakingDeadzone = 0.01f;
    this->mBrakeEngagement = NULL;
    this->mClutchSensivity = 3.00f;
    this->mClutchRange = 100.00f;
    this->mClutchDeadzone = 0.01f;
    this->mClutchEngagement = NULL;
    this->mDefaultMappingContext = NULL;
    this->mVerticalAction = NULL;
    this->mHorizontalAction = NULL;
    this->mThrottleAction = NULL;
    this->mBrakeAction = NULL;
    this->mLeftAction = NULL;
    this->mRightAction = NULL;
    this->mClutchAction = NULL;
    this->mHandbrakeAction = NULL;
    this->mShiftAction = NULL;
    this->mShift1Action = NULL;
    this->mShift2Action = NULL;
    this->mShift3Action = NULL;
    this->mShift4Action = NULL;
    this->mShift5Action = NULL;
    this->mShift6Action = NULL;
    this->mShiftRAction = NULL;
    this->mInputComp = NULL;
}

void UFGearStandardInput::setVerticalAxis(FName S) {
}

void UFGearStandardInput::setVerticalAction(UInputAction* ia) {
}

void UFGearStandardInput::setThrottleSensivity(float F) {
}

void UFGearStandardInput::setThrottleRange(float F) {
}

void UFGearStandardInput::setThrottleEngagementCurve(UCurveFloat* C) {
}

void UFGearStandardInput::setThrottleDeadzone(float F) {
}

void UFGearStandardInput::setThrottleAxis(FName S) {
}

void UFGearStandardInput::setThrottleAction(UInputAction* ia) {
}

void UFGearStandardInput::setSteerSpeedCurve(UCurveFloat* C) {
}

void UFGearStandardInput::setSteerSensivity(float F) {
}

void UFGearStandardInput::setSteerRange(float F) {
}

void UFGearStandardInput::setSteerLimitCurve(UCurveFloat* C) {
}

void UFGearStandardInput::setSteerInputGravity(float F) {
}

void UFGearStandardInput::setSteeringAssistThresholdAngle(float F) {
}

void UFGearStandardInput::setSteeringAssist(float F) {
}

void UFGearStandardInput::setSteerDeadzone(float F) {
}

void UFGearStandardInput::setStartGridMode(bool B) {
}

void UFGearStandardInput::setShiftRAxis(FName S) {
}

void UFGearStandardInput::setShiftRAction(UInputAction* ia) {
}

void UFGearStandardInput::setShifterType(FGearShifterType st) {
}

void UFGearStandardInput::setShiftAxis(FName S) {
}

void UFGearStandardInput::setShiftAction(UInputAction* ia) {
}

void UFGearStandardInput::setShift6Axis(FName S) {
}

void UFGearStandardInput::setShift6Action(UInputAction* ia) {
}

void UFGearStandardInput::setShift5Axis(FName S) {
}

void UFGearStandardInput::setShift5Action(UInputAction* ia) {
}

void UFGearStandardInput::setShift4Axis(FName S) {
}

void UFGearStandardInput::setShift4Action(UInputAction* ia) {
}

void UFGearStandardInput::setShift3Axis(FName S) {
}

void UFGearStandardInput::setShift3Action(UInputAction* ia) {
}

void UFGearStandardInput::setShift2Axis(FName S) {
}

void UFGearStandardInput::setShift2Action(UInputAction* ia) {
}

void UFGearStandardInput::setShift1Axis(FName S) {
}

void UFGearStandardInput::setShift1Action(UInputAction* ia) {
}

void UFGearStandardInput::setRightAxis(FName S) {
}

void UFGearStandardInput::setRightAction(UInputAction* ia) {
}

void UFGearStandardInput::setReadInputs(bool B) {
}

void UFGearStandardInput::setLeftAxis(FName S) {
}

void UFGearStandardInput::setLeftAction(UInputAction* ia) {
}

void UFGearStandardInput::setInputs(float Throttle, float Brake, float steer, float Clutch, int32 gear, bool hb) {
}

void UFGearStandardInput::setHorizontalAxis(FName S) {
}

void UFGearStandardInput::setHorizontalAction(UInputAction* ia) {
}

void UFGearStandardInput::setHandbrakeAxis(FName S) {
}

void UFGearStandardInput::setHandbrakeAction(UInputAction* ia) {
}

void UFGearStandardInput::SetEnabled(bool Enable, bool NewResetInputs) {
}

void UFGearStandardInput::setDefaultMappingContext(UInputMappingContext* IMC) {
}

void UFGearStandardInput::setControllerType(FGearControllerType ct) {
}

void UFGearStandardInput::setCombinedAxis(bool B) {
}

void UFGearStandardInput::setCluthEngagementCurve(UCurveFloat* C) {
}

void UFGearStandardInput::setClutchSensivity(float F) {
}

void UFGearStandardInput::setClutchRange(float F) {
}

void UFGearStandardInput::setClutchDeadzone(float F) {
}

void UFGearStandardInput::setClutchAxis(FName S) {
}

void UFGearStandardInput::setClutchAction(UInputAction* ia) {
}

void UFGearStandardInput::setBrakingSensivity(float F) {
}

void UFGearStandardInput::setBrakingRange(float F) {
}

void UFGearStandardInput::setBrakingDeadzone(float F) {
}

void UFGearStandardInput::setBrakeEngagementCurve(UCurveFloat* C) {
}

void UFGearStandardInput::setBrakeAxis(FName S) {
}

void UFGearStandardInput::setBrakeAction(UInputAction* ia) {
}

void UFGearStandardInput::resetInputs() {
}

void UFGearStandardInput::overrideFinalInputs(float Throttle, float Brake, float steer, float Clutch, int32 gear, bool hb) {
}

bool UFGearStandardInput::isSteeringAssistActive() const {
    return false;
}

bool UFGearStandardInput::IsEnabled() const {
    return false;
}

FName UFGearStandardInput::getVerticalAxis() const {
    return NAME_None;
}

UInputAction* UFGearStandardInput::getVerticalAction() const {
    return NULL;
}

float UFGearStandardInput::getThrottleSensivity() const {
    return 0.0f;
}

float UFGearStandardInput::getThrottleRawInput() const {
    return 0.0f;
}

float UFGearStandardInput::getThrottleRange() const {
    return 0.0f;
}

UCurveFloat* UFGearStandardInput::getThrottleEngagementCurve() const {
    return NULL;
}

float UFGearStandardInput::getThrottleDeadzone() const {
    return 0.0f;
}

FName UFGearStandardInput::getThrottleAxis() const {
    return NAME_None;
}

UInputAction* UFGearStandardInput::getThrottleAction() const {
    return NULL;
}

UCurveFloat* UFGearStandardInput::getSteerSpeedCurve() const {
    return NULL;
}

float UFGearStandardInput::getSteerSensivity() const {
    return 0.0f;
}

float UFGearStandardInput::getSteerRawInput() const {
    return 0.0f;
}

float UFGearStandardInput::getSteerRange() const {
    return 0.0f;
}

UCurveFloat* UFGearStandardInput::getSteerLimitCurve() const {
    return NULL;
}

float UFGearStandardInput::getSteerInputGravity() const {
    return 0.0f;
}

float UFGearStandardInput::getSteeringAssistThresholdAngle() const {
    return 0.0f;
}

float UFGearStandardInput::getSteeringAssist() const {
    return 0.0f;
}

float UFGearStandardInput::getSteerDeadzone() const {
    return 0.0f;
}

FName UFGearStandardInput::getShiftRAxis() const {
    return NAME_None;
}

UInputAction* UFGearStandardInput::getShiftRAction() const {
    return NULL;
}

FGearShifterType UFGearStandardInput::getShifterType() const {
    return FGearShifterType::AUTO;
}

FName UFGearStandardInput::getShiftAxis() const {
    return NAME_None;
}

UInputAction* UFGearStandardInput::getShiftAction() const {
    return NULL;
}

FName UFGearStandardInput::getShift6Axis() const {
    return NAME_None;
}

UInputAction* UFGearStandardInput::getShift6Action() const {
    return NULL;
}

FName UFGearStandardInput::getShift5Axis() const {
    return NAME_None;
}

UInputAction* UFGearStandardInput::getShift5Action() const {
    return NULL;
}

FName UFGearStandardInput::getShift4Axis() const {
    return NAME_None;
}

UInputAction* UFGearStandardInput::getShift4Action() const {
    return NULL;
}

FName UFGearStandardInput::getShift3Axis() const {
    return NAME_None;
}

UInputAction* UFGearStandardInput::getShift3Action() const {
    return NULL;
}

FName UFGearStandardInput::getShift2Axis() const {
    return NAME_None;
}

UInputAction* UFGearStandardInput::getShift2Action() const {
    return NULL;
}

FName UFGearStandardInput::getShift1Axis() const {
    return NAME_None;
}

UInputAction* UFGearStandardInput::getShift1Action() const {
    return NULL;
}

FName UFGearStandardInput::getRightAxis() const {
    return NAME_None;
}

UInputAction* UFGearStandardInput::getRightAction() const {
    return NULL;
}

FName UFGearStandardInput::getLeftAxis() const {
    return NAME_None;
}

UInputAction* UFGearStandardInput::getLeftAction() const {
    return NULL;
}

FGearInputSystemType UFGearStandardInput::getInputSystemType() const {
    return FGearInputSystemType::LEGACY;
}

FName UFGearStandardInput::getHorizontalAxis() const {
    return NAME_None;
}

UInputAction* UFGearStandardInput::getHorizontalAction() const {
    return NULL;
}

bool UFGearStandardInput::getHandbrakeInput() const {
    return false;
}

FName UFGearStandardInput::getHandbrakeAxis() const {
    return NAME_None;
}

UInputAction* UFGearStandardInput::getHandbrakeAction() const {
    return NULL;
}

int32 UFGearStandardInput::getGearboxInput() const {
    return 0;
}

UInputMappingContext* UFGearStandardInput::getDefaultMappingContext() const {
    return NULL;
}

FGearControllerType UFGearStandardInput::getControllerType() const {
    return FGearControllerType::KEYBOARD;
}

bool UFGearStandardInput::getCombinedAxis() const {
    return false;
}

UCurveFloat* UFGearStandardInput::getCluthEngagementCurve() const {
    return NULL;
}

float UFGearStandardInput::getClutchSensivity() const {
    return 0.0f;
}

float UFGearStandardInput::getClutchRawInput() const {
    return 0.0f;
}

float UFGearStandardInput::getClutchRange() const {
    return 0.0f;
}

float UFGearStandardInput::getClutchDeadzone() const {
    return 0.0f;
}

FName UFGearStandardInput::getClutchAxis() const {
    return NAME_None;
}

UInputAction* UFGearStandardInput::getClutchAction() const {
    return NULL;
}

float UFGearStandardInput::getBrakingSensivity() const {
    return 0.0f;
}

float UFGearStandardInput::getBrakingRange() const {
    return 0.0f;
}

float UFGearStandardInput::getBrakingDeadzone() const {
    return 0.0f;
}

float UFGearStandardInput::getBrakeRawInput() const {
    return 0.0f;
}

UCurveFloat* UFGearStandardInput::getBrakeEngagementCurve() const {
    return NULL;
}

FName UFGearStandardInput::getBrakeAxis() const {
    return NAME_None;
}

UInputAction* UFGearStandardInput::getBrakeAction() const {
    return NULL;
}


