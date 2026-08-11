#pragma once
#include "CoreMinimal.h"
#include "OceanologyWaterProjection.generated.h"

USTRUCT(BlueprintType)
struct FOceanologyWaterProjection {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double VirtualRealityEyeOffset;
    
    OCEANOLOGY_PLUGIN_API FOceanologyWaterProjection();
};

