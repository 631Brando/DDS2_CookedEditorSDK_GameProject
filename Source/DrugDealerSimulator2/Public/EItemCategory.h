#pragma once
#include "CoreMinimal.h"
#include "EItemCategory.generated.h"

UENUM(BlueprintType)
enum class EItemCategory : uint8 {
    Miscellaneous,
    Drugs,
    Substances,
    Money,
    Valuables,
    Clothes,
    Tools,
    Throwables,
    Keys,
    SpecialItems,
    Knowledge,
};

