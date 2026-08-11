#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MixProportions.h"
#include "DrugMixListItem.generated.h"

USTRUCT(BlueprintType)
struct FDrugMixListItem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGuid MixGuid;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMixProportions MixProportions;
    
    DRUGDEALERSIMULATOR2_API FDrugMixListItem();
};

