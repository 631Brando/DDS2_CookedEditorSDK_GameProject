#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "OceanologyFoam.h"
#include "OceanologyFoamHelper.generated.h"

class UMaterialInstanceDynamic;

UCLASS(Blueprintable)
class UOceanologyFoamHelper : public UObject {
    GENERATED_BODY()
public:
    UOceanologyFoamHelper();

    UFUNCTION(BlueprintCallable)
    static void SetMaterialParameters(UMaterialInstanceDynamic* Mid, const FOceanologyFoam& Foam);
    
    UFUNCTION(BlueprintPure)
    static void LerpFoam(const FOceanologyFoam& A, const FOceanologyFoam& B, const double Alpha, FOceanologyFoam& OutResult);
    
};

