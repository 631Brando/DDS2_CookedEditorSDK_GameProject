#pragma once
#include "CoreMinimal.h"
#include "GearBoneTransform.h"
#include "GearBoneAxle.generated.h"

USTRUCT(BlueprintType)
struct FGearBoneAxle {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGearBoneTransform Left;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGearBoneTransform Right;
    
    FGEARPLUGIN_API FGearBoneAxle();
};

