#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "OceanologyGlobalDisplacement.h"
#include "OceanologyGlobalDisplacementHelper.generated.h"

class UMaterialInstanceDynamic;
class UMaterialParameterCollectionInstance;
class UNiagaraComponent;

UCLASS(Blueprintable)
class UOceanologyGlobalDisplacementHelper : public UObject {
    GENERATED_BODY()
public:
    UOceanologyGlobalDisplacementHelper();

    UFUNCTION(BlueprintCallable)
    static void SetNiagaraVariables(UNiagaraComponent* Niagara, const FOceanologyGlobalDisplacement& GlobalDisplacement);
    
    UFUNCTION(BlueprintCallable)
    static void SetMaterialParameters(UMaterialInstanceDynamic* Mid, const FOceanologyGlobalDisplacement& GlobalDisplacement);
    
    UFUNCTION(BlueprintCallable)
    static void SetMaterialParameterCollections(UMaterialParameterCollectionInstance* MPCI, const FOceanologyGlobalDisplacement& GlobalDisplacement);
    
    UFUNCTION(BlueprintPure)
    static void LerpGlobalDisplacement(const FOceanologyGlobalDisplacement& A, const FOceanologyGlobalDisplacement& B, const double Alpha, FOceanologyGlobalDisplacement& OutResult);
    
};

