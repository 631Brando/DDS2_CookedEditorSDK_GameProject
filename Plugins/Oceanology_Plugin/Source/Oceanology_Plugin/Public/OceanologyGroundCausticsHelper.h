#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "OceanologyGroundCaustics.h"
#include "OceanologyGroundCausticsHelper.generated.h"

class UMaterialInstanceDynamic;

UCLASS(Blueprintable)
class UOceanologyGroundCausticsHelper : public UObject {
    GENERATED_BODY()
public:
    UOceanologyGroundCausticsHelper();

    UFUNCTION(BlueprintCallable)
    static void SetMaterialParameters(UMaterialInstanceDynamic* Mid, const FOceanologyGroundCaustics& GroundCaustics);
    
    UFUNCTION(BlueprintPure)
    static void LerpGroundCaustics(const FOceanologyGroundCaustics& A, const FOceanologyGroundCaustics& B, const double Alpha, FOceanologyGroundCaustics& OutResult);
    
};

