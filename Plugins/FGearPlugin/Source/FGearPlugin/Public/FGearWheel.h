#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "Engine/HitResult.h"
#include "FGearTelemetryDrawer.h"
#include "FGearWheelSide.h"
#include "FGearWheel.generated.h"

class UFGearAxle;
class UStaticMeshComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class FGEARPLUGIN_API UFGearWheel : public UFGearTelemetryDrawer {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool mIsActive;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGearWheelSide mSide;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName mBoneName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* mConvexShape;
    
public:
    UFGearWheel(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void setWidth(float F);
    
    UFUNCTION(BlueprintCallable)
    void setWheelSide(FGearWheelSide S);
    
    UFUNCTION(BlueprintCallable)
    void setSuspensionUpTravel(float F);
    
    UFUNCTION(BlueprintCallable)
    void setSuspensionSpring(float F);
    
    UFUNCTION(BlueprintCallable)
    void setSuspensionPreload(float F);
    
    UFUNCTION(BlueprintCallable)
    void setSuspensionDownTravel(float F);
    
    UFUNCTION(BlueprintCallable)
    void setSpringCoeff(float F);
    
    UFUNCTION(BlueprintCallable)
    void SetSpeed(float S);
    
    UFUNCTION(BlueprintCallable)
    void setRollScale(float F);
    
    UFUNCTION(BlueprintCallable)
    void setRelaxationDamper(float F);
    
    UFUNCTION(BlueprintCallable)
    void SetRadius(float F);
    
    UFUNCTION(BlueprintCallable)
    void setPressure(float F);
    
    UFUNCTION(BlueprintCallable)
    void setOverturnScale(float F);
    
    UFUNCTION(BlueprintCallable)
    void setMass(float F);
    
    UFUNCTION(BlueprintCallable)
    void setLngScale(float F);
    
    UFUNCTION(BlueprintCallable)
    void setLngFriction(float F);
    
    UFUNCTION(BlueprintCallable)
    void setLatScale(float F);
    
    UFUNCTION(BlueprintCallable)
    void setLatFriction(float F);
    
    UFUNCTION(BlueprintCallable)
    void setLateralOffsets(float Forward, float Spacer, float rim);
    
    UFUNCTION(BlueprintCallable)
    void setInherentDrag(float F);
    
    UFUNCTION(BlueprintCallable)
    void setFrictionFactor(float F);
    
    UFUNCTION(BlueprintCallable)
    void setEnable(bool B);
    
    UFUNCTION(BlueprintCallable)
    void setCurrentSteer(float S);
    
    UFUNCTION(BlueprintCallable)
    void setCompressionDamper(float F);
    
    UFUNCTION(BlueprintCallable)
    void setBraking(float B);
    
    UFUNCTION(BlueprintCallable)
    void setBrakeTorque(float F);
    
    UFUNCTION(BlueprintCallable)
    void setBoneName(const FString& NewName);
    
    UFUNCTION(BlueprintCallable)
    void setAlignScale(float F);
    
    UFUNCTION(BlueprintCallable)
    void setAdditionalDrag(float F);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsEnabled() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool isASRActive() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool isABSActive() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool hasDrive() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool hasContact() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FGearWheelSide getWheelSide() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getWheelRPMToKMH() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FQuat getWheelRotation() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector getWheelPosition() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getSuspensionTotalLength() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getSuspensionSpring() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getSuspensionCompressRatio() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getSuspensionCompressedLength() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getSpeed() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getSlipRatio() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getSlipAngle() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getRPM() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FHitResult getRayHit() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getRadius() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getPressure() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getPitch() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getLongitudinalSlip() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector getLongitudinalForce() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector getLocalHubPosition() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getLateralSlip() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector getLateralForce() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getKMHSpeed() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getInherentDrag() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector getHubPosition() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getGroundSpeed() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getGroundRpm() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector getGlobalRight() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector getGlobalForward() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getFrictionFactor() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getFeedbackTorque() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getCurrentSteer() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getCurrentLoad() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector getCombinedTorque() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getBraking() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UFGearAxle* getAxle() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getAdditionalDrag() const;
    
};

