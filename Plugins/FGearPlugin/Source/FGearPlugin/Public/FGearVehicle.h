#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "Engine/EngineTypes.h"
#include "GameFramework/Pawn.h"
#include "FGearQueryMobilityType.h"
#include "FGearQueryType.h"
#include "FGearUpDirection.h"
#include "FGearVehicleState.h"
#include "GearInputSignatureDelegate.h"
#include "GearSleepSignatureDelegate.h"
#include "GearTelemetryOptions.h"
#include "GearWakeSignatureDelegate.h"
#include "FGearVehicle.generated.h"

class UFGearAeroDynamics;
class UFGearAnimInstance;
class UFGearArcadeAssists;
class UFGearAxle;
class UFGearEngine;
class UFGearOrbitCamera;
class UFGearReplication;
class UFGearSkeletalMeshComponent;
class UFGearStandardInput;
class UFGearSuspensionConstraint;
class UFGearTransmission;
class UFGearWheel;
class UFGearWheelOptions;
class UPrimitiveComponent;
class UStaticMesh;

UCLASS(Blueprintable)
class FGEARPLUGIN_API AFGearVehicle : public APawn {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGearSleepSignature onSleepEvent;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGearWakeSignature onWakeEvent;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGearInputSignature onOverrideInput;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UFGearEngine* mEngine;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UFGearTransmission* mTransmission;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UFGearStandardInput* mStandardInput;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UFGearAeroDynamics* mAeroDynamics;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, NoClear, meta=(AllowPrivateAccess=true))
    UFGearOrbitCamera* mOrbitCamera;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, NoClear, meta=(AllowPrivateAccess=true))
    UFGearArcadeAssists* mArcadeAssists;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, NoClear, meta=(AllowPrivateAccess=true))
    UFGearSuspensionConstraint* mSuspensionConstraint;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UFGearAxle* mAxle0;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UFGearWheelOptions* mWheelOptions0;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UFGearWheel* mWheelLeft0;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UFGearWheel* mWheelRight0;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UFGearAxle* mAxle1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UFGearWheelOptions* mWheelOptions1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UFGearWheel* mWheelLeft1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UFGearWheel* mWheelRight1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UFGearReplication* mReplication;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UFGearSkeletalMeshComponent* mMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UFGearAnimInstance* mAnimation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 mUpdateRate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mMass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector mInertiaScale;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector mCenterofMass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool mCustomGravity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector mGravity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGearQueryType mQueryType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 mRays;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 mLateralRays;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGearQueryMobilityType mQueryMobilityType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<ECollisionChannel> mTraceChannel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 mIgnoreMask;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool mTraceComplex;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStaticMesh* mConvexAsset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGearUpDirection mConvexUp;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRotator mConvexRotation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool mConvexVisible;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStaticMesh* mDefaultCylinderAsset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool mDetectGround;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool mAllowReverse;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool mTirePenetration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool mRelaxationDownforce;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mHardContactScale;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mHandBrakePower;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mReverseBrakeSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mRollingResistanceCoeff;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mDrivetrainInertia;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mDrivetrainFriction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mStickyTireSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mReactionScale;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mOptimumSlipWeight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGearTelemetryOptions mTelemetry;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mABS;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mMinAbsSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mASR;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mUnderSteerAssist;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mMinUnderSteerAngle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mOverSteerAssist;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mMinOverSteerAngle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mFrontAntiRollPower;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mRearAntiRollPower;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mSleepLinearThreshold;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mSleepAngularThreshold;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mSleepWaitingTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 mWakeUpSources;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=onRepInSleep, meta=(AllowPrivateAccess=true))
    bool mInSleep;
    
public:
    AFGearVehicle(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

    UFUNCTION(BlueprintCallable)
    void wakeUp();
    
    UFUNCTION(BlueprintCallable)
    void sleep();
    
    UFUNCTION(BlueprintCallable)
    void setUseCustomGravity(bool use);
    
    UFUNCTION(BlueprintCallable)
    void setUpdateRate(int32 I);
    
    UFUNCTION(BlueprintCallable)
    void setUpdateInputs(bool B);
    
    UFUNCTION(BlueprintCallable)
    void setUnderSteerAssist(float F);
    
    UFUNCTION(BlueprintCallable)
    void setTraceComplex(bool B);
    
    UFUNCTION(BlueprintCallable)
    void setTraceChannel(TEnumAsByte<ECollisionChannel> L);
    
    UFUNCTION(BlueprintCallable)
    void setTirePenetration(bool B);
    
    UFUNCTION(BlueprintCallable)
    void setStickyTireState(float F);
    
    UFUNCTION(BlueprintCallable)
    void setStickyTireSpeed(float F);
    
    UFUNCTION(BlueprintCallable)
    void setSteering(float steerInput);
    
    UFUNCTION(BlueprintCallable)
    void setSleepWaitingTime(const float Time);
    
    UFUNCTION(BlueprintCallable)
    void setSleepLinearThreshold(const float Threshold);
    
    UFUNCTION(BlueprintCallable)
    void setSleepAngularThreshold(const float Threshold);
    
    UFUNCTION(BlueprintCallable)
    void setRollingResistanceCoeff(float F);
    
    UFUNCTION(BlueprintCallable)
    void setReverseBrake(float F);
    
    UFUNCTION(BlueprintCallable)
    void setRelaxationDownforce(bool B);
    
    UFUNCTION(BlueprintCallable)
    void setRearAntiRollPower(float F);
    
    UFUNCTION(BlueprintCallable)
    void setReactionForceScale(float F);
    
    UFUNCTION(BlueprintCallable)
    void setRayCount(int32 ct);
    
    UFUNCTION(BlueprintCallable)
    void setQueryType(FGearQueryType T);
    
    UFUNCTION(BlueprintCallable)
    void setQueryMobilityType(FGearQueryMobilityType T);
    
    UFUNCTION(BlueprintCallable)
    void setOverSteerAssist(float F);
    
    UFUNCTION(BlueprintCallable)
    void setOptimumSlipWeight(float F);
    
    UFUNCTION(BlueprintCallable)
    void setMinUnderSteerAngle(float F);
    
    UFUNCTION(BlueprintCallable)
    void setMinOverSteerAngle(float F);
    
    UFUNCTION(BlueprintCallable)
    void setMinAbsSpeed(float F);
    
    UFUNCTION(BlueprintCallable)
    void setMass(float Mass);
    
    UFUNCTION(BlueprintCallable)
    void setLateralRayCount(int32 ct);
    
    UFUNCTION(BlueprintCallable)
    void setInertiaScale(FVector iscale);
    
    UFUNCTION(BlueprintCallable)
    void setIgnoreMask(uint8 F);
    
    UFUNCTION(BlueprintCallable)
    void setHardContactScale(float F);
    
    UFUNCTION(BlueprintCallable)
    void setHandbrakePower(float F);
    
    UFUNCTION(BlueprintCallable)
    void setGravity(FVector Gravity);
    
    UFUNCTION(BlueprintCallable)
    void setFrontAntiRollPower(float F);
    
    UFUNCTION(BlueprintCallable)
    void setDrivetrainInertia(float F);
    
    UFUNCTION(BlueprintCallable)
    void setDrivetrainFriction(float F);
    
    UFUNCTION(BlueprintCallable)
    void setDetectGround(bool B);
    
    UFUNCTION(BlueprintCallable)
    void setCenterOfMassOffset(FVector com);
    
    UFUNCTION(BlueprintCallable)
    void setBraking(float brakeInput, bool Handbrake);
    
    UFUNCTION(BlueprintCallable)
    void setASR(float F);
    
    UFUNCTION(BlueprintCallable)
    void setAllowReverse(bool allow);
    
    UFUNCTION(BlueprintCallable)
    void setABS(float F);
    
private:
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void serverWakeUp();
    
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void serverSleep();
    
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void serverReset(FVector Position, FQuat Rotation);
    
public:
    UFUNCTION(BlueprintCallable)
    void saveState(FFGearVehicleState& State);
    
    UFUNCTION(BlueprintCallable)
    void Reset(FVector Position, FRotator Rotation);
    
private:
    UFUNCTION(BlueprintCallable)
    void onWake(UPrimitiveComponent* Component, FName bone);
    
    UFUNCTION(BlueprintCallable)
    void onRepInSleep();
    
public:
    UFUNCTION(BlueprintCallable)
    void loadState(FFGearVehicleState State);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool isUnderSteering() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool isOverSteering() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool isHandbrakeOn() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getWheelSpeedLimitKMH() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 getWheelCount() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getVelocitySize() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector getVelocityDir() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector getUpDir() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 getUpdateRate() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UFGearTransmission* getTransmission() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool getTraceComplex() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TEnumAsByte<ECollisionChannel> getTraceChannel() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool getTirePenetration() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getSteerDeltaAngle(bool front) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UFGearStandardInput* getStandardInput() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getSleepWaitingTime() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getSleepLinearThreshold() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getSleepAngularThreshold() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getSimCoeff() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FQuat getRotation() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getRollingResistanceCoeff() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getRightSpeed() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getReverseBrakeSpeed() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool getRelaxationDownforce() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 getRayCount() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FGearQueryType getQueryType() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FGearQueryMobilityType getQueryMobilityType() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector GetPosition() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getOptimumSlipWeight() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getNormalizedSteering() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector getMyVelocity() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getMinWheelKMHSpeed(bool onlyPowered) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getMinAbsSpeed() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UFGearSkeletalMeshComponent* getMesh() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getMaxWheelRPMToKMH() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getMaxWheelKMHSpeed(bool onlyPowered, bool absValue) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getMaxSteeringAngle() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getMassPerWheel() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetMass() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector getLocalInertiaTensor() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 getLateralRayCount() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getKMHSpeed() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool getIsSleeping() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector getInertiaScale() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    uint8 getIgnoreMask() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getHardContactScale() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getHandbrakePower() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getForwardSpeed() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector getForwardDir() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool getESPActive() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UFGearEngine* getEngine() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getDrivetrainInertia() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getDrivetrainFriction() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool getDetectGround() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector GetCenterOfMass() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getAxleDistance(int32 axle1, int32 axle2) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 getAxleCount() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UFGearAxle* getAxle(int32 I) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool getASRActive() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getASR() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UFGearAnimInstance* getAnim() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool getAllowReverse() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UFGearAeroDynamics* getAeroDynamics() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool getABSActive() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getABS() const;
    
private:
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void ClientReset(FVector Position, FQuat Rotation);
    
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void clientPrepareTelemetry();
    
};

