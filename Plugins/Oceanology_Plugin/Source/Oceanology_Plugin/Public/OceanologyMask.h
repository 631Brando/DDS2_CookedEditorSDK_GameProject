#pragma once
#include "CoreMinimal.h"
#include "OceanologyMask.generated.h"

USTRUCT(BlueprintType)
struct FOceanologyMask {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double LandscapeVisibilityMask;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double ObjectVisibilityMask;
    
    OCEANOLOGY_PLUGIN_API FOceanologyMask();
};

