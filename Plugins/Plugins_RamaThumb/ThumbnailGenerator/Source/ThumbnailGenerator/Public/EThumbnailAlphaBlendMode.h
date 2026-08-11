#pragma once
#include "CoreMinimal.h"
#include "EThumbnailAlphaBlendMode.generated.h"

UENUM(BlueprintType)
enum class EThumbnailAlphaBlendMode : uint8 {
    EReplace,
    EAdd,
    EMultiply,
    ESubtract,
};

