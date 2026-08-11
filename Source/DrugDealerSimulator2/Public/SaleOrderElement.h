#pragma once
#include "CoreMinimal.h"
#include "SaleOrderElement.generated.h"

USTRUCT(BlueprintType)
struct FSaleOrderElement {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName OrderDrug;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 OrderQuantity;
    
    DRUGDEALERSIMULATOR2_API FSaleOrderElement();
};

