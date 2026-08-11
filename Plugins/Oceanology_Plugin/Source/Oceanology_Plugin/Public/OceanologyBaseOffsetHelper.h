#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "OceanologyBaseOffset.h"
#include "OceanologyBaseOffsetHelper.generated.h"

class UMaterialInstanceDynamic;
class UMaterialParameterCollectionInstance;
class UNiagaraComponent;

UCLASS(Blueprintable)
class UOceanologyBaseOffsetHelper : public UObject {
    GENERATED_BODY()
public:
    UOceanologyBaseOffsetHelper();

    UFUNCTION(BlueprintCallable)
    static void SetNiagaraVariables(UNiagaraComponent* Niagara, const FOceanologyBaseOffset& BaseOffset);
    
    UFUNCTION(BlueprintCallable)
    static void SetMaterialParameters(UMaterialInstanceDynamic* Mid, const FOceanologyBaseOffset& BaseOffset);
    
    UFUNCTION(BlueprintCallable)
    static void SetMaterialParameterCollections(UMaterialParameterCollectionInstance* MPCI, const FOceanologyBaseOffset& BaseOffset);
    
    UFUNCTION(BlueprintPure)
    static void LerpBaseOffset(const FOceanologyBaseOffset& A, const FOceanologyBaseOffset& B, const double Alpha, FOceanologyBaseOffset& OutResult);
    
};

