#pragma once
#include "CoreMinimal.h"
#include "FindSessionsCallbackProxy.h"
#include "OnFindSessionAllSessionsCompleteDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnFindSessionAllSessionsComplete, bool, bWasSuccessful, const TArray<FBlueprintSessionResult>&, BlueprintSessionSearchResultsArray);

