#pragma once
#include "CoreMinimal.h"
#include "EMessageRewardRule.generated.h"

UENUM(BlueprintType)
enum class EMessageRewardRule : uint8 {
    OnAccept,
    OnDisplay,
};

