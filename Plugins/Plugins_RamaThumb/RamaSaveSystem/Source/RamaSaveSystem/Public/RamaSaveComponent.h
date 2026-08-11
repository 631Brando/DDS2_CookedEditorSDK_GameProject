#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "Components/ActorComponent.h"
#include "RamaPlayerLoadedSignatureDelegate.h"
#include "RamaSaveFullyLoadedSignatureDelegate.h"
#include "RamaSavePreLoadDestroySignatureDelegate.h"
#include "RamaSavePreSaveSignatureDelegate.h"
#include "RamaSaveComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class RAMASAVESYSTEM_API URamaSaveComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGuid RamaSave_PersistentActorUniqueID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool RamaSave_LogPersistentActorGUID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FString> RamaSave_SaveTags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString ActorStreamingLevel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool RamaSave_ShouldLoadActorWorldPosition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool RamaSave_ShouldSaveActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool DestroyBeforeLoad;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FString> RamaSave_OwningActorVarsToSave;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FString> RamaSave_ComponentVarsToSave;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool RamaSave_VerboseLog;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool RamaSave_LogAllSavedComponentProperties;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool RamaSave_SavePhysicsData;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRamaSaveFullyLoadedSignature RamaSaveEvent_ActorFullyLoaded;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRamaSavePreSaveSignature RamaSaveEvent_PreSave;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRamaSavePreLoadDestroySignature RamaSaveEvent_PreLoadDestroy;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRamaPlayerLoadedSignature RamaSaveEvent_PlayerLoaded;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LoadedGameVersion;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTransform OwningActorTransform;
    
    URamaSaveComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void RamaSave_PreSave();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void RamaSave_PostLoad();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool RamaSave_HasSaveTag(const FString& SaveTag);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool RamaSave_HasAnyOfSaveTags(const TArray<FString>& SaveTags);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FString GetActorStreamingLevelPackageName();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetActorIsInPersistentLevel();
    
};

