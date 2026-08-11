#pragma once
#include "CoreMinimal.h"
#include "FGearTelemetryDrawer.h"
#include "GearPID.h"
#include "FGearArcadeAssists.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class FGEARPLUGIN_API UFGearArcadeAssists : public UFGearTelemetryDrawer {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool mRecoverAssists;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mUnderSteerRecoverPower;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mOverSteerRecoverPower;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mMinRecoverAssistSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mFullRecoverAssistSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool mAntirollBars;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mFrontAntiRollPower;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mRearAntiRollPower;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool mTractionAssist;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mTractionAssistRatio;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mTractionAssistMaxSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool mDriftAssist;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mDriftAssistFrontRatio;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mDriftAssistRearRatio;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool mTorqueSplitter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mTorqueSplitterRatio;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mTorqueSplitterResponseTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool mBikeHelper;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mAntiRollSpring;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mDamperSmooth;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mMinLeanSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mMaxLeanAngle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mMaxPitchAngle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool mLeanInAir;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool mCruiseControl;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mCruiseSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGearPID mCruiseControlPID;
    
public:
    UFGearArcadeAssists(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void setTractionAssist(bool Enable);
    
    UFUNCTION(BlueprintCallable)
    void setTorqueSplitter(bool Enable);
    
    UFUNCTION(BlueprintCallable)
    void setRecoverAssists(bool Enable);
    
    UFUNCTION(BlueprintCallable)
    void setMinLeanSpeed(float V);
    
    UFUNCTION(BlueprintCallable)
    void setMaxPitchAngle(float V);
    
    UFUNCTION(BlueprintCallable)
    void setMaxLeanAngle(float V);
    
    UFUNCTION(BlueprintCallable)
    void setLeanInAir(bool Enable);
    
    UFUNCTION(BlueprintCallable)
    void setInstantSpeed(float kmhSpeed, int32 gear);
    
    UFUNCTION(BlueprintCallable)
    void setDriftAssist(bool Enable);
    
    UFUNCTION(BlueprintCallable)
    void setDamperSmooth(float V);
    
    UFUNCTION(BlueprintCallable)
    void setCruiseControl(bool Active, float kmhSpeed);
    
    UFUNCTION(BlueprintCallable)
    void setBikeHelper(bool Enable);
    
    UFUNCTION(BlueprintCallable)
    void setAntiRollSpring(float V);
    
    UFUNCTION(BlueprintCallable)
    void setAntirollBars(bool Enable);
    
};

