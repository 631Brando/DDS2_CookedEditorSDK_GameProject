#pragma once
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "DDS2_PlayerController.generated.h"

class APawn;

UCLASS(Blueprintable)
class DRUGDEALERSIMULATOR2_API ADDS2_PlayerController : public APlayerController {
    GENERATED_BODY()
public:
    ADDS2_PlayerController(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ReceivePawnLeavingGame(APawn* aPawn);
    
};

