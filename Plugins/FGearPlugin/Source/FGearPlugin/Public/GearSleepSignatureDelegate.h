#pragma once
#include "CoreMinimal.h"
#include "GearSleepSignatureDelegate.generated.h"

class AFGearVehicle;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGearSleepSignature, AFGearVehicle*, Vehicle);

