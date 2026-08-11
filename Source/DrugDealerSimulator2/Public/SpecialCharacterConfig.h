#pragma once
#include "CoreMinimal.h"
#include "SpecialCharacterConfig.generated.h"

USTRUCT(BlueprintType)
struct FSpecialCharacterConfig {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MinTownReputationLevel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ObtainChance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ReputationLoopPool;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName UnlockRequired;
    
    DRUGDEALERSIMULATOR2_API FSpecialCharacterConfig();
};

