#include "FGearVehicle.h"
#include "FGearAeroDynamics.h"
#include "FGearAxle.h"
#include "FGearEngine.h"
#include "FGearReplication.h"
#include "FGearSkeletalMeshComponent.h"
#include "FGearStandardInput.h"
#include "FGearTransmission.h"
#include "FGearWheel.h"
#include "FGearWheelOptions.h"
#include "Net/UnrealNetwork.h"

AFGearVehicle::AFGearVehicle(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bNetLoadOnClient = false;
    this->RootComponent = CreateDefaultSubobject<UFGearSkeletalMeshComponent>(TEXT("Mesh Component"));
    this->mEngine = CreateDefaultSubobject<UFGearEngine>(TEXT("Engine"));
    this->mTransmission = CreateDefaultSubobject<UFGearTransmission>(TEXT("transmission"));
    this->mStandardInput = CreateDefaultSubobject<UFGearStandardInput>(TEXT("Standard Input"));
    this->mAeroDynamics = CreateDefaultSubobject<UFGearAeroDynamics>(TEXT("Aero Dynamics"));
    this->mOrbitCamera = NULL;
    this->mArcadeAssists = NULL;
    this->mSuspensionConstraint = NULL;
    this->mAxle0 = CreateDefaultSubobject<UFGearAxle>(TEXT("Front Axle"));
    this->mWheelOptions0 = CreateDefaultSubobject<UFGearWheelOptions>(TEXT("Front Wheel Options"));
    this->mWheelLeft0 = CreateDefaultSubobject<UFGearWheel>(TEXT("Front Wheel Left"));
    this->mWheelRight0 = CreateDefaultSubobject<UFGearWheel>(TEXT("Front Wheel Right"));
    this->mAxle1 = CreateDefaultSubobject<UFGearAxle>(TEXT("Rear Axle"));
    this->mWheelOptions1 = CreateDefaultSubobject<UFGearWheelOptions>(TEXT("Rear Wheel Options"));
    this->mWheelLeft1 = CreateDefaultSubobject<UFGearWheel>(TEXT("Rear Wheel Left"));
    this->mWheelRight1 = CreateDefaultSubobject<UFGearWheel>(TEXT("Rear Wheel Right"));
    this->mReplication = CreateDefaultSubobject<UFGearReplication>(TEXT("Replication"));
    this->mMesh = (UFGearSkeletalMeshComponent*)RootComponent;
    this->mAnimation = NULL;
    this->mUpdateRate = 250;
    this->mMass = 1000.00f;
    this->mCustomGravity = false;
    this->mQueryType = FGearQueryType::Line;
    this->mRays = 1;
    this->mLateralRays = 1;
    this->mQueryMobilityType = FGearQueryMobilityType::Any;
    this->mTraceChannel = ECC_Visibility;
    this->mIgnoreMask = 0;
    this->mTraceComplex = false;
    this->mConvexUp = FGearUpDirection::Y_UP;
    this->mConvexVisible = false;
    this->mDetectGround = false;
    this->mAllowReverse = true;
    this->mTirePenetration = true;
    this->mRelaxationDownforce = false;
    this->mHardContactScale = 0.00f;
    this->mHandBrakePower = 1.00f;
    this->mReverseBrakeSpeed = 1.00f;
    this->mRollingResistanceCoeff = 1.00f;
    this->mDrivetrainInertia = 1.00f;
    this->mDrivetrainFriction = 50.00f;
    this->mStickyTireSpeed = 0.00f;
    this->mReactionScale = 0.00f;
    this->mOptimumSlipWeight = 0.00f;
    this->mABS = 0.00f;
    this->mMinAbsSpeed = 10.00f;
    this->mASR = 0.00f;
    this->mUnderSteerAssist = 0.00f;
    this->mMinUnderSteerAngle = 10.00f;
    this->mOverSteerAssist = 0.00f;
    this->mMinOverSteerAngle = 20.00f;
    this->mFrontAntiRollPower = 0.00f;
    this->mRearAntiRollPower = 0.00f;
    this->mSleepLinearThreshold = 0.00f;
    this->mSleepAngularThreshold = 0.00f;
    this->mSleepWaitingTime = 1.00f;
    this->mWakeUpSources = 1;
    this->mInSleep = false;
    this->mAeroDynamics->SetupAttachment(RootComponent);
    this->mAxle0->SetupAttachment(RootComponent);
    this->mAxle1->SetupAttachment(RootComponent);
    this->mEngine->SetupAttachment(RootComponent);
    this->mReplication->SetupAttachment(RootComponent);
    this->mStandardInput->SetupAttachment(RootComponent);
    this->mTransmission->SetupAttachment(RootComponent);
    this->mWheelLeft0->SetupAttachment(mAxle0);
    this->mWheelLeft1->SetupAttachment(mAxle1);
    this->mWheelOptions0->SetupAttachment(mAxle0);
    this->mWheelOptions1->SetupAttachment(mAxle1);
    this->mWheelRight0->SetupAttachment(mAxle0);
    this->mWheelRight1->SetupAttachment(mAxle1);
}

void AFGearVehicle::wakeUp() {
}

void AFGearVehicle::sleep() {
}

void AFGearVehicle::setUseCustomGravity(bool use) {
}

void AFGearVehicle::setUpdateRate(int32 I) {
}

void AFGearVehicle::setUpdateInputs(bool B) {
}

void AFGearVehicle::setUnderSteerAssist(float F) {
}

void AFGearVehicle::setTraceComplex(bool B) {
}

void AFGearVehicle::setTraceChannel(TEnumAsByte<ECollisionChannel> L) {
}

void AFGearVehicle::setTirePenetration(bool B) {
}

void AFGearVehicle::setStickyTireState(float F) {
}

void AFGearVehicle::setStickyTireSpeed(float F) {
}

void AFGearVehicle::setSteering(float steerInput) {
}

void AFGearVehicle::setSleepWaitingTime(const float Time) {
}

void AFGearVehicle::setSleepLinearThreshold(const float Threshold) {
}

void AFGearVehicle::setSleepAngularThreshold(const float Threshold) {
}

void AFGearVehicle::setRollingResistanceCoeff(float F) {
}

void AFGearVehicle::setReverseBrake(float F) {
}

void AFGearVehicle::setRelaxationDownforce(bool B) {
}

void AFGearVehicle::setRearAntiRollPower(float F) {
}

void AFGearVehicle::setReactionForceScale(float F) {
}

void AFGearVehicle::setRayCount(int32 ct) {
}

void AFGearVehicle::setQueryType(FGearQueryType T) {
}

void AFGearVehicle::setQueryMobilityType(FGearQueryMobilityType T) {
}

void AFGearVehicle::setOverSteerAssist(float F) {
}

void AFGearVehicle::setOptimumSlipWeight(float F) {
}

void AFGearVehicle::setMinUnderSteerAngle(float F) {
}

void AFGearVehicle::setMinOverSteerAngle(float F) {
}

void AFGearVehicle::setMinAbsSpeed(float F) {
}

void AFGearVehicle::setMass(float Mass) {
}

void AFGearVehicle::setLateralRayCount(int32 ct) {
}

void AFGearVehicle::setInertiaScale(FVector iscale) {
}

void AFGearVehicle::setIgnoreMask(uint8 F) {
}

void AFGearVehicle::setHardContactScale(float F) {
}

void AFGearVehicle::setHandbrakePower(float F) {
}

void AFGearVehicle::setGravity(FVector Gravity) {
}

void AFGearVehicle::setFrontAntiRollPower(float F) {
}

void AFGearVehicle::setDrivetrainInertia(float F) {
}

void AFGearVehicle::setDrivetrainFriction(float F) {
}

void AFGearVehicle::setDetectGround(bool B) {
}

void AFGearVehicle::setCenterOfMassOffset(FVector com) {
}

void AFGearVehicle::setBraking(float brakeInput, bool Handbrake) {
}

void AFGearVehicle::setASR(float F) {
}

void AFGearVehicle::setAllowReverse(bool allow) {
}

void AFGearVehicle::setABS(float F) {
}

void AFGearVehicle::serverWakeUp_Implementation() {
}

void AFGearVehicle::serverSleep_Implementation() {
}

void AFGearVehicle::serverReset_Implementation(FVector Position, FQuat Rotation) {
}

void AFGearVehicle::saveState(FFGearVehicleState& State) {
}

void AFGearVehicle::Reset(FVector Position, FRotator Rotation) {
}

void AFGearVehicle::onWake(UPrimitiveComponent* Component, FName bone) {
}

void AFGearVehicle::onRepInSleep() {
}

void AFGearVehicle::loadState(FFGearVehicleState State) {
}

bool AFGearVehicle::isUnderSteering() const {
    return false;
}

bool AFGearVehicle::isOverSteering() const {
    return false;
}

bool AFGearVehicle::isHandbrakeOn() const {
    return false;
}

float AFGearVehicle::getWheelSpeedLimitKMH() const {
    return 0.0f;
}

int32 AFGearVehicle::getWheelCount() const {
    return 0;
}

float AFGearVehicle::getVelocitySize() const {
    return 0.0f;
}

FVector AFGearVehicle::getVelocityDir() const {
    return FVector{};
}

FVector AFGearVehicle::getUpDir() const {
    return FVector{};
}

int32 AFGearVehicle::getUpdateRate() const {
    return 0;
}

UFGearTransmission* AFGearVehicle::getTransmission() const {
    return NULL;
}

bool AFGearVehicle::getTraceComplex() const {
    return false;
}

TEnumAsByte<ECollisionChannel> AFGearVehicle::getTraceChannel() const {
    return ECC_WorldStatic;
}

bool AFGearVehicle::getTirePenetration() const {
    return false;
}

float AFGearVehicle::getSteerDeltaAngle(bool front) const {
    return 0.0f;
}

UFGearStandardInput* AFGearVehicle::getStandardInput() const {
    return NULL;
}

float AFGearVehicle::getSleepWaitingTime() const {
    return 0.0f;
}

float AFGearVehicle::getSleepLinearThreshold() const {
    return 0.0f;
}

float AFGearVehicle::getSleepAngularThreshold() const {
    return 0.0f;
}

float AFGearVehicle::getSimCoeff() const {
    return 0.0f;
}

FQuat AFGearVehicle::getRotation() const {
    return FQuat{};
}

float AFGearVehicle::getRollingResistanceCoeff() const {
    return 0.0f;
}

float AFGearVehicle::getRightSpeed() const {
    return 0.0f;
}

float AFGearVehicle::getReverseBrakeSpeed() const {
    return 0.0f;
}

bool AFGearVehicle::getRelaxationDownforce() const {
    return false;
}

int32 AFGearVehicle::getRayCount() const {
    return 0;
}

FGearQueryType AFGearVehicle::getQueryType() const {
    return FGearQueryType::Line;
}

FGearQueryMobilityType AFGearVehicle::getQueryMobilityType() const {
    return FGearQueryMobilityType::Any;
}

FVector AFGearVehicle::GetPosition() const {
    return FVector{};
}

float AFGearVehicle::getOptimumSlipWeight() const {
    return 0.0f;
}

float AFGearVehicle::getNormalizedSteering() const {
    return 0.0f;
}

FVector AFGearVehicle::getMyVelocity() const {
    return FVector{};
}

float AFGearVehicle::getMinWheelKMHSpeed(bool onlyPowered) const {
    return 0.0f;
}

float AFGearVehicle::getMinAbsSpeed() const {
    return 0.0f;
}

UFGearSkeletalMeshComponent* AFGearVehicle::getMesh() const {
    return NULL;
}

float AFGearVehicle::getMaxWheelRPMToKMH() const {
    return 0.0f;
}

float AFGearVehicle::getMaxWheelKMHSpeed(bool onlyPowered, bool absValue) const {
    return 0.0f;
}

float AFGearVehicle::getMaxSteeringAngle() const {
    return 0.0f;
}

float AFGearVehicle::getMassPerWheel() const {
    return 0.0f;
}

float AFGearVehicle::GetMass() const {
    return 0.0f;
}

FVector AFGearVehicle::getLocalInertiaTensor() const {
    return FVector{};
}

int32 AFGearVehicle::getLateralRayCount() const {
    return 0;
}

float AFGearVehicle::getKMHSpeed() const {
    return 0.0f;
}

bool AFGearVehicle::getIsSleeping() const {
    return false;
}

FVector AFGearVehicle::getInertiaScale() const {
    return FVector{};
}

uint8 AFGearVehicle::getIgnoreMask() const {
    return 0;
}

float AFGearVehicle::getHardContactScale() const {
    return 0.0f;
}

float AFGearVehicle::getHandbrakePower() const {
    return 0.0f;
}

float AFGearVehicle::getForwardSpeed() const {
    return 0.0f;
}

FVector AFGearVehicle::getForwardDir() const {
    return FVector{};
}

bool AFGearVehicle::getESPActive() const {
    return false;
}

UFGearEngine* AFGearVehicle::getEngine() const {
    return NULL;
}

float AFGearVehicle::getDrivetrainInertia() const {
    return 0.0f;
}

float AFGearVehicle::getDrivetrainFriction() const {
    return 0.0f;
}

bool AFGearVehicle::getDetectGround() const {
    return false;
}

FVector AFGearVehicle::GetCenterOfMass() const {
    return FVector{};
}

float AFGearVehicle::getAxleDistance(int32 axle1, int32 axle2) const {
    return 0.0f;
}

int32 AFGearVehicle::getAxleCount() const {
    return 0;
}

UFGearAxle* AFGearVehicle::getAxle(int32 I) const {
    return NULL;
}

bool AFGearVehicle::getASRActive() const {
    return false;
}

float AFGearVehicle::getASR() const {
    return 0.0f;
}

UFGearAnimInstance* AFGearVehicle::getAnim() const {
    return NULL;
}

bool AFGearVehicle::getAllowReverse() const {
    return false;
}

UFGearAeroDynamics* AFGearVehicle::getAeroDynamics() const {
    return NULL;
}

bool AFGearVehicle::getABSActive() const {
    return false;
}

float AFGearVehicle::getABS() const {
    return 0.0f;
}

void AFGearVehicle::ClientReset_Implementation(FVector Position, FQuat Rotation) {
}

void AFGearVehicle::clientPrepareTelemetry_Implementation() {
}

void AFGearVehicle::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(AFGearVehicle, mInSleep);
}


