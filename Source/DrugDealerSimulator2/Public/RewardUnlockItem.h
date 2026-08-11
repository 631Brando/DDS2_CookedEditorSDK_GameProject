#pragma once
#include "CoreMinimal.h"
#include "RewardUnlockItem.generated.h"

USTRUCT(BlueprintType)
struct FRewardUnlockItem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName GroupID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ElementID;
    
    DRUGDEALERSIMULATOR2_API FRewardUnlockItem();
};

