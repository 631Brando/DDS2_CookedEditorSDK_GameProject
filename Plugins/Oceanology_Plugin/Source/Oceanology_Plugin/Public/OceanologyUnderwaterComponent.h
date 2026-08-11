#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "EOceanologyUnderwaterMode.h"
#include "OceanologyBubblesSettings.h"
#include "OceanologyMaskUnderwater.h"
#include "OceanologyUnderwater.h"
#include "OceanologyVolumetricFog.h"
#include "OceanologyWaterProjection.h"
#include "OceanologyUnderwaterComponent.generated.h"

class AOceanologyWaterParent;
class UMaterialInstanceDynamic;
class UMaterialInterface;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class OCEANOLOGY_PLUGIN_API UOceanologyUnderwaterComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    EOceanologyUnderwaterMode UnderwaterMode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    FOceanologyUnderwater Underwater;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    FOceanologyVolumetricFog VolumetricFog;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    FOceanologyMaskUnderwater MaskUnderwater;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    FOceanologyWaterProjection WaterProjection;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool UserOverrideUnderwaterMaterial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* UnderwaterMaterial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* VolumetricFogMaterial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    FOceanologyBubblesSettings BubblesSettings;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    AOceanologyWaterParent* OceanologyWater;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, NonPIEDuplicateTransient, TextExportTransient, Transient, meta=(AllowPrivateAccess=true))
    UMaterialInstanceDynamic* UnderwaterMID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, NonPIEDuplicateTransient, TextExportTransient, Transient, meta=(AllowPrivateAccess=true))
    UMaterialInstanceDynamic* VolumetricFogMID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, NonPIEDuplicateTransient, TextExportTransient, Transient, meta=(AllowPrivateAccess=true))
    UMaterialInstanceDynamic* BubblesMID;
    
public:
    UOceanologyUnderwaterComponent(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

    UFUNCTION(BlueprintCallable)
    void InitBubbles();
    
    UFUNCTION(BlueprintCallable)
    void Init();
    
    UFUNCTION(BlueprintCallable)
    UMaterialInstanceDynamic* GetVolumetricFogMID();
    
    UFUNCTION(BlueprintCallable)
    UMaterialInstanceDynamic* GetUnderwaterMID();
    
    UFUNCTION(BlueprintCallable)
    UMaterialInstanceDynamic* GetBubblesMID();
    
    UFUNCTION(BlueprintCallable)
    void CreateOrUpdateVolumetricFogMID();
    
    UFUNCTION(BlueprintCallable)
    void CreateOrUpdateUnderwaterMID();
    
    UFUNCTION(BlueprintCallable)
    void CreateOrUpdateBubblesMID();
    
};

