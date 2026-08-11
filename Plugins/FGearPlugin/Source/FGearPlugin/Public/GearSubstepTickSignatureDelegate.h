#pragma once
#include "CoreMinimal.h"
#include "GearSubstepTickSignatureDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGearSubstepTickSignature, float, deltaTime);

