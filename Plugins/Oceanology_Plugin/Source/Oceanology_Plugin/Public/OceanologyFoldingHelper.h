#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "OceanologyFolding.h"
#include "OceanologyFoldingHelper.generated.h"

class UMaterialInstanceDynamic;

UCLASS(Blueprintable)
class UOceanologyFoldingHelper : public UObject {
    GENERATED_BODY()
public:
    UOceanologyFoldingHelper();

    UFUNCTION(BlueprintCallable)
    static void SetMaterialParameters(UMaterialInstanceDynamic* Mid, const FOceanologyFolding& Folding);
    
    UFUNCTION(BlueprintPure)
    static void LerpFolding(const FOceanologyFolding& A, const FOceanologyFolding& B, const double Alpha, FOceanologyFolding& OutResult);
    
};

