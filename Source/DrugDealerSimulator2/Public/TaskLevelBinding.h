#pragma once
#include "CoreMinimal.h"
#include "TaskLevelBinding.generated.h"

USTRUCT(BlueprintType)
struct FTaskLevelBinding {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName TaskID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 BindToLevel;
    
    DRUGDEALERSIMULATOR2_API FTaskLevelBinding();
};

