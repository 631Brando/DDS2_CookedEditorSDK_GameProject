#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "OceanologyWetness.h"
#include "OceanologyWetnessHelper.generated.h"

class UMaterialInstanceDynamic;

UCLASS(Blueprintable)
class UOceanologyWetnessHelper : public UObject {
    GENERATED_BODY()
public:
    UOceanologyWetnessHelper();

    UFUNCTION(BlueprintCallable)
    static void SetMaterialParameters(UMaterialInstanceDynamic* Mid, const FOceanologyWetness& Wetness);
    
    UFUNCTION(BlueprintPure)
    static void LerpWetness(const FOceanologyWetness& A, const FOceanologyWetness& B, const double Alpha, FOceanologyWetness& OutResult);
    
};

