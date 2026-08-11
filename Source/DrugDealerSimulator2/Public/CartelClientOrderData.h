#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CartelClientOrderData.generated.h"

USTRUCT(BlueprintType)
struct FCartelClientOrderData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, int32> OrderContent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 CurOrderStatus;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGuid OrderSaleSpot;
    
    DRUGDEALERSIMULATOR2_API FCartelClientOrderData();
};

