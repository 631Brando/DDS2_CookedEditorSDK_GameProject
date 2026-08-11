#pragma once
#include "CoreMinimal.h"
#include "ECartelCharacterJobType.generated.h"

UENUM(BlueprintType)
enum class ECartelCharacterJobType : uint8 {
    Boss,
    AvailableCartel,
    AvailableClient,
    Client,
    Dealer,
    Spotter,
    Distributor,
    LabTech,
    Muscle,
};

