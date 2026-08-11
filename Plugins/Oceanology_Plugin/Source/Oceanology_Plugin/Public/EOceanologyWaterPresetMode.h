#pragma once
#include "CoreMinimal.h"
#include "EOceanologyWaterPresetMode.generated.h"

UENUM(BlueprintType)
enum class EOceanologyWaterPresetMode : uint8 {
    UsePresetDirectly,
    ApplyPresetToCurrentSettings,
};

