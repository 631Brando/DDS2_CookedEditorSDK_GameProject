#pragma once
#include "CoreMinimal.h"
#include "ReputationLevelSettings.generated.h"

USTRUCT(BlueprintType)
struct FReputationLevelSettings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LevelPointPool;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, float> UnlockedPropertyMap;
    
    DRUGDEALERSIMULATOR2_API FReputationLevelSettings();
};

