#pragma once
#include "CoreMinimal.h"
#include "OceanologyFoam.generated.h"

class UTexture;

USTRUCT(BlueprintType)
struct FOceanologyFoam {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double FoamDistortionIntensity;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double FoamDistortionScale;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double FoamDistortionSpeed;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double FoamNormals;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double UVBubbles;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double UVFoam;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double BubblesNormals;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture* T_BubblesColor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture* T_BubblesNormals;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture* T_FoamColor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture* T_FoamNormals;
    
    OCEANOLOGY_PLUGIN_API FOceanologyFoam();
};

