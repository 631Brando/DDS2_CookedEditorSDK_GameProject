#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ThumbnailBackgroundSceneSettings.h"
#include "ThumbnailSettings.h"
#include "ThumbnailGeneratorSettings.generated.h"

UCLASS(Blueprintable, DefaultConfig, Config=Engine)
class THUMBNAILGENERATOR_API UThumbnailGeneratorSettings : public UObject {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UObject*> AssetRefs;
    
public:
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    FThumbnailSettings DefaultThumbnailSettings;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    FThumbnailBackgroundSceneSettings BackgroundSceneSettings;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MaxRenderTargetCacheSize;
    
    UThumbnailGeneratorSettings();

};

