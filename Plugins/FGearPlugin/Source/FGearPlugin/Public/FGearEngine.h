#pragma once
#include "CoreMinimal.h"
#include "FGearTelemetryDrawer.h"
#include "FGearEngine.generated.h"

class UCurveFloat;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class FGEARPLUGIN_API UFGearEngine : public UFGearTelemetryDrawer {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* mTorqueCurve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mTorqueScale;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mFrictionTorque;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mIdleRpm;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mLimitRpm;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mLimiterTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mEngineInertia;
    
public:
    UFGearEngine(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void setTorqueScale(float F);
    
    UFUNCTION(BlueprintCallable)
    void setTorqueCurve(UCurveFloat* Curve);
    
    UFUNCTION(BlueprintCallable)
    void setThrottle(float pedal);
    
    UFUNCTION(BlueprintCallable)
    void setRunning(bool B);
    
    UFUNCTION(BlueprintCallable)
    void setRpm(float F);
    
    UFUNCTION(BlueprintCallable)
    void setLimitRpm(float F);
    
    UFUNCTION(BlueprintCallable)
    void setLimiterTime(float F);
    
    UFUNCTION(BlueprintCallable)
    void setLimiter(float L);
    
    UFUNCTION(BlueprintCallable)
    void setIdleRpm(float F);
    
    UFUNCTION(BlueprintCallable)
    void setFrictionTorque(float F);
    
    UFUNCTION(BlueprintCallable)
    void setEngineInertia(float F);
    
    UFUNCTION(BlueprintCallable)
    void resetRpm();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsRunning() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool isLimiterOn() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getTorqueScale() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UCurveFloat* getTorqueCurve() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getTorque() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getThrottle() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getRpmRatio() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getRPM() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getLimitRpm() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getLimiterTime() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getIdleRpm() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getFrictionTorque() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getEngineInertia() const;
    
    UFUNCTION(BlueprintCallable)
    void calculatePeakTorqueRpm();
    
    UFUNCTION(BlueprintCallable)
    void calculateMaxPower(float& maxPower, float& maxPowerRpm);
    
};

