#pragma once
#include "CoreMinimal.h"
#include "OceanologyProcedural.generated.h"

USTRUCT(BlueprintType)
struct FOceanologyProcedural {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double NoiseTiling;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double Turbulance;
    
    OCEANOLOGY_PLUGIN_API FOceanologyProcedural();
};

