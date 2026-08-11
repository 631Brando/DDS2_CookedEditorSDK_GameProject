#pragma once
#include "CoreMinimal.h"
#include "CharacterConfig.h"
#include "RandomClientData.generated.h"

USTRUCT(BlueprintType)
struct FRandomClientData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCharacterConfig CharacterConfig;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ClientReputation;
    
    DRUGDEALERSIMULATOR2_API FRandomClientData();
};

