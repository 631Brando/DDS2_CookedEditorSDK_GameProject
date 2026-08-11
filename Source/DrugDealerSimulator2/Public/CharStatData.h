#pragma once
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "CharStatData.generated.h"

USTRUCT(BlueprintType)
struct FCharStatData : public FTableRowBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName StatID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float StatValue;
    
    DRUGDEALERSIMULATOR2_API FCharStatData();
};

