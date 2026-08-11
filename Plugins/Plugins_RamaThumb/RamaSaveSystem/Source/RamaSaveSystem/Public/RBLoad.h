#pragma once
#include "CoreMinimal.h"
#include "RBLoad.generated.h"

class UPrimitiveComponent;

USTRUCT(BlueprintType)
struct FRBLoad {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPrimitiveComponent* Comp;
    
    RAMASAVESYSTEM_API FRBLoad();
};

