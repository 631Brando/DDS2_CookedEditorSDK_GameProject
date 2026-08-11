#pragma once
#include "CoreMinimal.h"
#include "ProductionChainItem.generated.h"

USTRUCT(BlueprintType)
struct FProductionChainItem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText StepName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText StepDescription;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName StepMainProductID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> StepEquipmentList;
    
    DRUGDEALERSIMULATOR2_API FProductionChainItem();
};

