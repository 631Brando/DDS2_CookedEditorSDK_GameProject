#pragma once
#include "CoreMinimal.h"
#include "RamaSavePreLoadDestroySignatureDelegate.generated.h"

class URamaSaveComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FRamaSavePreLoadDestroySignature, URamaSaveComponent*, RamaSaveComponent);

