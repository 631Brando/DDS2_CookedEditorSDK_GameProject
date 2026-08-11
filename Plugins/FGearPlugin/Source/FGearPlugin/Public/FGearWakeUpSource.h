#pragma once
#include "CoreMinimal.h"
#include "FGearWakeUpSource.generated.h"

UENUM(BlueprintType)
enum class FGearWakeUpSource : uint8 {
    None,
    Throttle,
    Braking,
    Steering = 4,
    Shifting = 8,
};

