#pragma once
#include "CoreMinimal.h"
#include "RecipieRandOutput.generated.h"

USTRUCT(BlueprintType)
struct FRecipieRandOutput {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ItemId;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RandChance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Quantity;
    
    DRUGDEALERSIMULATOR2_API FRecipieRandOutput();
};

