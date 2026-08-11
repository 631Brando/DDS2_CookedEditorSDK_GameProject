#pragma once
#include "CoreMinimal.h"
#include "OceanologyBaseOffset.generated.h"

USTRUCT(BlueprintType)
struct FOceanologyBaseOffset {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double Amplitude;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double Steepness;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double Speed;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double WaveLength;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double Direction;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double Direction_Offset;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double Direction_Offset2;
    
    OCEANOLOGY_PLUGIN_API FOceanologyBaseOffset();
};

