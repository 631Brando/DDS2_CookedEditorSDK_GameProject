#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "OceanologyBubbles.h"
#include "OceanologyBubblesHelper.generated.h"

class UMaterialInstanceDynamic;

UCLASS(Blueprintable)
class UOceanologyBubblesHelper : public UObject {
    GENERATED_BODY()
public:
    UOceanologyBubblesHelper();

    UFUNCTION(BlueprintCallable)
    static void SetMaterialParameters(UMaterialInstanceDynamic* Mid, const FOceanologyBubbles& Bubbles);
    
    UFUNCTION(BlueprintPure)
    static void LerpBubbles(const FOceanologyBubbles& A, const FOceanologyBubbles& B, const double Alpha, FOceanologyBubbles& OutResult);
    
};

