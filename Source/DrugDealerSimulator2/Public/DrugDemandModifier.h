#pragma once
#include "CoreMinimal.h"
#include "DrugDemandModifier.generated.h"

USTRUCT(BlueprintType)
struct FDrugDemandModifier {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DemandModifier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CompetitionDemandLevel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CompetitionModifier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName CompetitionEventID;
    
    DRUGDEALERSIMULATOR2_API FDrugDemandModifier();
};

