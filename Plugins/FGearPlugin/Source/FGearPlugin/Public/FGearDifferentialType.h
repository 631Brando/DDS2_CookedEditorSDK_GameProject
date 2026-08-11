#pragma once
#include "CoreMinimal.h"
#include "FGearDifferentialType.generated.h"

UENUM(BlueprintType)
enum class FGearDifferentialType : uint8 {
    DF_OPEN,
    DF_LOCKED,
    DF_LSD,
};

