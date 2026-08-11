#pragma once
#include "CoreMinimal.h"
#include "GameFramework/PhysicsVolume.h"
#include "OceanologySwimVolume.generated.h"

UCLASS(Blueprintable)
class OCEANOLOGY_PLUGIN_API AOceanologySwimVolume : public APhysicsVolume {
    GENERATED_BODY()
public:
    AOceanologySwimVolume(const FObjectInitializer& ObjectInitializer);

};

