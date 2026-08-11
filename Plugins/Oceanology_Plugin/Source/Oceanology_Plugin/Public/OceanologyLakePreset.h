#pragma once
#include "CoreMinimal.h"
#include "OceanologyGroundCaustics.h"
#include "OceanologyLakePresetResult.h"
#include "OceanologyWaterPreset.h"
#include "OceanologyWaterPresetResult.h"
#include "OceanologyLakePreset.generated.h"

class UOceanologyLakePreset;

UCLASS(Blueprintable)
class OCEANOLOGY_PLUGIN_API UOceanologyLakePreset : public UOceanologyWaterPreset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOceanologyGroundCaustics GroundCaustics;
    
    UOceanologyLakePreset();

    UFUNCTION(BlueprintPure)
    static void LerpPreset(const UOceanologyLakePreset* A, const UOceanologyLakePreset* B, const double Alpha, FOceanologyWaterPresetResult& OutWaterPresetResult, FOceanologyLakePresetResult& OutPresetResult);
    
};

