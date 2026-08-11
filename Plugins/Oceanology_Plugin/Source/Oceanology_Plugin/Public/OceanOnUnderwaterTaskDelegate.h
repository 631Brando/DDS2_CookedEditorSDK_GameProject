#pragma once
#include "CoreMinimal.h"
#include "OceanOnUnderwaterTaskDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOceanOnUnderwaterTask, int32, TimeUnderwaterInSeconds);

