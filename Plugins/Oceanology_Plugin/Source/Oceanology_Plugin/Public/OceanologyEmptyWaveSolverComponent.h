#pragma once
#include "CoreMinimal.h"
#include "OceanologyWaveSolverComponent.h"
#include "OceanologyEmptyWaveSolverComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class OCEANOLOGY_PLUGIN_API UOceanologyEmptyWaveSolverComponent : public UOceanologyWaveSolverComponent {
    GENERATED_BODY()
public:
    UOceanologyEmptyWaveSolverComponent(const FObjectInitializer& ObjectInitializer);

};

