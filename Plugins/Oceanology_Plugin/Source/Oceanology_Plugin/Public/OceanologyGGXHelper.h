#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "OceanologyGGX.h"
#include "OceanologyGGXHelper.generated.h"

class UMaterialInstanceDynamic;

UCLASS(Blueprintable)
class UOceanologyGGXHelper : public UObject {
    GENERATED_BODY()
public:
    UOceanologyGGXHelper();

    UFUNCTION(BlueprintCallable)
    static void SetMaterialParameters(UMaterialInstanceDynamic* Mid, const FOceanologyGGX& GGX);
    
    UFUNCTION(BlueprintPure)
    static void LerpGGX(const FOceanologyGGX& A, const FOceanologyGGX& B, const double Alpha, FOceanologyGGX& OutResult);
    
};

