#pragma once
#include "CoreMinimal.h"
#include "TimeData.generated.h"

USTRUCT(BlueprintType)
struct FTimeData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 TimeDay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 TimeHour;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 TimeMinute;
    
    DRUGDEALERSIMULATOR2_API FTimeData();
};

