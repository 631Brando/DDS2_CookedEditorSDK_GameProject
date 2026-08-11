#pragma once
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "ItemSpecialTypeData.generated.h"

class UTexture2D;

USTRUCT(BlueprintType)
struct FItemSpecialTypeData : public FTableRowBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText TypeName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText TypeDescription;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2D* TypeIcon;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool CanPlaceQuickslot;
    
    DRUGDEALERSIMULATOR2_API FItemSpecialTypeData();
};

