#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "OceanologyRefraction.h"
#include "OceanologyRefractionHelper.generated.h"

class UMaterialInstanceDynamic;

UCLASS(Blueprintable)
class UOceanologyRefractionHelper : public UObject {
    GENERATED_BODY()
public:
    UOceanologyRefractionHelper();

    UFUNCTION(BlueprintCallable)
    static void SetMaterialParameters(UMaterialInstanceDynamic* Mid, const FOceanologyRefraction& Refraction);
    
    UFUNCTION(BlueprintPure)
    static void LerpRefraction(const FOceanologyRefraction& A, const FOceanologyRefraction& B, const double Alpha, FOceanologyRefraction& OutResult);
    
};

