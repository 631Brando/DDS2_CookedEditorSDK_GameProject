#pragma once
#include "CoreMinimal.h"
#include "FindSessionsCallbackProxy.h"
#include "MultiplayerOnSessionInviteAcceptedCompleteDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FMultiplayerOnSessionInviteAcceptedComplete, const FBlueprintSessionResult&, AcceptedSessionInvite);

