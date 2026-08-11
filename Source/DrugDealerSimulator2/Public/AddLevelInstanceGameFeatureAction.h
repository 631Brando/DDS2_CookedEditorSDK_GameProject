#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameFeatureAction.h"
#include "AddLevelInstanceGameFeatureAction.generated.h"

class ULevelStreamingDynamic;
class UWorld;

UCLASS(Blueprintable, EditInlineNew)
class DRUGDEALERSIMULATOR2_API UAddLevelInstanceGameFeatureAction : public UGameFeatureAction {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UWorld> LevelToModify;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UWorld> LevelToInject;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTransform RelativeTransform;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bRuntimeFeatureActionActivation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bServerSideOnly;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bShouldRebuildNavigationPostLoad;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<FName, ULevelStreamingDynamic*> WorldsInstances;
    
public:
    UAddLevelInstanceGameFeatureAction();

protected:
    UFUNCTION(BlueprintCallable)
    void OnLevelInstanceShown();
    
};

