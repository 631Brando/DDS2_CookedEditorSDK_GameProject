#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/Actor.h"
#include "OceanologyActorHeight.h"
#include "OceanologyCaustics.h"
#include "OceanologyFlipbook.h"
#include "OceanologyFoam.h"
#include "OceanologyFolding.h"
#include "OceanologyGGX.h"
#include "OceanologyHorizonCorrection.h"
#include "OceanologyMask.h"
#include "OceanologyProcedural.h"
#include "OceanologyRVT.h"
#include "OceanologyRefraction.h"
#include "OceanologySurfaceScattering.h"
#include "Templates/SubclassOf.h"
#include "OceanologyWaterParent.generated.h"

class UBoxComponent;
class UMaterialInstanceDynamic;
class UMaterialInterface;
class UNiagaraComponent;
class UOceanologyUnderwaterComponent;
class UOceanologyWaterMeshComponent;
class UOceanologyWaveSolverComponent;
class UPostProcessComponent;
class USceneComponent;
class UStaticMeshComponent;
class UTexture;

UCLASS(Abstract, Blueprintable)
class OCEANOLOGY_PLUGIN_API AOceanologyWaterParent : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, NonTransactional, meta=(AllowPrivateAccess=true))
    USceneComponent* DefaultSceneRoot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UOceanologyWaterMeshComponent* WaterMeshComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UBoxComponent* UnderwaterBoxVolumeComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPostProcessComponent* UnderwaterPostProcessComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UOceanologyUnderwaterComponent* UnderwaterComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* VolumetricFogMeshComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UNiagaraComponent* BubblesComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UOceanologyWaveSolverComponent> WaveSolverClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UOceanologyWaveSolverComponent* WaveSolver;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool DebugEnabled;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    FOceanologySurfaceScattering SurfaceScattering;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    FOceanologyCaustics Caustics;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    FOceanologyRefraction Refraction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    FOceanologyHorizonCorrection HorizonCorrection;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    FOceanologyFlipbook flipbook;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    FOceanologyFoam Foam;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    FOceanologyFolding Folding;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    FOceanologyProcedural Procedural;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    FOceanologyRVT RVT;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    FOceanologyMask Mask;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    FOceanologyActorHeight ActorHeight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    FOceanologyGGX GGX;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool UserOverrideMaterial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* Material;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* MaterialFar;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, NonPIEDuplicateTransient, TextExportTransient, Transient, meta=(AllowPrivateAccess=true))
    UMaterialInstanceDynamic* WaterMID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, NonPIEDuplicateTransient, TextExportTransient, Transient, meta=(AllowPrivateAccess=true))
    UMaterialInstanceDynamic* WaterFarDistanceMID;
    
public:
    AOceanologyWaterParent(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    void SetWaterMaterialParameters(UMaterialInstanceDynamic* Mid) const;
    
    UFUNCTION(BlueprintCallable)
    void SetVectorParameterValue(const FName ParameterName, const FLinearColor Value);
    
    UFUNCTION(BlueprintCallable)
    bool SetupWaveSolvers();
    
    UFUNCTION(BlueprintCallable)
    void SetTextureParameterValue(const FName ParameterName, UTexture* Value);
    
    UFUNCTION(BlueprintCallable)
    void SetScalarParameterValue(const FName ParameterName, const double Value);
    
    UFUNCTION(BlueprintCallable)
    void ReloadSettings();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void InitSurface();
    
    UFUNCTION(BlueprintCallable)
    TSubclassOf<UOceanologyWaveSolverComponent> GetWaveSolverClass();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UOceanologyWaveSolverComponent* GetWaveSolver() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector GetWaveHeightAtLocation(const FVector& Location);
    
    UFUNCTION(BlueprintCallable)
    UMaterialInstanceDynamic* GetWaterMID();
    
    UFUNCTION(BlueprintCallable)
    UMaterialInstanceDynamic* GetWaterFarDistanceMID();
    
    UFUNCTION(BlueprintPure)
    double GetWaterDensity(const AActor* Actor);
    
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    bool GetValidWaveSolverByClass(TSubclassOf<UOceanologyWaveSolverComponent> InWaveSolverClass, UOceanologyWaveSolverComponent*& OutWaveSolver) const;
    
    UFUNCTION(BlueprintCallable)
    void CreateOrUpdateWaterMID();
    
    UFUNCTION(BlueprintCallable)
    void CreateOrUpdateWaterFarDistanceMID();
    
};

