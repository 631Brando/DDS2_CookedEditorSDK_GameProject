#pragma once
#include "CoreMinimal.h"
#include "OceanologyOceanPresetResult.h"
#include "OceanologyWaterPreset.h"
#include "OceanologyWaterPresetResult.h"
#include "OceanologyWetness.h"
#include "OceanologyOceanPreset.generated.h"

class UOceanologyOceanPreset;

UCLASS(Blueprintable)
class OCEANOLOGY_PLUGIN_API UOceanologyOceanPreset : public UOceanologyWaterPreset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool EnableWetness;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOceanologyWetness Wetness;
    
    UOceanologyOceanPreset();

    UFUNCTION(BlueprintPure)
    static void LerpPreset(const UOceanologyOceanPreset* A, const UOceanologyOceanPreset* B, const double Alpha, FOceanologyWaterPresetResult& OutWaterPresetResult, FOceanologyOceanPresetResult& OutOceanPresetResult);
    
};

