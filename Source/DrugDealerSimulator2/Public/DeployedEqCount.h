#pragma once
#include "CoreMinimal.h"
#include "DeployedEqCount.generated.h"

USTRUCT(BlueprintType)
struct FDeployedEqCount {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName EquipmentID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 EqInventory;
    
    DRUGDEALERSIMULATOR2_API FDeployedEqCount();
};

