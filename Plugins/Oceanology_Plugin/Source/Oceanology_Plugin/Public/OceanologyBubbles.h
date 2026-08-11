#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "OceanologyBubbles.generated.h"

USTRUCT(BlueprintType)
struct FOceanologyBubbles {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor BubbleColor;
    
    OCEANOLOGY_PLUGIN_API FOceanologyBubbles();
};

