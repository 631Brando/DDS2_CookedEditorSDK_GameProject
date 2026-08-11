#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "OceanologyCaustics.h"
#include "OceanologyCausticsHelper.generated.h"

class UMaterialInstanceDynamic;

UCLASS(Blueprintable)
class UOceanologyCausticsHelper : public UObject {
    GENERATED_BODY()
public:
    UOceanologyCausticsHelper();

    UFUNCTION(BlueprintCallable)
    static void SetMaterialParameters(UMaterialInstanceDynamic* Mid, const FOceanologyCaustics& Caustics);
    
    UFUNCTION(BlueprintPure)
    static void LerpCaustics(const FOceanologyCaustics& A, const FOceanologyCaustics& B, const double Alpha, FOceanologyCaustics& OutResult);
    
};

