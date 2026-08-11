#pragma once
#include "CoreMinimal.h"
#include "EquipmentOfferEntry.generated.h"

USTRUCT(BlueprintType)
struct FEquipmentOfferEntry {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ShopOfferID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ShopID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 QuantityAvailable;
    
    DRUGDEALERSIMULATOR2_API FEquipmentOfferEntry();
};

