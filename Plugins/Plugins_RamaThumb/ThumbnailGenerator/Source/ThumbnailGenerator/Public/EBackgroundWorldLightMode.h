#pragma once
#include "CoreMinimal.h"
#include "EBackgroundWorldLightMode.generated.h"

UENUM(BlueprintType)
enum class EBackgroundWorldLightMode : uint8 {
    ESpawnLights,
    ESourceFromWorld,
    ESourceSkyLight,
    ESourceDirectionalLights,
    ESourceAvailableSpawnRest,
    EIgnoreLights,
};

