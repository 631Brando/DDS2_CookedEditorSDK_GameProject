#pragma once
#include "CoreMinimal.h"
#include "GearTransmissionSignatureDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FGearTransmissionSignature, int32, prev, int32, Next);

