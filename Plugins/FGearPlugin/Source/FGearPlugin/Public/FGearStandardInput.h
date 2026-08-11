#pragma once
#include "CoreMinimal.h"
#include "FGearControllerType.h"
#include "FGearInputSystemType.h"
#include "FGearShifterType.h"
#include "FGearTelemetryDrawer.h"
#include "FGearStandardInput.generated.h"

class UCurveFloat;
class UInputAction;
class UInputComponent;
class UInputMappingContext;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class FGEARPLUGIN_API UFGearStandardInput : public UFGearTelemetryDrawer {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool mEnabled;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGearInputSystemType mInputType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool mCombinedAxis;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGearControllerType mControllerType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGearShifterType mShifterType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName mVerticalAxis;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName mHorizontalAxis;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName mThrottleAxis;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName mBrakeAxis;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName mLeftAxis;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName mRightAxis;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName mClutchAxis;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName mHandbrakeAxis;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName mShiftAxis;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName mShift1Axis;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName mShift2Axis;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName mShift3Axis;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName mShift4Axis;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName mShift5Axis;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName mShift6Axis;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName mShiftRAxis;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mSteerSensivity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* mSteerSpeedCurve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* mSteerLimitCurve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mSteerInputGravity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mSteerRange;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mSteerDeadzone;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mSteeringAssist;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mSteeringAssistThresholdAngle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mThrottleSensivity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mThrottleRange;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mThrottleDeadzone;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* mThrottleEngagement;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mBrakingSensivity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mBrakingRange;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mBrakingDeadzone;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* mBrakeEngagement;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mClutchSensivity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mClutchRange;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mClutchDeadzone;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* mClutchEngagement;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInputMappingContext* mDefaultMappingContext;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInputAction* mVerticalAction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInputAction* mHorizontalAction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInputAction* mThrottleAction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInputAction* mBrakeAction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInputAction* mLeftAction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInputAction* mRightAction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInputAction* mClutchAction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInputAction* mHandbrakeAction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInputAction* mShiftAction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInputAction* mShift1Action;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInputAction* mShift2Action;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInputAction* mShift3Action;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInputAction* mShift4Action;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInputAction* mShift5Action;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInputAction* mShift6Action;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInputAction* mShiftRAction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, NoClear, meta=(AllowPrivateAccess=true))
    UInputComponent* mInputComp;
    
public:
    UFGearStandardInput(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void setVerticalAxis(FName S);
    
    UFUNCTION(BlueprintCallable)
    void setVerticalAction(UInputAction* ia);
    
    UFUNCTION(BlueprintCallable)
    void setThrottleSensivity(float F);
    
    UFUNCTION(BlueprintCallable)
    void setThrottleRange(float F);
    
    UFUNCTION(BlueprintCallable)
    void setThrottleEngagementCurve(UCurveFloat* C);
    
    UFUNCTION(BlueprintCallable)
    void setThrottleDeadzone(float F);
    
    UFUNCTION(BlueprintCallable)
    void setThrottleAxis(FName S);
    
    UFUNCTION(BlueprintCallable)
    void setThrottleAction(UInputAction* ia);
    
    UFUNCTION(BlueprintCallable)
    void setSteerSpeedCurve(UCurveFloat* C);
    
    UFUNCTION(BlueprintCallable)
    void setSteerSensivity(float F);
    
    UFUNCTION(BlueprintCallable)
    void setSteerRange(float F);
    
    UFUNCTION(BlueprintCallable)
    void setSteerLimitCurve(UCurveFloat* C);
    
    UFUNCTION(BlueprintCallable)
    void setSteerInputGravity(float F);
    
    UFUNCTION(BlueprintCallable)
    void setSteeringAssistThresholdAngle(float F);
    
    UFUNCTION(BlueprintCallable)
    void setSteeringAssist(float F);
    
    UFUNCTION(BlueprintCallable)
    void setSteerDeadzone(float F);
    
    UFUNCTION(BlueprintCallable)
    void setStartGridMode(bool B);
    
    UFUNCTION(BlueprintCallable)
    void setShiftRAxis(FName S);
    
    UFUNCTION(BlueprintCallable)
    void setShiftRAction(UInputAction* ia);
    
    UFUNCTION(BlueprintCallable)
    void setShifterType(FGearShifterType st);
    
    UFUNCTION(BlueprintCallable)
    void setShiftAxis(FName S);
    
    UFUNCTION(BlueprintCallable)
    void setShiftAction(UInputAction* ia);
    
    UFUNCTION(BlueprintCallable)
    void setShift6Axis(FName S);
    
    UFUNCTION(BlueprintCallable)
    void setShift6Action(UInputAction* ia);
    
    UFUNCTION(BlueprintCallable)
    void setShift5Axis(FName S);
    
    UFUNCTION(BlueprintCallable)
    void setShift5Action(UInputAction* ia);
    
    UFUNCTION(BlueprintCallable)
    void setShift4Axis(FName S);
    
    UFUNCTION(BlueprintCallable)
    void setShift4Action(UInputAction* ia);
    
    UFUNCTION(BlueprintCallable)
    void setShift3Axis(FName S);
    
    UFUNCTION(BlueprintCallable)
    void setShift3Action(UInputAction* ia);
    
    UFUNCTION(BlueprintCallable)
    void setShift2Axis(FName S);
    
    UFUNCTION(BlueprintCallable)
    void setShift2Action(UInputAction* ia);
    
    UFUNCTION(BlueprintCallable)
    void setShift1Axis(FName S);
    
    UFUNCTION(BlueprintCallable)
    void setShift1Action(UInputAction* ia);
    
    UFUNCTION(BlueprintCallable)
    void setRightAxis(FName S);
    
    UFUNCTION(BlueprintCallable)
    void setRightAction(UInputAction* ia);
    
    UFUNCTION(BlueprintCallable)
    void setReadInputs(bool B);
    
    UFUNCTION(BlueprintCallable)
    void setLeftAxis(FName S);
    
    UFUNCTION(BlueprintCallable)
    void setLeftAction(UInputAction* ia);
    
    UFUNCTION(BlueprintCallable)
    void setInputs(float Throttle, float Brake, float steer, float Clutch, int32 gear, bool hb);
    
    UFUNCTION(BlueprintCallable)
    void setHorizontalAxis(FName S);
    
    UFUNCTION(BlueprintCallable)
    void setHorizontalAction(UInputAction* ia);
    
    UFUNCTION(BlueprintCallable)
    void setHandbrakeAxis(FName S);
    
    UFUNCTION(BlueprintCallable)
    void setHandbrakeAction(UInputAction* ia);
    
    UFUNCTION(BlueprintCallable)
    void SetEnabled(bool Enable, bool NewResetInputs);
    
    UFUNCTION(BlueprintCallable)
    void setDefaultMappingContext(UInputMappingContext* IMC);
    
    UFUNCTION(BlueprintCallable)
    void setControllerType(FGearControllerType ct);
    
    UFUNCTION(BlueprintCallable)
    void setCombinedAxis(bool B);
    
    UFUNCTION(BlueprintCallable)
    void setCluthEngagementCurve(UCurveFloat* C);
    
    UFUNCTION(BlueprintCallable)
    void setClutchSensivity(float F);
    
    UFUNCTION(BlueprintCallable)
    void setClutchRange(float F);
    
    UFUNCTION(BlueprintCallable)
    void setClutchDeadzone(float F);
    
    UFUNCTION(BlueprintCallable)
    void setClutchAxis(FName S);
    
    UFUNCTION(BlueprintCallable)
    void setClutchAction(UInputAction* ia);
    
    UFUNCTION(BlueprintCallable)
    void setBrakingSensivity(float F);
    
    UFUNCTION(BlueprintCallable)
    void setBrakingRange(float F);
    
    UFUNCTION(BlueprintCallable)
    void setBrakingDeadzone(float F);
    
    UFUNCTION(BlueprintCallable)
    void setBrakeEngagementCurve(UCurveFloat* C);
    
    UFUNCTION(BlueprintCallable)
    void setBrakeAxis(FName S);
    
    UFUNCTION(BlueprintCallable)
    void setBrakeAction(UInputAction* ia);
    
    UFUNCTION(BlueprintCallable)
    void resetInputs();
    
    UFUNCTION(BlueprintCallable)
    void overrideFinalInputs(float Throttle, float Brake, float steer, float Clutch, int32 gear, bool hb);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool isSteeringAssistActive() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsEnabled() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FName getVerticalAxis() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UInputAction* getVerticalAction() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getThrottleSensivity() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getThrottleRawInput() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getThrottleRange() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UCurveFloat* getThrottleEngagementCurve() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getThrottleDeadzone() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FName getThrottleAxis() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UInputAction* getThrottleAction() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UCurveFloat* getSteerSpeedCurve() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getSteerSensivity() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getSteerRawInput() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getSteerRange() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UCurveFloat* getSteerLimitCurve() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getSteerInputGravity() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getSteeringAssistThresholdAngle() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getSteeringAssist() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getSteerDeadzone() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FName getShiftRAxis() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UInputAction* getShiftRAction() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FGearShifterType getShifterType() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FName getShiftAxis() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UInputAction* getShiftAction() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FName getShift6Axis() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UInputAction* getShift6Action() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FName getShift5Axis() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UInputAction* getShift5Action() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FName getShift4Axis() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UInputAction* getShift4Action() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FName getShift3Axis() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UInputAction* getShift3Action() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FName getShift2Axis() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UInputAction* getShift2Action() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FName getShift1Axis() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UInputAction* getShift1Action() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FName getRightAxis() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UInputAction* getRightAction() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FName getLeftAxis() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UInputAction* getLeftAction() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FGearInputSystemType getInputSystemType() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FName getHorizontalAxis() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UInputAction* getHorizontalAction() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool getHandbrakeInput() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FName getHandbrakeAxis() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UInputAction* getHandbrakeAction() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 getGearboxInput() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UInputMappingContext* getDefaultMappingContext() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FGearControllerType getControllerType() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool getCombinedAxis() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UCurveFloat* getCluthEngagementCurve() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getClutchSensivity() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getClutchRawInput() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getClutchRange() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getClutchDeadzone() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FName getClutchAxis() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UInputAction* getClutchAction() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getBrakingSensivity() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getBrakingRange() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getBrakingDeadzone() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getBrakeRawInput() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UCurveFloat* getBrakeEngagementCurve() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FName getBrakeAxis() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UInputAction* getBrakeAction() const;
    
};

