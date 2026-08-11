#pragma once
#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "FGearTelemetryDrawer.generated.h"

UCLASS(Abstract, Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class FGEARPLUGIN_API UFGearTelemetryDrawer : public USceneComponent {
    GENERATED_BODY()
public:
    UFGearTelemetryDrawer(const FObjectInitializer& ObjectInitializer);

};

