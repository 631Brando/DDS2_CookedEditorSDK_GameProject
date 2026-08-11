#pragma once
#include "CoreMinimal.h"
#include "RamaSaveFullyLoadedSignatureDelegate.generated.h"

class URamaSaveComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FRamaSaveFullyLoadedSignature, URamaSaveComponent*, RamaSaveComponent, const FString&, LevelPackageName);

