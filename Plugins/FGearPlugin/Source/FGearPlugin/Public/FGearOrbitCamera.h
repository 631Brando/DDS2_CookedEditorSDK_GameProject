#pragma once
#include "CoreMinimal.h"
#include "FGearTelemetryDrawer.h"
#include "FGearOrbitCamera.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class FGEARPLUGIN_API UFGearOrbitCamera : public UFGearTelemetryDrawer {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool mDriftMode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool mFreeze;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mSpring;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mTargetZOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mTiltAngle;
    
public:
    UFGearOrbitCamera(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void setTiltAngle(float T);
    
    UFUNCTION(BlueprintCallable)
    void setTargetZOffset(float Z);
    
    UFUNCTION(BlueprintCallable)
    void setSpring(float S);
    
    UFUNCTION(BlueprintCallable)
    void setRotationOffset(float Angle);
    
    UFUNCTION(BlueprintCallable)
    void setOrbitMode(bool orbit);
    
    UFUNCTION(BlueprintCallable)
    void setFreeze(bool F);
    
    UFUNCTION(BlueprintCallable)
    void setDriftMode(bool dm);
    
    UFUNCTION(BlueprintCallable)
    void setDistance(float D);
    
    UFUNCTION(BlueprintCallable)
    void injectMouseDZ(float mz);
    
    UFUNCTION(BlueprintCallable)
    void injectMouseDY(float my);
    
    UFUNCTION(BlueprintCallable)
    void injectMouseDX(float mx);
    
};

