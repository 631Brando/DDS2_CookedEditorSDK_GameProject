#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "OceanologyVolumetricFog.generated.h"

USTRUCT(BlueprintType)
struct FOceanologyVolumetricFog {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double MultiScatteringContribution;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double MultiScatteringOcclusion;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double WetAlpha;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor ExponentialFogColor;
    
    OCEANOLOGY_PLUGIN_API FOceanologyVolumetricFog();
};

