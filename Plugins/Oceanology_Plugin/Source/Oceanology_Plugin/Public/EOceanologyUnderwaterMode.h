#pragma once
#include "CoreMinimal.h"
#include "EOceanologyUnderwaterMode.generated.h"

UENUM(BlueprintType)
enum class EOceanologyUnderwaterMode : uint8 {
    None,
    Underwater,
    VolumetricFog,
};

