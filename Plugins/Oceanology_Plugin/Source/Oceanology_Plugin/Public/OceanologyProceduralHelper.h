#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "OceanologyProcedural.h"
#include "OceanologyProceduralHelper.generated.h"

class UMaterialInstanceDynamic;

UCLASS(Blueprintable)
class UOceanologyProceduralHelper : public UObject {
    GENERATED_BODY()
public:
    UOceanologyProceduralHelper();

    UFUNCTION(BlueprintCallable)
    static void SetMaterialParameters(UMaterialInstanceDynamic* Mid, const FOceanologyProcedural& Procedural);
    
    UFUNCTION(BlueprintPure)
    static void LerpProcedural(const FOceanologyProcedural& A, const FOceanologyProcedural& B, const double Alpha, FOceanologyProcedural& OutResult);
    
};

