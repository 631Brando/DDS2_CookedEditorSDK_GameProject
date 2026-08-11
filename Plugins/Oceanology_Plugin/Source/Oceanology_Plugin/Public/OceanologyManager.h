#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "OceanologyManager.generated.h"

class UBoxComponent;
class UOceanologyHeightmapComponent;
class UOceanologyVirtualTextureComponent;
class USceneComponent;

UCLASS(Blueprintable)
class OCEANOLOGY_PLUGIN_API AOceanologyManager : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, NonTransactional, meta=(AllowPrivateAccess=true))
    USceneComponent* DefaultSceneRoot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UOceanologyVirtualTextureComponent* HeightmapVirtualTextureComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UOceanologyHeightmapComponent* HeightmapComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<AActor> BoundsAlignActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bSetAllBoundsButton;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UBoxComponent* Box;
    
public:
    AOceanologyManager(const FObjectInitializer& ObjectInitializer);

};

