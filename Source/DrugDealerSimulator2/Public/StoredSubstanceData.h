#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "StoredSubstanceData.generated.h"

USTRUCT(BlueprintType)
struct FStoredSubstanceData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName SubstanceID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGuid MixGuid;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float StoredAmount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float StoredMaxAdd;
    
    DRUGDEALERSIMULATOR2_API FStoredSubstanceData();
};

