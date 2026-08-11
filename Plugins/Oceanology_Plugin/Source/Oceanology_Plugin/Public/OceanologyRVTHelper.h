#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "OceanologyRVT.h"
#include "OceanologyRVTHelper.generated.h"

class UMaterialInstanceDynamic;

UCLASS(Blueprintable)
class UOceanologyRVTHelper : public UObject {
    GENERATED_BODY()
public:
    UOceanologyRVTHelper();

    UFUNCTION(BlueprintCallable)
    static void SetMaterialParameters(UMaterialInstanceDynamic* Mid, const FOceanologyRVT& RVT);
    
    UFUNCTION(BlueprintPure)
    static void LerpRVT(const FOceanologyRVT& A, const FOceanologyRVT& B, const double Alpha, FOceanologyRVT& OutResult);
    
};

