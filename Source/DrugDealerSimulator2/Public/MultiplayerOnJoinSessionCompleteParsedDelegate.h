#pragma once
#include "CoreMinimal.h"
#include "MultiplayerOnJoinSessionCompleteParsedDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FMultiplayerOnJoinSessionCompleteParsed, bool, bWasSuccessful);

