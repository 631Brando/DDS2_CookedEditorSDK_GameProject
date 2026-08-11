#pragma once
#include "CoreMinimal.h"
#include "EOceanologyWaveTimeMode.generated.h"

UENUM(BlueprintType)
enum class EOceanologyWaveTimeMode : uint8 {
    LocalTime,
    ServerTimeForReplication,
};

