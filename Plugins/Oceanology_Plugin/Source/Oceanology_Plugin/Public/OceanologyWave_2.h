#pragma once
#include "CoreMinimal.h"
#include "OceanologyWave_2.generated.h"

USTRUCT(BlueprintType)
struct FOceanologyWave_2 {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double Amplitude_2;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double Steepness_2;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double Speed_2;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double WaveLength_2;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double Direction_2;
    
    OCEANOLOGY_PLUGIN_API FOceanologyWave_2();
};

