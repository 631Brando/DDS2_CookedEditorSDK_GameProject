#pragma once
#include "CoreMinimal.h"
#include "EThumbnailCameraFitMode.generated.h"

UENUM(BlueprintType)
enum class EThumbnailCameraFitMode : uint8 {
    EFill,
    EFit,
    EFitX,
    EFitY,
};

