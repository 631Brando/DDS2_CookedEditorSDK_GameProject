#pragma once
#include "CoreMinimal.h"
#include "ETaskSharePolicy.generated.h"

UENUM(BlueprintType)
enum class ETaskSharePolicy : uint8 {
    SharedSingle,
    SharedMultiple,
    PrivateOnly,
    CartelTask,
};

