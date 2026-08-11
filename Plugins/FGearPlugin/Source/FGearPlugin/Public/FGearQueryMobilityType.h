#pragma once
#include "CoreMinimal.h"
#include "FGearQueryMobilityType.generated.h"

UENUM(BlueprintType)
enum class FGearQueryMobilityType : uint8 {
    Any,
    Static,
    Dynamic,
};

