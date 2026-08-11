#pragma once
#include "CoreMinimal.h"
#include "FGearTelemetryDrawer.h"
#include "GearTransmissionSignatureDelegate.h"
#include "FGearTransmission.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class FGEARPLUGIN_API UFGearTransmission : public UFGearTelemetryDrawer {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGearTransmissionSignature OnGearChanged;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool mAutoChange;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool mAutoReverse;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool mAutoClutch;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool mRevMatching;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mChangeTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mGearUpRatio;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mGearDownRatio;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mGearUpVelocityBias;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mGearDownVelocityBias;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mClutchTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mClutchScale;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<float> mGearRatios;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mFinalGearRatio;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool mClutchAssist;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mClutchScaleMin;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mClutchScaleMax;
    
public:
    UFGearTransmission(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void setThrottleState(int32 ts);
    
    UFUNCTION(BlueprintCallable)
    void setRevMatching(bool B);
    
    UFUNCTION(BlueprintCallable)
    void setPauseTime(float F);
    
    UFUNCTION(BlueprintCallable)
    void setGearUpVelocityBias(float F);
    
    UFUNCTION(BlueprintCallable)
    void setGearUpRatio(float F);
    
    UFUNCTION(BlueprintCallable)
    void setGearRatio(int32 gear, float Ratio);
    
    UFUNCTION(BlueprintCallable)
    void setGearDownVelocityBias(float F);
    
    UFUNCTION(BlueprintCallable)
    void setGearDownRatio(float F);
    
    UFUNCTION(BlueprintCallable)
    void setGearCount(int32 Size);
    
    UFUNCTION(BlueprintCallable)
    void setFinalGearRatio(float F);
    
    UFUNCTION(BlueprintCallable)
    void setCurrentGear(int32 gear, bool Force);
    
    UFUNCTION(BlueprintCallable)
    void setClutchTime(float T);
    
    UFUNCTION(BlueprintCallable)
    void setClutchState(float cs);
    
    UFUNCTION(BlueprintCallable)
    void setClutchScale(float cs);
    
    UFUNCTION(BlueprintCallable)
    void setChangeTime(float T);
    
    UFUNCTION(BlueprintCallable)
    void setAutoReverse(bool B);
    
    UFUNCTION(BlueprintCallable)
    void setAutoClutch(bool B);
    
    UFUNCTION(BlueprintCallable)
    void setAutoChange(bool B);
    
    UFUNCTION(BlueprintCallable)
    void refreshParameters();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool isRevMatching() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool isChanging() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool isAutoReverse() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool isAutoClutch() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool isAutoChange() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getTransmissionRatio() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<float> getMaxSpeeds() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 getMaxGear() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getGearUpVelocityBias() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getGearUpRatio() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getGearRatio(int32 gear) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getGearMaxSpeed(int32 gear) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getGearDownVelocityBias() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getGearDownRatio() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 getGearCount() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getFinalGearRatio() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 getCurGear() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getClutchTime() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getClutchState() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getClutchScale() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getChangeTime() const;
    
    UFUNCTION(BlueprintCallable)
    void gearUp(bool skipN);
    
    UFUNCTION(BlueprintCallable)
    void gearDown(bool skipN);
    
};

