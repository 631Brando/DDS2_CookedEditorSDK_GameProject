#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RiverologyLandscapeStruct.h"
#include "Riverology.generated.h"

class USceneComponent;
class USplineComponent;

UCLASS(Blueprintable)
class RIVEROLOGY_PLUGIN_API ARiverology : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* Root;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USplineComponent* SplineComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRiverologyLandscapeStruct RiverologyLandscape;
    
    ARiverology(const FObjectInitializer& ObjectInitializer);

};

