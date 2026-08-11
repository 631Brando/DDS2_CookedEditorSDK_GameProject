#pragma once
#include "CoreMinimal.h"
#include "EMixStatus.generated.h"

UENUM(BlueprintType)
enum class EMixStatus : uint8 {
    DoesNotExist,
    MixFound,
    MixArchived,
};

