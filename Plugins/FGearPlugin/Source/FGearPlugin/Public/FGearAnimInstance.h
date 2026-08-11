#pragma once
#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "GearBoneAxle.h"
#include "FGearAnimInstance.generated.h"

UCLASS(Blueprintable, NonTransient)
class FGEARPLUGIN_API UFGearAnimInstance : public UAnimInstance {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FGearBoneAxle> axles;
    
    UFGearAnimInstance();

};

