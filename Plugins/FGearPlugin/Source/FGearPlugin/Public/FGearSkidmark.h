#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FGearSkidmark.generated.h"

UCLASS(Blueprintable, NotPlaceable)
class FGEARPLUGIN_API AFGearSkidmark : public AActor {
    GENERATED_BODY()
public:
    AFGearSkidmark(const FObjectInitializer& ObjectInitializer);

};

