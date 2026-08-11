#pragma once
#include "CoreMinimal.h"
#include "EquipmentOfferEntry.h"
#include "EquipmentOfferData.generated.h"

USTRUCT(BlueprintType)
struct FEquipmentOfferData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, FEquipmentOfferEntry> OfferList;
    
    DRUGDEALERSIMULATOR2_API FEquipmentOfferData();
};

