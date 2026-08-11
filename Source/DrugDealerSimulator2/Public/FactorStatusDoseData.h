#pragma once
#include "CoreMinimal.h"
#include "FactorStatusDoseData.generated.h"

USTRUCT(BlueprintType)
struct FFactorStatusDoseData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName StatusID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DoseAmount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DoseTimer;
    
    DRUGDEALERSIMULATOR2_API FFactorStatusDoseData();
};

