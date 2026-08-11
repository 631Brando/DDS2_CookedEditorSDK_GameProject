#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/EngineTypes.h"
#include "CharacterMovementComponentAsync.h"
#include "Engine/TimerHandle.h"
#include "OceanOnDrownDeathDelegate.h"
#include "OceanOnDrowningTaskDelegate.h"
#include "OceanOnStartDrowningDelegate.h"
#include "OceanOnStartSwimmingDelegate.h"
#include "OceanOnStopDrowningDelegate.h"
#include "OceanOnUnderwaterEnterDelegate.h"
#include "OceanOnUnderwaterExitDelegate.h"
#include "OceanOnUnderwaterTaskDelegate.h"
#include "OceanSwimmingComponent.generated.h"

class AOceanologyWaterParent;
class AOceanologyWaterVolume;
class UCharacterMovementComponent;
class UMaterialInstanceDynamic;
class UNiagaraComponent;
class UNiagaraSystem;
class USoundBase;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class OCEANOLOGY_PLUGIN_API UOceanSwimmingComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SwimmingUpdateInterval;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName BuoyancyPontoonSocketForEnterWaterEvent;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double SwimmingBuoyancyForceMultiplier;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double Immersion;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double SwimUpLimiter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SwimMaxSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SwimFastMaxSpeed;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double SurfaceLockedSwimmingLimiter;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double EnterExitWaterToleranceOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool DrowningEnabled;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 DrowningTimeWarningInSeconds;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 DrowningTimeDeathInSeconds;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool EnableUnderwaterEffects;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UNiagaraSystem* HeadBubblesEffectNiagara;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName HeadSocketName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UNiagaraSystem* RightFootBubblesEffectNiagara;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UNiagaraSystem* LeftFootBubblesEffectNiagara;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName RightFootSocketName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName LeftFootSocketName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool StopHeadBubblesWhileSwimFast;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool StopRightFootBubblesWhileSwimFast;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool StopLeftFootBubblesWhileSwimFast;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UNiagaraSystem* SwimFastTrailEffectNiagara;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName SwimFastTrailSocketName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundBase* SwimFastTrailSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool DebugEnabled;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    bool EnteredWaterVolume;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    bool EnteredWater;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    bool Submerged;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    bool Swimming;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    int32 UnderwaterTimeCounter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    bool UnderwaterTaskRunning;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    int32 DrowningTimeCounter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    bool DrowningTaskRunning;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    bool DrownedToDeath;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    bool SurfaceLockedSwimming;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    bool SwimDown;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    bool SwimUp;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    bool SwimFast;
    
    UPROPERTY(EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    double SwimUpOrDownAxis;
    
    UPROPERTY(EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    double LookUpAxis;
    
    UPROPERTY(EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    double MoveForwardBackwardAxis;
    
    UPROPERTY(EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    double MoveLeftRightAxis;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool SwimmingOrientRotationToMovement;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool SwimmingUseControllerRotationYaw;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOceanOnStartSwimming OnStartSwimming;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOceanOnStartSwimming OnStopSwimming;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOceanOnUnderwaterTask OnUnderwaterTask;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOceanOnUnderwaterEnter OnUnderwaterEnter;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOceanOnUnderwaterExit OnUnderwaterExit;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOceanOnStartDrowning OnStartDrowning;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOceanOnStopDrowning OnStopDrowning;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOceanOnDrowningTask OnDrowningTask;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOceanOnDrownDeath OnDrownDeath;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    AOceanologyWaterParent* OceanologyWater;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    AOceanologyWaterVolume* OceanologyWaterVolume;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    FFindFloorResult FindFloorResult;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    float OriginalMaxWalkSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    float OriginalMaxSwimSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    bool OriginalOrientRotationToMovement;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    bool OriginalUseControllerRotationYaw;
    
    UPROPERTY(EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    double OriginalBuoyancy;
    
    UPROPERTY(EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    double EffectiveSwimmingBuoyancyForce;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    bool EffectiveSurfaceLockedSwimming;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    TEnumAsByte<EMovementMode> LastMovementMode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTimerHandle UnderwaterTaskDelegate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTimerHandle DrowningTaskDelegate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UNiagaraComponent* HeadBubblesEffect;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UNiagaraComponent* RightFootBubblesEffect;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UNiagaraComponent* LeftFootBubblesEffect;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UNiagaraComponent* SwimFastTrailEffect;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UMaterialInstanceDynamic* SwimmingBubblesMID;
    
public:
    UOceanSwimmingComponent(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

private:
    UFUNCTION(BlueprintCallable)
    void UnderwaterTask();
    
public:
    UFUNCTION(BlueprintCallable)
    void ToggleDebug();
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void Server_SwimUpOrDown(const bool Value, const double AxisValue);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void Server_SwimFast(const bool Value);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void Server_SurfaceLockedSwimming(const bool Value);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void Server_MoveLeftRight(const double AxisValue);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void Server_MoveForwardBackward(const double AxisValue);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void Server_LookUp(const double AxisValue);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnExitedWater(const FName Socket, const bool Underwater);
    
    UFUNCTION(BlueprintCallable)
    void OnEnteredWater(const FName Socket, const bool Underwater);
    
public:
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void NetMulticast_SwimUpOrDown(const bool Value, const double AxisValue);
    
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void NetMulticast_SwimFast(const bool Value);
    
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void NetMulticast_SurfaceLockedSwimming(const bool Value);
    
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void NetMulticast_MoveLeftRight(const double AxisValue);
    
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void NetMulticast_MoveForwardBackward(const double AxisValue);
    
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void NetMulticast_LookUp(const double AxisValue);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsSurfaceLockedSwimming() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AOceanologyWaterVolume* GetCurrentWaterVolume() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AOceanologyWaterParent* GetCurrentWater() const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    UCharacterMovementComponent* GetCharacterMovement();
    
private:
    UFUNCTION(BlueprintCallable)
    void DrownToDeath();
    
    UFUNCTION(BlueprintCallable)
    void DrowningTask();
    
protected:
    UFUNCTION(BlueprintCallable)
    void ComputeWaterFloorHeight();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool CanStopSwim();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool CanStartSwim();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool CanExitWater(const FName Socket, const bool Underwater);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool CanEnterWater(const FName Socket, const bool Underwater);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool CanAlterState();
    
};

