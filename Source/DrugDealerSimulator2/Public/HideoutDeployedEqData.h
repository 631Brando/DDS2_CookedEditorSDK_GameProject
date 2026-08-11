#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "HideoutDeployedEqData.generated.h"

USTRUCT(BlueprintType)
struct FHideoutDeployedEqData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName EquipmentID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTransform RelativeTransform;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool DefaultEq;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString EqInventory;
    
    DRUGDEALERSIMULATOR2_API FHideoutDeployedEqData();
};

