#pragma once
#include "CoreMinimal.h"
#include "OceanologyWave_4.generated.h"

USTRUCT(BlueprintType)
struct FOceanologyWave_4 {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double Amplitude_4;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double Steepness_4;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double Speed_4;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double WaveLength_4;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double Direction_4;
    
    OCEANOLOGY_PLUGIN_API FOceanologyWave_4();
};

