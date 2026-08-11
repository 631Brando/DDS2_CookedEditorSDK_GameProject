#pragma once
#include "CoreMinimal.h"
#include "InventoryGridData.h"
#include "SpecialSlotListItem.generated.h"

USTRUCT(BlueprintType)
struct FSpecialSlotListItem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName SlotID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FInventoryGridData SlotData;
    
    DRUGDEALERSIMULATOR2_API FSpecialSlotListItem();
};

