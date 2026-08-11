#pragma once
#include "CoreMinimal.h"
#include "FGearInputState.generated.h"

USTRUCT(BlueprintType)
struct FFGearInputState {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 mTick;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mThrottle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mSteer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mBrake;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mClutch;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    int8 mThrottleState;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    int8 mGear;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool mHandbrake;
    
    FGEARPLUGIN_API FFGearInputState();
};

