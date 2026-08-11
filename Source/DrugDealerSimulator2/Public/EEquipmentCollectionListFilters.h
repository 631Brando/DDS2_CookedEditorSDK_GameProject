#pragma once
#include "CoreMinimal.h"
#include "EEquipmentCollectionListFilters.generated.h"

UENUM(BlueprintType)
enum class EEquipmentCollectionListFilters : uint8 {
    ShowAll,
    ShowOfferOnly,
    ShowCollectionOnly,
};

