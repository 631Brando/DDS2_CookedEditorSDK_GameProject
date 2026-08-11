#pragma once
#include "CoreMinimal.h"
#include "OceanologyMaskUnderwater.generated.h"

USTRUCT(BlueprintType)
struct FOceanologyMaskUnderwater {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double UnderwaterLandscapeMask;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double UnderwaterObjectMask;
    
    OCEANOLOGY_PLUGIN_API FOceanologyMaskUnderwater();
};

