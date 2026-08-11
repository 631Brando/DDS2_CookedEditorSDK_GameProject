#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "OceanologyFolding.generated.h"

USTRUCT(BlueprintType)
struct FOceanologyFolding {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double FoamBoost;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double FoamContrast;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double FoamDepthMin;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double FoamOpacity;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double FoamPower;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double FoamRoughness;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double FoamScatterBias;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double FoamTextureBlendMin;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double FoamTextureBlendWidth;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double HeightBias;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double ScatteredLuminance;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double SmoothMax;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double SmoothMin;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor FoamEmissiveHigh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor FoamEmissiveLow;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor FoamScattering;
    
    OCEANOLOGY_PLUGIN_API FOceanologyFolding();
};

