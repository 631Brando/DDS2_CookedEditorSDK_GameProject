#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "OceanologySurfaceScattering.generated.h"

USTRUCT(BlueprintType)
struct FOceanologySurfaceScattering {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double CameraVectorPower;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double FadeLengthScattering;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double FadeOffsetScattering;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double PhaseGHigh;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double PhaseGLow;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double ScatterBoost;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double SurfaceScatteringExponential;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double SurfaceScatteringIntensity;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double SurfaceScatteringPower;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double SurfaceScatteringRefractMax;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double SurfaceScatteringRefractMin;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double TopDownExp;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double WaterFresnelExponenth;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double WaterFresnelRoughness;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double WaterFresnelSpecular;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double WaterRoughness;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double WaterSpecular;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor Absorption;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor AbsorptionFar;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor Scattering;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor ScatteringFar;
    
    OCEANOLOGY_PLUGIN_API FOceanologySurfaceScattering();
};

