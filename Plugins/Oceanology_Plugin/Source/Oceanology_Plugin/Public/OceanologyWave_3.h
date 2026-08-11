#pragma once
#include "CoreMinimal.h"
#include "OceanologyWave_3.generated.h"

USTRUCT(BlueprintType)
struct FOceanologyWave_3 {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double Amplitude_3;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double Steepness_3;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double Speed_3;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double WaveLength_3;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double Direction_3;
    
    OCEANOLOGY_PLUGIN_API FOceanologyWave_3();
};

