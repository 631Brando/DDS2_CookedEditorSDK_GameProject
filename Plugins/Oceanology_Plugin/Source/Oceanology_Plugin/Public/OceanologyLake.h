#pragma once
#include "CoreMinimal.h"
#include "Engine/HitResult.h"
#include "EOceanologyWaterPresetMode.h"
#include "OceanologyGroundCaustics.h"
#include "OceanologyLakeQuadTreeSettings.h"
#include "OceanologyWaterParent.h"
#include "OceanologyWaterProjection.h"
#include "OceanologyLake.generated.h"

class AActor;
class UDecalComponent;
class UMaterialInstanceDynamic;
class UMaterialInterface;
class UOceanAudioComponent;
class UOceanologyLakePreset;
class UPrimitiveComponent;

UCLASS(Blueprintable)
class OCEANOLOGY_PLUGIN_API AOceanologyLake : public AOceanologyWaterParent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UOceanAudioComponent* OceanAudioUnderwaterComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UOceanAudioComponent* OceanAudioWaveComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDecalComponent* CausticsComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOceanologyLakeQuadTreeSettings QuadTreeSettings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UOceanologyLakePreset* Preset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EOceanologyWaterPresetMode PresetMode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> PresetInclusionGroups;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool EnableCausticsOnGround;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    FOceanologyGroundCaustics GroundCaustics;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    FOceanologyWaterProjection WaterProjection;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* CausticsMaterial;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, NonPIEDuplicateTransient, TextExportTransient, Transient, meta=(AllowPrivateAccess=true))
    UMaterialInstanceDynamic* CausticsMID;
    
public:
    AOceanologyLake(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

    UFUNCTION(BlueprintCallable)
    void RegisterUnderwaterOverlapEvents();
    
    UFUNCTION(BlueprintCallable)
    void OnUnderwater_EndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
    
    UFUNCTION(BlueprintCallable)
    void OnUnderwater_BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
    
    UFUNCTION(BlueprintCallable)
    void LoadPreset(UOceanologyLakePreset* InPreset);
    
    UFUNCTION(BlueprintCallable)
    void InitCaustics();
    
    UFUNCTION(BlueprintCallable)
    void InitAudio();
    
    UFUNCTION(BlueprintCallable)
    UMaterialInstanceDynamic* GetCausticsMID();
    
    UFUNCTION(BlueprintCallable)
    void CreateOrUpdateCausticsMID();
    
};

