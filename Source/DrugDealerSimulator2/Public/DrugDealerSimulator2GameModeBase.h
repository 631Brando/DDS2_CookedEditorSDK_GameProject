#pragma once
#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GameFramework/OnlineReplStructs.h"
#include "DrugDealerSimulator2GameModeBase.generated.h"

UCLASS(Blueprintable, NonTransient)
class DRUGDEALERSIMULATOR2_API ADrugDealerSimulator2GameModeBase : public AGameModeBase {
    GENERATED_BODY()
public:
    ADrugDealerSimulator2GameModeBase(const FObjectInitializer& ObjectInitializer);

protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void BP_PreLogin(const FString& Options, const FString& Address, const FUniqueNetIdRepl& UniqueID, FString& ErrorMessage);
    
};

