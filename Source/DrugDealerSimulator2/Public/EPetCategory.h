#pragma once
#include "CoreMinimal.h"
#include "EPetCategory.generated.h"

UENUM(BlueprintType)
enum class EPetCategory : uint8 {
    Dog,
    Cat,
    Other,
};

