#pragma once
#include "CoreMinimal.h"
#include "EOceanologyWaterPresetMode.h"
#include "OceanologyOceanQuadTreeSettings.h"
#include "OceanologyWaterParent.h"
#include "OceanologyWetness.h"
#include "OceanologyInfiniteOcean.generated.h"

class UDecalComponent;
class UMaterialInstanceDynamic;
class UMaterialInterface;
class UOceanAudioComponent;
class UOceanologyInfiniteComponent;
class UOceanologyOceanPreset;

UCLASS(Blueprintable)
class OCEANOLOGY_PLUGIN_API AOceanologyInfiniteOcean : public AOceanologyWaterParent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UOceanologyInfiniteComponent* InfiniteComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDecalComponent* DLWetnessComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UOceanAudioComponent* OceanAudioUnderwaterComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOceanologyOceanQuadTreeSettings QuadTreeSettings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UOceanologyOceanPreset* Preset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EOceanologyWaterPresetMode PresetMode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> PresetInclusionGroups;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool EnableWetness;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    FOceanologyWetness Wetness;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* ShorelineWetnessMaterial;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, NonPIEDuplicateTransient, TextExportTransient, Transient, meta=(AllowPrivateAccess=true))
    UMaterialInstanceDynamic* ShorelineWetnessMID;
    
public:
    AOceanologyInfiniteOcean(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

    UFUNCTION(BlueprintCallable)
    void LoadPreset(UOceanologyOceanPreset* InPreset);
    
    UFUNCTION(BlueprintCallable)
    void InitShorelineWetness();
    
    UFUNCTION(BlueprintCallable)
    UMaterialInstanceDynamic* GetShorelineWetnessMID();
    
    UFUNCTION(BlueprintCallable)
    void ForceFollow();
    
    UFUNCTION(BlueprintCallable)
    void CreateOrUpdateShorelineWetnessMID();
    
};

