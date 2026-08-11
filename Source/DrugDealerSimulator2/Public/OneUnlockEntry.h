#pragma once
#include "CoreMinimal.h"
#include "OneUnlockEntry.generated.h"

USTRUCT(BlueprintType)
struct FOneUnlockEntry {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName UnlockGroupID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName UnlockID;
    
    DRUGDEALERSIMULATOR2_API FOneUnlockEntry();
};

