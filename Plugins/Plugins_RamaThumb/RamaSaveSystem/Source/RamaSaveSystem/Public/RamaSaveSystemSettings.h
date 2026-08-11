#pragma once
#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "RamaSaveSystemAssetPathRemap.h"
#include "Templates/SubclassOf.h"
#include "RamaSaveSystemSettings.generated.h"

class ARamaSaveEngine;
class URamaSaveSystemSettings;

UCLASS(Blueprintable, DefaultConfig, Config=Game)
class URamaSaveSystemSettings : public UDeveloperSettings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    float GameVersion;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<ARamaSaveEngine> RamaSaveEngineBP;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FRamaSaveSystemAssetPathRemap> RemappedVariablesAndClasses;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool SaveAllPropertiesMarkedAsSaveGame;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool UseUncompressedSaveFiles;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool AsyncSave;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AsyncSaveTickInterval;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AsyncSaveActorChunkSize;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool Saving_PerformObjectValidityChecks;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool Loading_GlobalVerboseLogging;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool Loading_GlobalDisablePhysicsLoad;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool LogSavingAndLoadingOfEachStaticDataProperty;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool LogLoadedActorClassPath;
    
    URamaSaveSystemSettings();

    UFUNCTION(BlueprintCallable, BlueprintPure)
    static URamaSaveSystemSettings* Get();
    
};

