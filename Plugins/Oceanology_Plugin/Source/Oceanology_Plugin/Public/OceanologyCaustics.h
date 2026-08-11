#pragma once
#include "CoreMinimal.h"
#include "OceanologyCaustics.generated.h"

class UTexture;

USTRUCT(BlueprintType)
struct FOceanologyCaustics {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double CausticsBrightness;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double CausticsFadeInDistance;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double CausticsScale;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double FadeDistance;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double LightParallax;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double MultiplyRefraction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture* T_Caustics;
    
    OCEANOLOGY_PLUGIN_API FOceanologyCaustics();
};

