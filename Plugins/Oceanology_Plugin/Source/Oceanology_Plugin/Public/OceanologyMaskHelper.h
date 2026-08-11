#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "OceanologyMask.h"
#include "OceanologyMaskHelper.generated.h"

class UMaterialInstanceDynamic;

UCLASS(Blueprintable)
class UOceanologyMaskHelper : public UObject {
    GENERATED_BODY()
public:
    UOceanologyMaskHelper();

    UFUNCTION(BlueprintCallable)
    static void SetMaterialParameters(UMaterialInstanceDynamic* Mid, const FOceanologyMask& Mask);
    
    UFUNCTION(BlueprintPure)
    static void LerpMask(const FOceanologyMask& A, const FOceanologyMask& B, const double Alpha, FOceanologyMask& OutResult);
    
};

