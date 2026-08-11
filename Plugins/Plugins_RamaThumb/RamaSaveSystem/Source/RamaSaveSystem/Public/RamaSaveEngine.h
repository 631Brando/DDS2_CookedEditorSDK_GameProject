#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RamaAsyncSaveUnit.h"
#include "RamaSaveEngineParams.h"
#include "RamaSaveEngine.generated.h"

class ULevelStreaming;
class URamaSaveComponent;

UCLASS(Blueprintable)
class ARamaSaveEngine : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<URamaSaveComponent*> RamaSaveComponents;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FString> SaveOnlyActorsWithTags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FRamaAsyncSaveUnit> AsyncUnits;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRamaSaveEngineParams LoadParams;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<ULevelStreaming*> Load_StreamingLevels;
    
    ARamaSaveEngine(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SaveCancelledForStreamingLevel(const FString& Filename);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void LoadProcessFinished_PreActorFullyLoaded(const FString& Filename);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void LoadProcessFinished(const FString& Filename);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Async_SaveStarted(const FString& Filename);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Async_SaveFinished(const FString& Filename);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Async_SaveCancelled(const FString& Filename);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Async_ProgressUpdate(const FString& Filename, float Progress);
    
};

