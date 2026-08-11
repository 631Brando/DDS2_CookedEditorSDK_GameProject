#pragma once
#include "CoreMinimal.h"
#include "FGearRewindReplayState.generated.h"

UENUM(BlueprintType)
enum class FGearRewindReplayState : uint8 {
    RS_PLAY,
    RS_REWIND,
    RS_REPLAY,
};

