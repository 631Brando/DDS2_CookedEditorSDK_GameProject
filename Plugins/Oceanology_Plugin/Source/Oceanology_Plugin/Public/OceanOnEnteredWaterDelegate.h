#pragma once
#include "CoreMinimal.h"
#include "OceanOnEnteredWaterDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOceanOnEnteredWater, FName, Socket, bool, Underwater);

