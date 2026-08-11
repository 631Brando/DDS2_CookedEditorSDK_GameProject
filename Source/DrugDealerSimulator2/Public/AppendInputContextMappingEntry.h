#pragma once
#include "CoreMinimal.h"
#include "AppendInputContextMappingEntry.generated.h"

class UInputMappingContext;

USTRUCT(BlueprintType)
struct FAppendInputContextMappingEntry {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UInputMappingContext> TargetInputMappingContext;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UInputMappingContext> SourceInputMappingContext;
    
    DRUGDEALERSIMULATOR2_API FAppendInputContextMappingEntry();
};

