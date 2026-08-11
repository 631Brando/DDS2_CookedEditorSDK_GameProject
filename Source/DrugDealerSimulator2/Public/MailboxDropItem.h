#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MailboxDropItem.generated.h"

USTRUCT(BlueprintType)
struct FMailboxDropItem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGuid CharGuid;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 DropAmount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Timer;
    
    DRUGDEALERSIMULATOR2_API FMailboxDropItem();
};

