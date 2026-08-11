#pragma once
#include "CoreMinimal.h"
#include "Engine/NetSerialization.h"
#include "FGearInputState.h"
#include "FGearTelemetryDrawer.h"
#include "FGearReplication.generated.h"

class UCurveFloat;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class FGEARPLUGIN_API UFGearReplication : public UFGearTelemetryDrawer {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool mOverrideSettings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool mEnabled;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 mInputSendRate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 mStateSendRate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* mPositionError;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* mRotationError;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* mCollisionError;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mMinCollisionBlendSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mForceSnapDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    FFGearInputState mCurrentInput;
    
public:
    UFGearReplication(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

private:
    UFUNCTION(BlueprintCallable, Server, Unreliable)
    void serverReceiveState(float Time, FVector_NetQuantize100 Pos, FVector_NetQuantize100 rot, FVector_NetQuantize100 vel, FVector_NetQuantize100 avel);
    
    UFUNCTION(Server, Unreliable)
    void serverReceiveInputs(uint64 pckt);
    
public:
    UFUNCTION(BlueprintCallable)
    void resetCollisionTime(float thresholdTime);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsEnabled() const;
    
private:
    UFUNCTION(BlueprintCallable, NetMulticast, Unreliable)
    void clientReceiveState(float Time, FVector_NetQuantize100 Pos, FVector_NetQuantize100 rot, FVector_NetQuantize100 vel, FVector_NetQuantize100 avel);
    
};

