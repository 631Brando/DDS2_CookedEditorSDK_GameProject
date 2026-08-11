#pragma once
#include "CoreMinimal.h"
#include "EOceanAudioMode.generated.h"

UENUM(BlueprintType)
enum class EOceanAudioMode : uint8 {
    None,
    Underwater,
    Wave,
};

