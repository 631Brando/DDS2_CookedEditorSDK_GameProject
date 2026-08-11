#pragma once
#include "CoreMinimal.h"
#include "OceanologyHorizonCorrection.generated.h"

class UTexture;

USTRUCT(BlueprintType)
struct FOceanologyHorizonCorrection {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double DetailNormalSpeed;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double DetailScaleNormal;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double DistantNormalLength;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double DistantNormalOffset;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double HorizonCorrectionNormalIntensity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture* T_DetailNormal;
    
    OCEANOLOGY_PLUGIN_API FOceanologyHorizonCorrection();
};

