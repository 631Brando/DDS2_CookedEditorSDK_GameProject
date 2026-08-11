#pragma once
#include "CoreMinimal.h"
#include "StressEventListItem.generated.h"

USTRUCT(BlueprintType)
struct FStressEventListItem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName EventID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TimeLeft;
    
    DRUGDEALERSIMULATOR2_API FStressEventListItem();
};

