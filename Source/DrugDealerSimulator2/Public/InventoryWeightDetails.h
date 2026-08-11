#pragma once
#include "CoreMinimal.h"
#include "InventoryWeightDetails.generated.h"

USTRUCT(BlueprintType)
struct FInventoryWeightDetails {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float WeightItems;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float WeightSpecialSlots;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float WeightClothes;
    
    DRUGDEALERSIMULATOR2_API FInventoryWeightDetails();
};

