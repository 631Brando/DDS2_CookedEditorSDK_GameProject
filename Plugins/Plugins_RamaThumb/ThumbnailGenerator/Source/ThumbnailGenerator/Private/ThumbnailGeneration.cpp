#include "ThumbnailGeneration.h"

UThumbnailGeneration::UThumbnailGeneration() {
}

UTexture2D* UThumbnailGeneration::SaveThumbnail(UTexture2D* Thumbnail, const FDirectoryPath& OutputDirectory, const FString& OutputName) {
    return NULL;
}

void UThumbnailGeneration::K2_GenerateThumbnailAsync(UClass* ActorClass, FThumbnailSettings ThumbnailSettings, TMap<FString, FString> Properties, UThumbnailGeneration::FGenerateThumbnailCallback Callback, UThumbnailGeneration::FPreCaptureThumbnail PreCaptureThumbnail) {
}

void UThumbnailGeneration::K2_FinishSpawningThumbnailActor(AActor* Actor) {
}

UTexture2D* UThumbnailGeneration::K2_FinishGenerateThumbnail(AActor* Actor, const FThumbnailSettings& ThumbnailSettings) {
    return NULL;
}

FThumbnailSettings UThumbnailGeneration::K2_FinalizeThumbnailSettings(FThumbnailSettings ThumbnailSettings) {
    return FThumbnailSettings{};
}

FString UThumbnailGeneration::K2_ExportSetPropertyText(const TSet<int32>& Property) {
    return TEXT("");
}

FString UThumbnailGeneration::K2_ExportPropertyText(const int32& Property) {
    return TEXT("");
}

FString UThumbnailGeneration::K2_ExportMapPropertyText(const TMap<int32, int32>& Property) {
    return TEXT("");
}

FString UThumbnailGeneration::K2_ExportArrayPropertyText(const TArray<int32>& Property) {
    return TEXT("");
}

AActor* UThumbnailGeneration::K2_BeginGenerateThumbnail(UClass* ActorClass, const FThumbnailSettings& ThumbnailSettings) {
    return NULL;
}

void UThumbnailGeneration::InitializeThumbnailWorld(FThumbnailBackgroundSceneSettings BackgroundSceneSettings) {
}

UWorld* UThumbnailGeneration::GetThumbnailWorld() {
    return NULL;
}

USceneCaptureComponent2D* UThumbnailGeneration::GetThumbnailCaptureComponent() {
    return NULL;
}


