#pragma once
#include "CoreMinimal.h"
#include "OceanologyRefraction.generated.h"

USTRUCT(BlueprintType)
struct FOceanologyRefraction {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double CriticalAngleBendWidth;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double CriticalAngleDot;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double CriticalAngleWidth;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double LipRefraction;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double RefractionBottomAmount;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double RefractionDownsampleFactor;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double RefractionNear;
    
    OCEANOLOGY_PLUGIN_API FOceanologyRefraction();
};

