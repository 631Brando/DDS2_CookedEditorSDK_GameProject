#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "OceanologyMaskUnderwater.h"
#include "OceanologyMaskUnderwaterHelper.generated.h"

class UMaterialInstanceDynamic;

UCLASS(Blueprintable)
class UOceanologyMaskUnderwaterHelper : public UObject {
    GENERATED_BODY()
public:
    UOceanologyMaskUnderwaterHelper();

    UFUNCTION(BlueprintCallable)
    static void SetMaterialParameters(UMaterialInstanceDynamic* Mid, const FOceanologyMaskUnderwater& MaskUnderwater);
    
    UFUNCTION(BlueprintPure)
    static void LerpMaskUnderwater(const FOceanologyMaskUnderwater& A, const FOceanologyMaskUnderwater& B, const double Alpha, FOceanologyMaskUnderwater& OutResult);
    
};

