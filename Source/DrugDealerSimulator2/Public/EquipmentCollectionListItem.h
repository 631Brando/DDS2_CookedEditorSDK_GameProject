#pragma once
#include "CoreMinimal.h"
#include "EquipmentOfferEntry.h"
#include "EquipmentCollectionListItem.generated.h"

USTRUCT(BlueprintType)
struct FEquipmentCollectionListItem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName EquipmentID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEquipmentOfferEntry OfferEntry;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 OfferShopPrice;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 CollectionQuantity;
    
    DRUGDEALERSIMULATOR2_API FEquipmentCollectionListItem();
};

