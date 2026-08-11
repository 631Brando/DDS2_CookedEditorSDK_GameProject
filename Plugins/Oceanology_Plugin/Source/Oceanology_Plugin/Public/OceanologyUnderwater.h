#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "OceanologyUnderwater.generated.h"

class UTexture;

USTRUCT(BlueprintType)
struct FOceanologyUnderwater {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double AtmosphereLighting;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double BandOffset;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double BandOpacity;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double Bandwidth;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double DarknessFadeDepth;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double DeepColorDistance;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double DepthColorAbsorption;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double DistortionIntensity;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double DistortionScale;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double DistortionSpeed;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double FogDensity;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double LocalPosition;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double SunPower;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double UnderwaterLightDepth;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double UnderwaterNoLightDepth;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double VignetteDark;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double VignetteDistortion;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double VignetteEdge;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double WaterLineColorIntensity;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double WaterLineDistanceFalloff;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double WaterLineRefraction;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double WaterLineRefractionWidth;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double WetAlpha;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double WetHardness;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double WetLocation;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double WetRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor ExponentialFogColorHigh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor ExponentialFogColorLow;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor SceneColorDeep;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor SceneColorShallow;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture* DistortionTexture;
    
    OCEANOLOGY_PLUGIN_API FOceanologyUnderwater();
};

