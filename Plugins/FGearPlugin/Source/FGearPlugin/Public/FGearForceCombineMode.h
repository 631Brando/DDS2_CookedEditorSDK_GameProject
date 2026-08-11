#pragma once
#include "CoreMinimal.h"
#include "FGearForceCombineMode.generated.h"

UENUM(BlueprintType)
enum class FGearForceCombineMode : uint8 {
    GRIP,
    SIMPLE,
    SUM,
};

