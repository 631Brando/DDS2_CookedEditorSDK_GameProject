#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ThumbnailGeneratorScript.generated.h"

class AActor;

UCLASS(Abstract, Blueprintable)
class THUMBNAILGENERATOR_API UThumbnailGeneratorScript : public UObject {
    GENERATED_BODY()
public:
    UThumbnailGeneratorScript();

    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void PreCaptureActorThumbnail(AActor* ThumbnailActor);
    
};

