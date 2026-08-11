#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "OceanologyVolumetricFog.h"
#include "OceanologyVolumetricFogHelper.generated.h"

class UMaterialInstanceDynamic;

UCLASS(Blueprintable)
class UOceanologyVolumetricFogHelper : public UObject {
    GENERATED_BODY()
public:
    UOceanologyVolumetricFogHelper();

    UFUNCTION(BlueprintCallable)
    static void SetMaterialParameters(UMaterialInstanceDynamic* Mid, const FOceanologyVolumetricFog& VolumetricFog);
    
    UFUNCTION(BlueprintPure)
    static void LerpVolumetricFog(const FOceanologyVolumetricFog& A, const FOceanologyVolumetricFog& B, const double Alpha, FOceanologyVolumetricFog& OutResult);
    
};

