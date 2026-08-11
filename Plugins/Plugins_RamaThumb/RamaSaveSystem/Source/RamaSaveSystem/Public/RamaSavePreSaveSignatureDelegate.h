#pragma once
#include "CoreMinimal.h"
#include "RamaSavePreSaveSignatureDelegate.generated.h"

class URamaSaveComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FRamaSavePreSaveSignature, URamaSaveComponent*, RamaSaveComponent);

