#pragma once
#include "CoreMinimal.h"
#include "Components/SkeletalMeshComponent.h"
#include "GearSubstepTickSignatureDelegate.h"
#include "FGearSkeletalMeshComponent.generated.h"

UCLASS(Blueprintable, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class FGEARPLUGIN_API UFGearSkeletalMeshComponent : public USkeletalMeshComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGearSubstepTickSignature OnSubstepTick;
    
    UFGearSkeletalMeshComponent(const FObjectInitializer& ObjectInitializer);

};

