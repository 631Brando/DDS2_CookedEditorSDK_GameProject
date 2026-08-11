#pragma once
#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "UObject/NoExportTypes.h"
#include "ThumbnailActorInterface.generated.h"

UINTERFACE(Blueprintable, MinimalAPI)
class UThumbnailActorInterface : public UInterface {
    GENERATED_BODY()
};

class IThumbnailActorInterface : public IInterface {
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void PreCaptureActorThumbnail();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    FTransform GetThumbnailTransform() const;
    
};

