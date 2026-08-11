#pragma once
#include "CoreMinimal.h"
#include "ESubstanceForm.generated.h"

UENUM(BlueprintType)
enum class ESubstanceForm : uint8 {
    SolidPowder,
    Fluid,
    Other,
};

