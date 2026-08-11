#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DDS2CasinoSoundManagerSubsystemBase.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class DDS2CASINORUNTIME_API UDDS2CasinoSoundManagerSubsystemBase : public UActorComponent {
    GENERATED_BODY()
public:
    UDDS2CasinoSoundManagerSubsystemBase(const FObjectInitializer& ObjectInitializer);

};

