#pragma once
#include "CoreMinimal.h"
#include "FGearControllerType.generated.h"

UENUM(BlueprintType)
enum class FGearControllerType : uint8 {
    KEYBOARD,
    JOYSTICK,
    WHEEL,
};

