#pragma once
#include "CoreMinimal.h"
#include "GearBrakeSignatureDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGearBrakeSignature, bool, State);

