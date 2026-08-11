#pragma once
#include "CoreMinimal.h"
#include "ShopOfferListItem.generated.h"

USTRUCT(BlueprintType)
struct FShopOfferListItem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ItemId;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 ItemCurStock;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 ItemCurPrice;
    
    DRUGDEALERSIMULATOR2_API FShopOfferListItem();
};

