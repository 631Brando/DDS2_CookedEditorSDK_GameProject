#pragma once
#include "CoreMinimal.h"
#include "FGearQueryType.generated.h"

UENUM(BlueprintType)
enum class FGearQueryType : uint8 {
    Line,
    Sphere,
    Convex,
};

