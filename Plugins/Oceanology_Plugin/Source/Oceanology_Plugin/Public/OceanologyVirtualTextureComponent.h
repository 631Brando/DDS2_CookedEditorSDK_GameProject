#pragma once
#include "CoreMinimal.h"
#include "Components/RuntimeVirtualTextureComponent.h"
#include "OceanologyVirtualTextureComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UOceanologyVirtualTextureComponent : public URuntimeVirtualTextureComponent {
    GENERATED_BODY()
public:
    UOceanologyVirtualTextureComponent(const FObjectInitializer& ObjectInitializer);

};

