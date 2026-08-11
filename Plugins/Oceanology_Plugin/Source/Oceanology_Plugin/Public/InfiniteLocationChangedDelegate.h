#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "InfiniteLocationChangedDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FInfiniteLocationChanged, FVector, CameraLocation, FVector, LastLocation, FVector, NewParentLocation);

