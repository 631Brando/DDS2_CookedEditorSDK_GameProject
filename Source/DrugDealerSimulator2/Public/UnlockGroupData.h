#pragma once
#include "CoreMinimal.h"
#include "UnlockGroupData.generated.h"

USTRUCT(BlueprintType)
struct FUnlockGroupData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, FString> ListData;
    
    DRUGDEALERSIMULATOR2_API FUnlockGroupData();
};

