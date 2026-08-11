#pragma once
#include "CoreMinimal.h"
#include "EShopItemOfferType.generated.h"

UENUM(BlueprintType)
enum class EShopItemOfferType : uint8 {
    Regular,
    Rotary,
    Special,
};

