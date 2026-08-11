#pragma once
#include "CoreMinimal.h"
#include "OceanologyFlipbook.generated.h"

class UTexture;

USTRUCT(BlueprintType)
struct FOceanologyFlipbook {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double DistantWaterScale;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double FarNormalFresnelPower;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double FrameRateFar;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double FrameRateNear;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double NearNormalStrength;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double NearWaterScale;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double NormalLongDistanceStrength;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double NormalMidDistanceForce;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture* T_FarNormalWater;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture* T_WaterNormals;
    
    OCEANOLOGY_PLUGIN_API FOceanologyFlipbook();
};

