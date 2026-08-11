#pragma once
#include "CoreMinimal.h"
#include "OceanologyGlobalDisplacement.generated.h"

USTRUCT(BlueprintType)
struct FOceanologyGlobalDisplacement {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double SizeM;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double OverallLength;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double GlobalAmplitude;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double GlobalSpeed;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double Choppiness;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double GlobalWaveDirection;
    
    OCEANOLOGY_PLUGIN_API FOceanologyGlobalDisplacement();
};

