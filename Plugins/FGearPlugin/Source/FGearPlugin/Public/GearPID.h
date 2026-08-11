#pragma once
#include "CoreMinimal.h"
#include "GearPID.generated.h"

USTRUCT(BlueprintType)
struct FGearPID {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mKp;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mKi;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mKd;
    
    FGEARPLUGIN_API FGearPID();
};

