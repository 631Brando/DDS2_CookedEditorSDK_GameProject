#pragma once
#include "CoreMinimal.h"
#include "FGearTelemetryDrawer.h"
#include "FGearAeroDynamics.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class FGEARPLUGIN_API UFGearAeroDynamics : public UFGearTelemetryDrawer {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mDragCoefficient;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mDownForceCoefficient;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mDownForceXOffset;
    
public:
    UFGearAeroDynamics(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void setDragCoefficient(float F);
    
    UFUNCTION(BlueprintCallable)
    void setDownForceXOffset(float F);
    
    UFUNCTION(BlueprintCallable)
    void setDownForceCoefficient(float F);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getDragCoefficient() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getDownForceXOffset() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getDownForceCoefficient() const;
    
};

