#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "OceanologyWaterProjection.h"
#include "OceanologyWaterProjectionHelper.generated.h"

class UMaterialInstanceDynamic;

UCLASS(Blueprintable)
class UOceanologyWaterProjectionHelper : public UObject {
    GENERATED_BODY()
public:
    UOceanologyWaterProjectionHelper();

    UFUNCTION(BlueprintCallable)
    static void SetMaterialParameters(UMaterialInstanceDynamic* Mid, const FOceanologyWaterProjection& WaterProjection);
    
    UFUNCTION(BlueprintPure)
    static void LerpWaterProjection(const FOceanologyWaterProjection& A, const FOceanologyWaterProjection& B, const double Alpha, FOceanologyWaterProjection& OutResult);
    
};

