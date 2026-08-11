#pragma once
#include "CoreMinimal.h"
#include "MixEntry.generated.h"

USTRUCT(BlueprintType)
struct FMixEntry {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName SubstanceID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SubstancePercent;
    
    DRUGDEALERSIMULATOR2_API FMixEntry();
};

