#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "OceanologySurfaceScattering.h"
#include "OceanologySurfaceScatteringHelper.generated.h"

class UMaterialInstanceDynamic;

UCLASS(Blueprintable)
class UOceanologySurfaceScatteringHelper : public UObject {
    GENERATED_BODY()
public:
    UOceanologySurfaceScatteringHelper();

    UFUNCTION(BlueprintCallable)
    static void SetMaterialParameters(UMaterialInstanceDynamic* Mid, const FOceanologySurfaceScattering& SurfaceScattering);
    
    UFUNCTION(BlueprintPure)
    static void LerpSurfaceScattering(const FOceanologySurfaceScattering& A, const FOceanologySurfaceScattering& B, const double Alpha, FOceanologySurfaceScattering& OutResult);
    
};

