#pragma once
#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "ThumbnailSettings.h"
#include "ThumbnailSceneInterface.generated.h"

UINTERFACE(Blueprintable, MinimalAPI)
class UThumbnailSceneInterface : public UInterface {
    GENERATED_BODY()
};

class IThumbnailSceneInterface : public IInterface {
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnUpdateThumbnailScene(const FThumbnailSettings& ThumbnailSettings);
    
};

