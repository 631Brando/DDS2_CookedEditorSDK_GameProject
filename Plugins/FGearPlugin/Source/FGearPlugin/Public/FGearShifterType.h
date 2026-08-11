#pragma once
#include "CoreMinimal.h"
#include "FGearShifterType.generated.h"

UENUM(BlueprintType)
enum class FGearShifterType : uint8 {
    AUTO,
    SEQUENTIAL,
    MANUAL,
};

