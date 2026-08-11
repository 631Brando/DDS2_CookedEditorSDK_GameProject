#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "RamaSaveLibrary.generated.h"

class AActor;
class UObject;
class URamaSaveComponent;
class URamaSaveObject;

UCLASS(Blueprintable)
class RAMASAVESYSTEM_API URamaSaveLibrary : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    URamaSaveLibrary();

    UFUNCTION(BlueprintCallable)
    static bool RenameFile(const FString& Dest, const FString& Source);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FString RemoveLevelPIEPrefix(const FString& LevelName);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FString RamaSavePaths_SavedDir();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FString RamaSavePaths_GameRootDirectory();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FString RamaSavePaths_BinaryLocation();
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void RamaSave_SaveToFile_WithTags(UObject* WorldContextObject, const FString& Filename, bool& FileIOSuccess, bool& AllComponentsSaved, TArray<FString> SaveOnlyActorsWithTags, const FString& SaveOnlyStreamingLevel, bool IgnoreStreamingActorsIfNoLevelSpecified, URamaSaveObject* StaticSaveData);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void RamaSave_SaveToFile(UObject* WorldContextObject, const FString& Filename, bool& FileIOSuccess, bool& AllComponentsSaved, const FString& SaveOnlyStreamingLevel, bool IgnoreStreamingActorsIfNoLevelSpecified, URamaSaveObject* StaticSaveData);
    
    UFUNCTION(BlueprintCallable)
    static void RamaSave_SaveOnlyStaticToFile(const FString& Filename, bool& FileIOSuccess, URamaSaveObject* StaticSaveData);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static int32 RamaSave_LoadStreamingStateFromFile(UObject* WorldContextObject, bool& FileIOSuccess, const FString& Filename, TArray<FString>& StreamingLevelsStates);
    
    UFUNCTION(BlueprintCallable)
    static URamaSaveObject* RamaSave_LoadStaticDataFromFile(bool& FileIOSuccess, const FString& Filename);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void RamaSave_LoadFromFileWithTags(UObject* WorldContextObject, const TArray<FString>& LoadOnlyActorsWithSaveTags, bool& FileIOSuccess, const FString& Filename, bool DestroyActorsBeforeLoad, bool DontLoadPlayerPawns, bool HandleStreamingLevelsLoadingAndUnloading, const FString& LoadOnlyStreamingLevel);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void RamaSave_LoadFromFile(UObject* WorldContextObject, bool& FileIOSuccess, const FString& Filename, bool DestroyActorsBeforeLoad, bool DontLoadPlayerPawns, bool HandleStreamingLevelsLoadingAndUnloading, const FString& LoadOnlyStreamingLevel);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FText RamaSave_GetFileTimeStampText(const FString& File, bool Verbose);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FDateTime RamaSave_GetFileTimeStamp(const FString& File);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool RamaSave_FolderExists(const FString& Dir);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool RamaSave_FileExists(const FString& File);
    
    UFUNCTION(BlueprintCallable)
    static bool RamaSave_DeleteFolder_DirectoryTree(const FString& Folder, FString& ErrorInfo);
    
    UFUNCTION(BlueprintCallable)
    static bool RamaSave_DeleteFile(const FString& File);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void RamaSave_DateTimeToString(const FDateTime& TheDateTime, FString& AsString);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void RamaSave_DateTimeFromString(const FString& AsString, FDateTime& TheDateTime);
    
    UFUNCTION(BlueprintCallable)
    static bool RamaSave_CopyFile(const FString& Dest, const FString& Src);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void RamaSave_ClearLevel(UObject* WorldContextObject, bool DontDestroyPlayers, const FString& ClearOnlyStreamingLevel);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static bool RamaSave_CancelAsyncSaveProcess(UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool RamaFileIO_GetFiles(const FString& FullPathOfBaseDir, TArray<FString>& FilenamesOut, bool Recursive, const FString& FilterByExtension);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FString GetDocumentsFolder();
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void GetAllRamaSaveComponentsWithTags(UObject* WorldContextObject, const TArray<FString>& SaveTags, TArray<URamaSaveComponent*>& RamaSaveComponents, const FString& GetOnlyStreamingLevelName, bool IgnoreStreamingActorsIfNoStreamingLevelSpecified);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void GetAllRamaSaveComponents(UObject* WorldContextObject, TArray<URamaSaveComponent*>& RamaSaveComponents, const FString& GetOnlyStreamingLevelName, bool IgnoreStreamingActorsIfNoStreamingLevelSpecified);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void GetAllRamaSaveActorsWithTags(UObject* WorldContextObject, const TArray<FString>& SaveTags, TArray<AActor*>& RamaSaveActors);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void GetAllRamaSaveActors(UObject* WorldContextObject, TArray<AActor*>& RamaSaveActors);
    
};

