#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "OceanologyHorizonCorrection.h"
#include "OceanologyHorizonCorrectionHelper.generated.h"

class UMaterialInstanceDynamic;

UCLASS(Blueprintable)
class UOceanologyHorizonCorrectionHelper : public UObject {
    GENERATED_BODY()
public:
    UOceanologyHorizonCorrectionHelper();

    UFUNCTION(BlueprintCallable)
    static void SetMaterialParameters(UMaterialInstanceDynamic* Mid, const FOceanologyHorizonCorrection& HorizonCorrection);
    
    UFUNCTION(BlueprintPure)
    static void LerpHorizonCorrection(const FOceanologyHorizonCorrection& A, const FOceanologyHorizonCorrection& B, const double Alpha, FOceanologyHorizonCorrection& OutResult);
    
};

