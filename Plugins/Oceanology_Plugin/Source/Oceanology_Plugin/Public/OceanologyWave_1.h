#pragma once
#include "CoreMinimal.h"
#include "OceanologyWave_1.generated.h"

USTRUCT(BlueprintType)
struct FOceanologyWave_1 {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double Amplitude_1;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double Steepness_1;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double Speed_1;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double WaveLength_1;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double Direction_1;
    
    OCEANOLOGY_PLUGIN_API FOceanologyWave_1();
};

