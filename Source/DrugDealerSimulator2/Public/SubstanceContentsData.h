#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SubstanceContentsData.generated.h"

USTRUCT(BlueprintType)
struct FSubstanceContentsData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName SubstanceID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGuid MixGuid;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float GramAmount;
    
    DRUGDEALERSIMULATOR2_API FSubstanceContentsData();
};

