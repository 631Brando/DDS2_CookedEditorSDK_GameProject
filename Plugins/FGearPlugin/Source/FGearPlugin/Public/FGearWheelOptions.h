#pragma once
#include "CoreMinimal.h"
#include "FGearTelemetryDrawer.h"
#include "Templates/SubclassOf.h"
#include "FGearWheelOptions.generated.h"

class UFGearTire;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class FGEARPLUGIN_API UFGearWheelOptions : public UFGearTelemetryDrawer {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UFGearTire> mTireModelClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UFGearTire* mTireModel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mLateralFriction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mLongitudinalFriction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mLateralScale;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mLongitudinalScale;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mOverturnScale;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mRollMomentScale;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mSelfAlignScale;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mTirePressure;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mWidth;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mForwardOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mSpacerOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mRimOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mCastOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mMass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mBrakeTorque;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mSuspensionUpTravel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mSuspensionDownTravel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mSuspensionSpring;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mCompressionDamper;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mRelaxationDamper;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mSuspensionPreload;
    
public:
    UFGearWheelOptions(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void setWidth(float F);
    
    UFUNCTION(BlueprintCallable)
    void setTirePressure(float F);
    
    UFUNCTION(BlueprintCallable)
    void setTireModel(UFGearTire* T);
    
    UFUNCTION(BlueprintCallable)
    void setSuspensionUpTravel(float F);
    
    UFUNCTION(BlueprintCallable)
    void setSuspensionSpring(float F);
    
    UFUNCTION(BlueprintCallable)
    void setSuspensionPreload(float F);
    
    UFUNCTION(BlueprintCallable)
    void setSuspensionDownTravel(float F);
    
    UFUNCTION(BlueprintCallable)
    void setSpacerOffset(float F);
    
    UFUNCTION(BlueprintCallable)
    void setSelfAlignScale(float F);
    
    UFUNCTION(BlueprintCallable)
    void setRollMomentScale(float F);
    
    UFUNCTION(BlueprintCallable)
    void setRimOffset(float F);
    
    UFUNCTION(BlueprintCallable)
    void setRelaxationDamper(float F);
    
    UFUNCTION(BlueprintCallable)
    void SetRadius(float F);
    
    UFUNCTION(BlueprintCallable)
    void setOverturnScale(float F);
    
    UFUNCTION(BlueprintCallable)
    void setMass(float F);
    
    UFUNCTION(BlueprintCallable)
    void setLongitudinalScale(float F);
    
    UFUNCTION(BlueprintCallable)
    void setLongitudinalFriction(float F);
    
    UFUNCTION(BlueprintCallable)
    void setLateralScale(float F);
    
    UFUNCTION(BlueprintCallable)
    void setLateralFriction(float F);
    
    UFUNCTION(BlueprintCallable)
    void setForwardOffset(float F);
    
    UFUNCTION(BlueprintCallable)
    void setCompressionDamper(float F);
    
    UFUNCTION(BlueprintCallable)
    void setCastOffset(float F);
    
    UFUNCTION(BlueprintCallable)
    void setBrakeTorque(float F);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetWidth() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getTirePressure() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UFGearTire* getTireModel() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getSuspensionUpTravel() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getSuspensionSpring() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getSuspensionPreload() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getSuspensionDownTravel() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getSpacerOffset() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getSelfAlignScale() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getRollMomentScale() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getRimOffset() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getRelaxationDamper() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getRadius() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getOverturnScale() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetMass() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getLongitudinalScale() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getLongitudinalFriction() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getLateralScale() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getLateralFriction() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getForwardOffset() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getCompressionDamper() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getCastOffset() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getBrakeTorque() const;
    
};

