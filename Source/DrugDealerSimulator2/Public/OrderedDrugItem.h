#pragma once
#include "CoreMinimal.h"
#include "OrderedDrugItem.generated.h"

USTRUCT(BlueprintType)
struct FOrderedDrugItem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName DrugID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 DrugQuantity;
    
    DRUGDEALERSIMULATOR2_API FOrderedDrugItem();
};

