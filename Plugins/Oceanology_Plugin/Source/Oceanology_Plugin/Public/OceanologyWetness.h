#pragma once
#include "CoreMinimal.h"
#include "OceanologyWetness.generated.h"

USTRUCT(BlueprintType)
struct FOceanologyWetness {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double BandOpacity;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double MoistureMetallic;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double MoistureRoughness;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double WetHardness;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double WetLocation;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double WetRadius;
    
    OCEANOLOGY_PLUGIN_API FOceanologyWetness();
};

