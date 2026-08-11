#pragma once
#include "CoreMinimal.h"
#include "EBackgroundWorldLightMode.h"
#include "ThumbnailBackgroundSceneSettings.generated.h"

class UWorld;

USTRUCT(BlueprintType)
struct THUMBNAILGENERATOR_API FThumbnailBackgroundSceneSettings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UWorld> BackgroundWorld;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EBackgroundWorldLightMode SpawnLightsMode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSpawnSkySphere;
    
    FThumbnailBackgroundSceneSettings();
};

