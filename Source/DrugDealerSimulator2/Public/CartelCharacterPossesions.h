#pragma once
#include "CoreMinimal.h"
#include "SubstanceContentsData.h"
#include "CartelCharacterPossesions.generated.h"

USTRUCT(BlueprintType)
struct FCartelCharacterPossesions {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 PossesedCash;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FSubstanceContentsData> PossesedSubstances;
    
    DRUGDEALERSIMULATOR2_API FCartelCharacterPossesions();
};

