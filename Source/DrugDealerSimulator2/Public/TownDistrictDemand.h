#pragma once
#include "CoreMinimal.h"
#include "TownDistrictDemand.generated.h"

USTRUCT(BlueprintType)
struct FTownDistrictDemand {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CurUnlockDemand;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, float> CurDrugDemand;
    
    DRUGDEALERSIMULATOR2_API FTownDistrictDemand();
};

