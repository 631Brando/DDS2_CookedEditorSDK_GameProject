#pragma once
#include "CoreMinimal.h"
#include "GameFeatureAction.h"
#include "AddStreamingLevelGameFeatureAction.generated.h"

class UWorld;

UCLASS(Blueprintable, EditInlineNew)
class DRUGDEALERSIMULATOR2_API UAddStreamingLevelGameFeatureAction : public UGameFeatureAction {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UWorld> LevelToModify;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UWorld> StreamingLevel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bRuntimeFeatureActionActivation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bServerSideOnly;
    
public:
    UAddStreamingLevelGameFeatureAction();

};

