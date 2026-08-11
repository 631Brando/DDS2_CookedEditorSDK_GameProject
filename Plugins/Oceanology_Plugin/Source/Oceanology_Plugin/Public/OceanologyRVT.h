#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "OceanologyRVT.generated.h"

class UTexture;

USTRUCT(BlueprintType)
struct FOceanologyRVT {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double BoxMaxEdgeFalloff;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double DepthForDFFoam;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double DepthForMask;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double DepthForStillShore;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double DepthForSurfaceScattering;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double WaterZMax;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double WaterZMin;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor ShorelineSurfaceScatteringColor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture* T_Heightmap;
    
    OCEANOLOGY_PLUGIN_API FOceanologyRVT();
};

