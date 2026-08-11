#pragma once
#include "CoreMinimal.h"
#include "OceanologyGroundCaustics.h"
#include "OceanologyLakePresetResult.generated.h"

USTRUCT(BlueprintType)
struct FOceanologyLakePresetResult {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOceanologyGroundCaustics GroundCaustics;
    
    OCEANOLOGY_PLUGIN_API FOceanologyLakePresetResult();
};

