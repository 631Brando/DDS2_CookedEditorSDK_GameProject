#pragma once
#include "CoreMinimal.h"
#include "OceanOnExitedWaterDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOceanOnExitedWater, FName, Socket, bool, Underwater);

