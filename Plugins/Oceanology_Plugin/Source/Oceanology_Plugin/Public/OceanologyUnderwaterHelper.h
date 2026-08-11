#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "OceanologyUnderwater.h"
#include "OceanologyUnderwaterHelper.generated.h"

class UMaterialInstanceDynamic;

UCLASS(Blueprintable)
class UOceanologyUnderwaterHelper : public UObject {
    GENERATED_BODY()
public:
    UOceanologyUnderwaterHelper();

    UFUNCTION(BlueprintCallable)
    static void SetMaterialParameters(UMaterialInstanceDynamic* Mid, const FOceanologyUnderwater& Underwater);
    
    UFUNCTION(BlueprintPure)
    static void LerpUnderwater(const FOceanologyUnderwater& A, const FOceanologyUnderwater& B, const double Alpha, FOceanologyUnderwater& OutResult);
    
};

