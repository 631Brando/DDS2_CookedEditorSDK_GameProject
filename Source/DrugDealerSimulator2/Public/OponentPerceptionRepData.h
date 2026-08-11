#pragma once
#include "CoreMinimal.h"
#include "OponentPerceptionStats.h"
#include "OponentPerceptionRepData.generated.h"

class AActor;

USTRUCT(BlueprintType)
struct FOponentPerceptionRepData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AActor* ActorRef;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOponentPerceptionStats Stats;
    
    DRUGDEALERSIMULATOR2_API FOponentPerceptionRepData();
};

