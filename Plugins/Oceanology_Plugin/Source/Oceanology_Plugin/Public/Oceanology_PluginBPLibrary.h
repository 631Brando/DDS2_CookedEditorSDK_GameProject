#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Oceanology_PluginBPLibrary.generated.h"

UCLASS(Blueprintable)
class UOceanology_PluginBPLibrary : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UOceanology_PluginBPLibrary();

    UFUNCTION(BlueprintCallable)
    static float Oceanology_PluginSampleFunction(float Param);
    
};

