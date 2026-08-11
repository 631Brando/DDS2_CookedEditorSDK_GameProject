#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FGearDifferentialType.h"
#include "FGearTelemetryDrawer.h"
#include "FGearAxle.generated.h"

class UFGearWheel;
class UFGearWheelOptions;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class FGEARPLUGIN_API UFGearAxle : public UFGearTelemetryDrawer {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGearDifferentialType mDifferentialType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mDiffStrength;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mTorqueShare;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mMaxSteerAngle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mAckermanCoeff;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 mAckermanReferenceIndex;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool mHasHandbrake;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mCamberAngle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mToeAngle;
    
public:
    UFGearAxle(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void setWheelOptions(UFGearWheelOptions* wo);
    
    UFUNCTION(BlueprintCallable)
    void setTorqueShare(float F);
    
    UFUNCTION(BlueprintCallable)
    void setToeAngle(float F);
    
    UFUNCTION(BlueprintCallable)
    void setTargetSteer(float S);
    
    UFUNCTION(BlueprintCallable)
    void setRightWheel(UFGearWheel* W);
    
    UFUNCTION(BlueprintCallable)
    void setMaxSteerAngle(float F);
    
    UFUNCTION(BlueprintCallable)
    void setLeftWheel(UFGearWheel* W);
    
    UFUNCTION(BlueprintCallable)
    void setHasHandBrake(bool B);
    
    UFUNCTION(BlueprintCallable)
    void setDiffStrength(float F);
    
    UFUNCTION(BlueprintCallable)
    void setDifferentialType(FGearDifferentialType dt);
    
    UFUNCTION(BlueprintCallable)
    void setCamberAngle(float F);
    
    UFUNCTION(BlueprintCallable)
    void setAckermanReferenceIndex(int32 I);
    
    UFUNCTION(BlueprintCallable)
    void setAckermanCoeff(float F);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool hasSteering() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool hasHandBrake() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getWheelRPMToKMH() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UFGearWheelOptions* getWheelOptions() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getTrackWidth() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getTorqueShare() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getToeAngle() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getRPM() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UFGearWheel* getRightWheel() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getNormalizedSteering() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getMaxSteerAngle() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getMaxRpm() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector getLocalCenter() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UFGearWheel* getLeftWheel() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getKMHSpeed() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 getIndex() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector getGlobalCenter() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getFeedbackTorque() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getDrivetrainFriction() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getDiffStrength() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FGearDifferentialType getDifferentialType() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getCurRpm() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getCamberAngle() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 getAckermanReferenceIndex() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getAckermanCoeff() const;
    
    UFUNCTION(BlueprintCallable)
    void applyWheelOptions();
    
};

