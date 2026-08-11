#pragma once
#include "CoreMinimal.h"
#include "OceanOnDrowningTaskDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOceanOnDrowningTask, int32, TimeDrowningInSeconds);

