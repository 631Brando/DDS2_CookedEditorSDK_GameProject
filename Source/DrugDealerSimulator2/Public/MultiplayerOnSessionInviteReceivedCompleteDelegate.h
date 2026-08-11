#pragma once
#include "CoreMinimal.h"
#include "FindSessionsCallbackProxy.h"
#include "MultiplayerOnSessionInviteReceivedCompleteDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FMultiplayerOnSessionInviteReceivedComplete, const FBlueprintSessionResult&, ReceivedSessionInvite);

