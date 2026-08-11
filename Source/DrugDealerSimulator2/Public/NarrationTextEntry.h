#pragma once
#include "CoreMinimal.h"
#include "NarrationTextEntry.generated.h"

USTRUCT(BlueprintType)
struct FNarrationTextEntry {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText NarrationLine;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TimeSeconds;
    
    DRUGDEALERSIMULATOR2_API FNarrationTextEntry();
};

