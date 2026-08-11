#pragma once
#include "CoreMinimal.h"
#include "OneRecordedMessage.generated.h"

USTRUCT(BlueprintType)
struct FOneRecordedMessage {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName MessageID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool Played;
    
    DRUGDEALERSIMULATOR2_API FOneRecordedMessage();
};

