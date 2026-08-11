#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "EOceanologyGerstnerWaveSummarize.h"
#include "OceanologyBaseOffset.h"
#include "OceanologyGlobalDisplacement.h"
#include "OceanologyLakePresetResult.h"
#include "OceanologyOceanPresetResult.h"
#include "OceanologyWaterPresetResult.h"
#include "OceanologyWaveSolverComponent.h"
#include "OceanologyWave_1.h"
#include "OceanologyWave_2.h"
#include "OceanologyWave_3.h"
#include "OceanologyWave_4.h"
#include "OceanologyGerstnerWaveSolverComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class OCEANOLOGY_PLUGIN_API UOceanologyGerstnerWaveSolverComponent : public UOceanologyWaveSolverComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    FOceanologyGlobalDisplacement GlobalDisplacement;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    FOceanologyBaseOffset BaseOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    FOceanologyWave_1 Wave_1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    FOceanologyWave_2 Wave_2;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    FOceanologyWave_3 Wave_3;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    FOceanologyWave_4 Wave_4;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    EOceanologyGerstnerWaveSummarize Summarize;
    
    UOceanologyGerstnerWaveSolverComponent(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void UpdateOceanWavesByPresetResult(const FOceanologyWaterPresetResult& WaterPresetResult, const FOceanologyOceanPresetResult& OceanPresetResult);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void UpdateLakeWavesByPresetResult(const FOceanologyWaterPresetResult& WaterPresetResult, const FOceanologyLakePresetResult& LakePresetResult);
    
    UFUNCTION(BlueprintPure)
    static double MultiplyWave(const double Value);
    
    UFUNCTION(BlueprintPure)
    FVector GerstnerWavesQuadruple(const FVector& Position, const double Amplitude, const double Steepness, const double Speed, const double WaveLength, const double Direction, const double NumWaves, const double DirectionOffset);
    
    UFUNCTION(BlueprintPure)
    FVector GerstnerWave(const FVector& Position, const double Direction, const double Speed, const double WaveLength, const double Amplitude, const double Steepness, const double NumWaves);
    
    UFUNCTION(BlueprintPure)
    static double DivideWave(const double Value);
    
    UFUNCTION(BlueprintPure)
    static FVector DirectionWave(const double Direction);
    
};

