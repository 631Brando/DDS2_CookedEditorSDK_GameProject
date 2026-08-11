#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "EOceanologyGerstnerWaveSummarize.h"
#include "EOceanologyUnderwaterMode.h"
#include "OceanologyBaseOffset.h"
#include "OceanologyBubblesSettings.h"
#include "OceanologyCaustics.h"
#include "OceanologyFlipbook.h"
#include "OceanologyFoam.h"
#include "OceanologyFolding.h"
#include "OceanologyGGX.h"
#include "OceanologyGlobalDisplacement.h"
#include "OceanologyHorizonCorrection.h"
#include "OceanologyMask.h"
#include "OceanologyMaskUnderwater.h"
#include "OceanologyProcedural.h"
#include "OceanologyRVT.h"
#include "OceanologyRefraction.h"
#include "OceanologySurfaceScattering.h"
#include "OceanologyUnderwater.h"
#include "OceanologyVolumetricFog.h"
#include "OceanologyWaterProjection.h"
#include "OceanologyWave_1.h"
#include "OceanologyWave_2.h"
#include "OceanologyWave_3.h"
#include "OceanologyWave_4.h"
#include "OceanologyWaterPreset.generated.h"

UCLASS(Blueprintable)
class OCEANOLOGY_PLUGIN_API UOceanologyWaterPreset : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOceanologyGlobalDisplacement GlobalDisplacement;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOceanologyBaseOffset BaseOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOceanologyWave_1 Wave_1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOceanologyWave_2 Wave_2;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOceanologyWave_3 Wave_3;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOceanologyWave_4 Wave_4;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EOceanologyGerstnerWaveSummarize Summarize;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOceanologySurfaceScattering SurfaceScattering;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOceanologyCaustics Caustics;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOceanologyRefraction Refraction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOceanologyHorizonCorrection HorizonCorrection;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOceanologyFlipbook flipbook;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOceanologyFoam Foam;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOceanologyFolding Folding;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOceanologyProcedural Procedural;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOceanologyRVT RVT;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOceanologyMask Mask;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOceanologyGGX GGX;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EOceanologyUnderwaterMode UnderwaterMode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOceanologyUnderwater Underwater;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOceanologyVolumetricFog VolumetricFog;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOceanologyMaskUnderwater MaskUnderwater;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOceanologyBubblesSettings BubblesSettings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOceanologyWaterProjection WaterProjection;
    
    UOceanologyWaterPreset();

};

