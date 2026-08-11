#pragma once
#include "CoreMinimal.h"
#include "OceanologyWetness.h"
#include "OceanologyOceanPresetResult.generated.h"

USTRUCT(BlueprintType)
struct FOceanologyOceanPresetResult {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOceanologyWetness Wetness;
    
    OCEANOLOGY_PLUGIN_API FOceanologyOceanPresetResult();
};

