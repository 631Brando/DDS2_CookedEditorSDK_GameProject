#pragma once
#include "CoreMinimal.h"
#include "EThumbnailSceneSimulationMode.generated.h"

UENUM(BlueprintType)
enum class EThumbnailSceneSimulationMode : uint8 {
    ENone,
    EActor,
    EAllComponents,
    ESpecifiedComponents,
};

