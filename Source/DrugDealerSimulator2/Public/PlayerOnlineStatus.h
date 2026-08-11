#pragma once
#include "CoreMinimal.h"
#include "PlayerOnlineStatus.generated.h"

USTRUCT(BlueprintType)
struct FPlayerOnlineStatus {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString PlayerID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool PlayerOnline;
    
    DRUGDEALERSIMULATOR2_API FPlayerOnlineStatus();
};

