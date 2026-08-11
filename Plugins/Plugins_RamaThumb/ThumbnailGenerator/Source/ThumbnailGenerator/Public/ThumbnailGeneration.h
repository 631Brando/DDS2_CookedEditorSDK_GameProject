#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/Object.h"
#include "ThumbnailBackgroundSceneSettings.h"
#include "ThumbnailSettings.h"
#include "ThumbnailGeneration.generated.h"

class AActor;
class USceneCaptureComponent2D;
class UTexture2D;
class UWorld;

UCLASS(Blueprintable)
class THUMBNAILGENERATOR_API UThumbnailGeneration : public UObject {
    GENERATED_BODY()
public:
    DECLARE_DYNAMIC_DELEGATE_OneParam(FPreCaptureThumbnail, AActor*, Actor);
    DECLARE_DYNAMIC_DELEGATE_OneParam(FGenerateThumbnailCallback, UTexture2D*, Thumbnail);
    
    UThumbnailGeneration();

    UFUNCTION(BlueprintCallable)
    static UTexture2D* SaveThumbnail(UTexture2D* Thumbnail, const FDirectoryPath& OutputDirectory, const FString& OutputName);
    
    UFUNCTION(BlueprintCallable)
    static void K2_GenerateThumbnailAsync(UClass* ActorClass, FThumbnailSettings ThumbnailSettings, TMap<FString, FString> Properties, UThumbnailGeneration::FGenerateThumbnailCallback Callback, UThumbnailGeneration::FPreCaptureThumbnail PreCaptureThumbnail);
    
    UFUNCTION(BlueprintCallable)
    static void K2_FinishSpawningThumbnailActor(AActor* Actor);
    
    UFUNCTION(BlueprintCallable)
    static UTexture2D* K2_FinishGenerateThumbnail(AActor* Actor, const FThumbnailSettings& ThumbnailSettings);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FThumbnailSettings K2_FinalizeThumbnailSettings(FThumbnailSettings ThumbnailSettings);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FString K2_ExportSetPropertyText(const TSet<int32>& Property);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FString K2_ExportPropertyText(const int32& Property);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FString K2_ExportMapPropertyText(const TMap<int32, int32>& Property);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FString K2_ExportArrayPropertyText(const TArray<int32>& Property);
    
    UFUNCTION(BlueprintCallable)
    static AActor* K2_BeginGenerateThumbnail(UClass* ActorClass, const FThumbnailSettings& ThumbnailSettings);
    
    UFUNCTION(BlueprintCallable)
    static void InitializeThumbnailWorld(FThumbnailBackgroundSceneSettings BackgroundSceneSettings);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static UWorld* GetThumbnailWorld();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static USceneCaptureComponent2D* GetThumbnailCaptureComponent();
    
};

