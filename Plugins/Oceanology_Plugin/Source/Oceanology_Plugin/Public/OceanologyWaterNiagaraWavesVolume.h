#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Volume.h"
#include "OceanologyWaterNiagaraWavesVolume.generated.h"

class AOceanologyWaterParent;
class UNiagaraComponent;
class UNiagaraSystem;

UCLASS(Blueprintable)
class OCEANOLOGY_PLUGIN_API AOceanologyWaterNiagaraWavesVolume : public AVolume {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UNiagaraComponent* NiagaraWavesComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AOceanologyWaterParent* OceanologyWater;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UNiagaraSystem* NiagaraWaves;
    
    AOceanologyWaterNiagaraWavesVolume(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void ReloadSettings();
    
    UFUNCTION(BlueprintCallable)
    void DebugBounds();
    
};

