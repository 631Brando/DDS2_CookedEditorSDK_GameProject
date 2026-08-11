#pragma once
#include "CoreMinimal.h"
#include "OceanologyGroundCaustics.generated.h"

USTRUCT(BlueprintType)
struct FOceanologyGroundCaustics {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double DarknessExposure;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double MaximumDarkness;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double MinimumDarkness;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double WetAlpha;
    
    OCEANOLOGY_PLUGIN_API FOceanologyGroundCaustics();
};

