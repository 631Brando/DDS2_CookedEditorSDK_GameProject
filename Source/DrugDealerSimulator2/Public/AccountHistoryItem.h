#pragma once
#include "CoreMinimal.h"
#include "AccountHistoryItem.generated.h"

USTRUCT(BlueprintType)
struct FAccountHistoryItem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString PaymentName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PaymentAmount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName PaymentType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString PaymentDetails;
    
    DRUGDEALERSIMULATOR2_API FAccountHistoryItem();
};

