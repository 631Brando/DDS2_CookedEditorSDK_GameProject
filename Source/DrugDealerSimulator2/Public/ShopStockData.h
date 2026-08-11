#pragma once
#include "CoreMinimal.h"
#include "ShopStockData.generated.h"

USTRUCT(BlueprintType)
struct FShopStockData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, int32> StockUsed;
    
    DRUGDEALERSIMULATOR2_API FShopStockData();
};

