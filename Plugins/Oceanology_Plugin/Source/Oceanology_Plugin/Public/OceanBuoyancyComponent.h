#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "Components/ActorComponent.h"
#include "OceanBuoyancyPontoon.h"
#include "OceanOnEnteredWaterDelegate.h"
#include "OceanOnExitedWaterDelegate.h"
#include "OceanBuoyancyComponent.generated.h"

class AOceanologyWaterParent;
class AOceanologyWaterVolume;
class UCharacterMovementComponent;
class UPrimitiveComponent;
class USplineComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class OCEANOLOGY_PLUGIN_API UOceanBuoyancyComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BuoyancyUpdateInterval;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double DefaultMeshDensity;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double WaterFluidDensity;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double WaterFluidLinearDamping;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double WaterFluidAngularDamping;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector WaterVelocityDamper;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool LimitUnderwaterMaxVelocity;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double MaxUnderwaterVelocity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FOceanBuoyancyPontoon> Pontoons;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double GlobalWaveForceMultiplier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool GlobalWaveForceEnabled;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double AngleAdjustedForceStrength;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool OrientMeshRotationYawTowardsFlowDirection;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool DebugEnabled;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor DebugSphereColorPontoons;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor DebugSphereColorBuoyancyLocation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor DebugSphereColorBuoyancyLocationUnderwater;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double DebugSphereRadiusMultiplier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    bool EnteredWaterVolume;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOceanOnEnteredWater OnEnteredWater;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOceanOnExitedWater OnExitedWater;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double CharacterMovementForceMultiplier;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double EnterExitWaterTolerance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    AOceanologyWaterParent* OceanologyWater;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    AOceanologyWaterVolume* OceanologyWaterVolume;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPrimitiveComponent* OwnerMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCharacterMovementComponent* CharacterMovement;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USplineComponent* FlowControlSpline;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    FVector CurrentWaveHeight;
    
public:
    UOceanBuoyancyComponent(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

    UFUNCTION(BlueprintCallable)
    void ToggleDebug();
    
    UFUNCTION(BlueprintCallable)
    void SetFlowControlSpline(USplineComponent* InFlowControlSpline, const double InUnscaledSplineWidth);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector GetVelocityAtLocation(const FVector& Point) const;
    
    UFUNCTION(BlueprintPure)
    double GetOwnerWaveHeightDistance() const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, BlueprintPure)
    UPrimitiveComponent* GetOwnerMesh() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    USplineComponent* GetFlowControlSpline() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector GetCurrentWaveHeight() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AOceanologyWaterVolume* GetCurrentWaterVolume() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AOceanologyWaterParent* GetCurrentWater() const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    UCharacterMovementComponent* GetCharacterMovement();
    
    UFUNCTION(BlueprintCallable)
    void DebugPontoons();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    void AddForceAtLocation(const FVector& Force, const FVector& Position) const;
    
};

