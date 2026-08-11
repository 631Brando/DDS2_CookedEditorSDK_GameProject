#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "OceanologyActorHeight.h"
#include "OceanologyActorHeightHelper.generated.h"

class UMaterialInstanceDynamic;

UCLASS(Blueprintable)
class UOceanologyActorHeightHelper : public UObject {
    GENERATED_BODY()
public:
    UOceanologyActorHeightHelper();

    UFUNCTION(BlueprintCallable)
    static void SetMaterialParameters(UMaterialInstanceDynamic* Mid, const FOceanologyActorHeight& ActorHeight);
    
    UFUNCTION(BlueprintPure)
    static void LerpActorHeight(const FOceanologyActorHeight& A, const FOceanologyActorHeight& B, const double Alpha, FOceanologyActorHeight& OutResult);
    
};

