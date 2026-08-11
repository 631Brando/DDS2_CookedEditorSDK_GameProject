#pragma once
#include "CoreMinimal.h"
#include "Styling/SlateColor.h"
#include "MixEntry.h"
#include "MixProportions.generated.h"

USTRUCT(BlueprintType)
struct FMixProportions {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText MixCustomName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSlateColor MixColorCode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString MixCreatorNetID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName SubstanceDrugID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FMixEntry> Proportions;
    
    DRUGDEALERSIMULATOR2_API FMixProportions();
};

