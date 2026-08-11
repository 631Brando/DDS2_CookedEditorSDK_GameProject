#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "OceanologyActorHeight.generated.h"

USTRUCT(BlueprintType)
struct FOceanologyActorHeight {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor LocationOffset;
    
    OCEANOLOGY_PLUGIN_API FOceanologyActorHeight();
};

