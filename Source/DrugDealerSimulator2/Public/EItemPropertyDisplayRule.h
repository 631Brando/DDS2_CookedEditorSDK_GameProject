#pragma once
#include "CoreMinimal.h"
#include "EItemPropertyDisplayRule.generated.h"

UENUM(BlueprintType)
enum class EItemPropertyDisplayRule : uint8 {
    DirectFloat,
    DirectInteger,
    MultiplierPercent = 3,
    Distance,
    Toggle,
};

