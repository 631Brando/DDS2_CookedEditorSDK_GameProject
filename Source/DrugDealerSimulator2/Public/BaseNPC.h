#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BaseNPC.generated.h"

UCLASS(Blueprintable)
class DRUGDEALERSIMULATOR2_API ABaseNPC : public ACharacter {
    GENERATED_BODY()
public:
    ABaseNPC(const FObjectInitializer& ObjectInitializer);

};

