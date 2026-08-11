#pragma once
#include "CoreMinimal.h"
#include "OceanologyGGX.generated.h"

USTRUCT(BlueprintType)
struct FOceanologyGGX {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double GGX;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double PhongReflection;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double SunReflectionAmount;
    
    OCEANOLOGY_PLUGIN_API FOceanologyGGX();
};

