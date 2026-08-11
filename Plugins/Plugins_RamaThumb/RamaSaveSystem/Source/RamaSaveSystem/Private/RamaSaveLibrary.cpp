#include "RamaSaveLibrary.h"

URamaSaveLibrary::URamaSaveLibrary() {
}

bool URamaSaveLibrary::RenameFile(const FString& Dest, const FString& Source) {
    return false;
}

FString URamaSaveLibrary::RemoveLevelPIEPrefix(const FString& LevelName) {
    return TEXT("");
}

FString URamaSaveLibrary::RamaSavePaths_SavedDir() {
    return TEXT("");
}

FString URamaSaveLibrary::RamaSavePaths_GameRootDirectory() {
    return TEXT("");
}

FString URamaSaveLibrary::RamaSavePaths_BinaryLocation() {
    return TEXT("");
}

void URamaSaveLibrary::RamaSave_SaveToFile_WithTags(UObject* WorldContextObject, const FString& Filename, bool& FileIOSuccess, bool& AllComponentsSaved, TArray<FString> SaveOnlyActorsWithTags, const FString& SaveOnlyStreamingLevel, bool IgnoreStreamingActorsIfNoLevelSpecified, URamaSaveObject* StaticSaveData) {
}

void URamaSaveLibrary::RamaSave_SaveToFile(UObject* WorldContextObject, const FString& Filename, bool& FileIOSuccess, bool& AllComponentsSaved, const FString& SaveOnlyStreamingLevel, bool IgnoreStreamingActorsIfNoLevelSpecified, URamaSaveObject* StaticSaveData) {
}

void URamaSaveLibrary::RamaSave_SaveOnlyStaticToFile(const FString& Filename, bool& FileIOSuccess, URamaSaveObject* StaticSaveData) {
}

int32 URamaSaveLibrary::RamaSave_LoadStreamingStateFromFile(UObject* WorldContextObject, bool& FileIOSuccess, const FString& Filename, TArray<FString>& StreamingLevelsStates) {
    return 0;
}

URamaSaveObject* URamaSaveLibrary::RamaSave_LoadStaticDataFromFile(bool& FileIOSuccess, const FString& Filename) {
    return NULL;
}

void URamaSaveLibrary::RamaSave_LoadFromFileWithTags(UObject* WorldContextObject, const TArray<FString>& LoadOnlyActorsWithSaveTags, bool& FileIOSuccess, const FString& Filename, bool DestroyActorsBeforeLoad, bool DontLoadPlayerPawns, bool HandleStreamingLevelsLoadingAndUnloading, const FString& LoadOnlyStreamingLevel) {
}

void URamaSaveLibrary::RamaSave_LoadFromFile(UObject* WorldContextObject, bool& FileIOSuccess, const FString& Filename, bool DestroyActorsBeforeLoad, bool DontLoadPlayerPawns, bool HandleStreamingLevelsLoadingAndUnloading, const FString& LoadOnlyStreamingLevel) {
}

FText URamaSaveLibrary::RamaSave_GetFileTimeStampText(const FString& File, bool Verbose) {
    return FText::GetEmpty();
}

FDateTime URamaSaveLibrary::RamaSave_GetFileTimeStamp(const FString& File) {
    return FDateTime{};
}

bool URamaSaveLibrary::RamaSave_FolderExists(const FString& Dir) {
    return false;
}

bool URamaSaveLibrary::RamaSave_FileExists(const FString& File) {
    return false;
}

bool URamaSaveLibrary::RamaSave_DeleteFolder_DirectoryTree(const FString& Folder, FString& ErrorInfo) {
    return false;
}

bool URamaSaveLibrary::RamaSave_DeleteFile(const FString& File) {
    return false;
}

void URamaSaveLibrary::RamaSave_DateTimeToString(const FDateTime& TheDateTime, FString& AsString) {
}

void URamaSaveLibrary::RamaSave_DateTimeFromString(const FString& AsString, FDateTime& TheDateTime) {
}

bool URamaSaveLibrary::RamaSave_CopyFile(const FString& Dest, const FString& Src) {
    return false;
}

void URamaSaveLibrary::RamaSave_ClearLevel(UObject* WorldContextObject, bool DontDestroyPlayers, const FString& ClearOnlyStreamingLevel) {
}

bool URamaSaveLibrary::RamaSave_CancelAsyncSaveProcess(UObject* WorldContextObject) {
    return false;
}

bool URamaSaveLibrary::RamaFileIO_GetFiles(const FString& FullPathOfBaseDir, TArray<FString>& FilenamesOut, bool Recursive, const FString& FilterByExtension) {
    return false;
}

FString URamaSaveLibrary::GetDocumentsFolder() {
    return TEXT("");
}

void URamaSaveLibrary::GetAllRamaSaveComponentsWithTags(UObject* WorldContextObject, const TArray<FString>& SaveTags, TArray<URamaSaveComponent*>& RamaSaveComponents, const FString& GetOnlyStreamingLevelName, bool IgnoreStreamingActorsIfNoStreamingLevelSpecified) {
}

void URamaSaveLibrary::GetAllRamaSaveComponents(UObject* WorldContextObject, TArray<URamaSaveComponent*>& RamaSaveComponents, const FString& GetOnlyStreamingLevelName, bool IgnoreStreamingActorsIfNoStreamingLevelSpecified) {
}

void URamaSaveLibrary::GetAllRamaSaveActorsWithTags(UObject* WorldContextObject, const TArray<FString>& SaveTags, TArray<AActor*>& RamaSaveActors) {
}

void URamaSaveLibrary::GetAllRamaSaveActors(UObject* WorldContextObject, TArray<AActor*>& RamaSaveActors) {
}


