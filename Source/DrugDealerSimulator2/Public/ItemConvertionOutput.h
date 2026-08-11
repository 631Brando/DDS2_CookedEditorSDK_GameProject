#pragma once
#include "CoreMinimal.h"
#include "ItemConvertionOutput.generated.h"

USTRUCT(BlueprintType)
struct FItemConvertionOutput {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ConvertsionItem;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PercentChance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 QuantityPerItem;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool DirectStackReplace;
    
    DRUGDEALERSIMULATOR2_API FItemConvertionOutput();
};

