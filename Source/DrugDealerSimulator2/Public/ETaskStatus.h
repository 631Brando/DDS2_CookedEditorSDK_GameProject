#pragma once
#include "CoreMinimal.h"
#include "ETaskStatus.generated.h"

UENUM(BlueprintType)
enum class ETaskStatus : uint8 {
    Inactive,
    Active,
    Completed,
    Failed,
};

