#pragma once
#include "CoreMinimal.h"
#include "GearWakeSignatureDelegate.generated.h"

class AFGearVehicle;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGearWakeSignature, AFGearVehicle*, Vehicle);

