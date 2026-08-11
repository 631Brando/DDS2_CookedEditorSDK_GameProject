#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Components/ActorComponent.h"
#include "EOceanologyWaveTimeMode.h"
#include "OceanologyWaterPresetResult.h"
#include "OceanologyWaveSolverComponent.generated.h"

class AOceanologyWaterParent;
class UMaterialParameterCollection;

UCLASS(Abstract, Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class OCEANOLOGY_PLUGIN_API UOceanologyWaveSolverComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EOceanologyWaveTimeMode WaveTimeMode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float WaveSolverUpdateInterval;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    AOceanologyWaterParent* Owner;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialParameterCollection* MPC_Waves;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double GameTimeInSeconds;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool SimulateWaves;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AOceanologyWaterParent* FirstWaterInstance;
    
public:
    UOceanologyWaveSolverComponent(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void UpdateWavesByPresetResult(AOceanologyWaterParent* Water, const FOceanologyWaterPresetResult& WaterPresetResult);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void UpdateWaves();
    
    UFUNCTION(BlueprintCallable)
    void StopWaveSimulation();
    
    UFUNCTION(BlueprintCallable)
    void StartWaveSimulation();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsUsingMPC_Waves() const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void InitWaves(AOceanologyWaterParent* InOwner, const bool InUsingMPC_Waves);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, BlueprintPure)
    FVector GetWaveHeightAtLocation(const FVector& Location);
    
    UFUNCTION(BlueprintNativeEvent, BlueprintPure)
    double GetMinWaveHeight();
    
    UFUNCTION(BlueprintNativeEvent, BlueprintPure)
    double GetMaxWaveHeight();
    
    UFUNCTION(BlueprintNativeEvent, BlueprintPure)
    double GetGlobalWaveDirection();
    
};

