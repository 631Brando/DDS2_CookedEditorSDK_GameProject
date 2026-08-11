#pragma once
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "HideoutEquipmentTypeData.generated.h"

class UTexture2D;

USTRUCT(BlueprintType)
struct FHideoutEquipmentTypeData : public FTableRowBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText TypeName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText TypeDescription;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2D* TypeImage;
    
    DRUGDEALERSIMULATOR2_API FHideoutEquipmentTypeData();
};

