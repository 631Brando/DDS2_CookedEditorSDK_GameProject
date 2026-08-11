#pragma once
#include "CoreMinimal.h"
#include "GearInputSignatureDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGearInputSignature, float, deltaTime);

