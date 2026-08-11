#pragma once
#include "CoreMinimal.h"
#include "SpecialClientConfig.generated.h"

USTRUCT(BlueprintType)
struct FSpecialClientConfig {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName RelatedDrugID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinDemand;
    
    DRUGDEALERSIMULATOR2_API FSpecialClientConfig();
};

