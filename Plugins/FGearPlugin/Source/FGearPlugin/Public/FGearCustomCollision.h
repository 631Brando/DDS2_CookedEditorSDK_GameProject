#pragma once
#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "Components/StaticMeshComponent.h"
#include "FGearCustomCollision.generated.h"

UCLASS(Blueprintable, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class FGEARPLUGIN_API UFGearCustomCollision : public UStaticMeshComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool mOverrideChannel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<ECollisionChannel> mChannel;
    
public:
    UFGearCustomCollision(const FObjectInitializer& ObjectInitializer);

};

