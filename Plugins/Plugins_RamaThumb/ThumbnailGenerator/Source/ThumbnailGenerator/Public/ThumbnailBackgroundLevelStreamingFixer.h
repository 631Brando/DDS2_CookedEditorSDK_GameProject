#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ThumbnailBackgroundLevelStreamingFixer.generated.h"

class ULevelStreaming;

UCLASS(Blueprintable)
class UThumbnailBackgroundLevelStreamingFixer : public UObject {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ULevelStreaming* LevelStreaming;
    
public:
    UThumbnailBackgroundLevelStreamingFixer();

    UFUNCTION(BlueprintCallable)
    void OnLevelShown();
    
};

