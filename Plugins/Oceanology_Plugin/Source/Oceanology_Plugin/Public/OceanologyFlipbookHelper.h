#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "OceanologyFlipbook.h"
#include "OceanologyFlipbookHelper.generated.h"

class UMaterialInstanceDynamic;

UCLASS(Blueprintable)
class UOceanologyFlipbookHelper : public UObject {
    GENERATED_BODY()
public:
    UOceanologyFlipbookHelper();

    UFUNCTION(BlueprintCallable)
    static void SetMaterialParameters(UMaterialInstanceDynamic* Mid, const FOceanologyFlipbook& flipbook);
    
    UFUNCTION(BlueprintPure)
    static void LerpFlipbook(const FOceanologyFlipbook& A, const FOceanologyFlipbook& B, const double Alpha, FOceanologyFlipbook& OutResult);
    
};

