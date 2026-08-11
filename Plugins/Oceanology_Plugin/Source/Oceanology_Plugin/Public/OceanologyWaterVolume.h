#pragma once
#include "CoreMinimal.h"
#include "Engine/HitResult.h"
#include "GameFramework/PhysicsVolume.h"
#include "OceanologyWaterVolume.generated.h"

class AActor;
class AOceanologyWaterParent;
class UPrimitiveComponent;

UCLASS(Blueprintable)
class OCEANOLOGY_PLUGIN_API AOceanologyWaterVolume : public APhysicsVolume {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool DebugEnabled;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    AOceanologyWaterParent* OceanologyWater;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<AActor> BoundsAlignActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool CheckInitialOverlapOnBeginPlay;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double InitialOverlapOnBeginPlayDelay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool EnableBuoyancyInArea;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool EnableSwimmingInArea;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PhysicsVolumeTerminalVelocity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 PhysicsVolumePriority;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PhysicsVolumeFluidFriction;
    
    AOceanologyWaterVolume(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_ChangeOverlapStatus(const AActor* OtherActor, const bool Active);
    
    UFUNCTION(BlueprintCallable)
    void RegisterOverlapEvents();
    
    UFUNCTION(BlueprintCallable)
    void OnVolume_EndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
    
    UFUNCTION(BlueprintCallable)
    void OnVolume_BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
    
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void NetMulticast_ChangeOverlapStatus(const AActor* OtherActor, const bool Active);
    
    UFUNCTION(BlueprintCallable)
    void InitialOverlappingCheck();
    
};

