#pragma once
#include "CoreMinimal.h"
#include "RamaPlayerLoadedSignatureDelegate.generated.h"

class APawn;
class APlayerController;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FRamaPlayerLoadedSignature, APlayerController*, PC, APawn*, Pawn, int32, PlayerIndex);

