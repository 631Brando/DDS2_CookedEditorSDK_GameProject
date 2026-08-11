#include "OceanologyWaterParent.h"
#include "Components/BoxComponent.h"
#include "Components/PostProcessComponent.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
#include "NiagaraComponent.h"
#include "Net/UnrealNetwork.h"
#include "OceanologyUnderwaterComponent.h"
#include "OceanologyWaterMeshComponent.h"
#include "Templates/SubclassOf.h"

AOceanologyWaterParent::AOceanologyWaterParent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bEnableAutoLODGeneration = false;
    this->bReplicates = true;
    const FProperty* p_RemoteRole = GetClass()->FindPropertyByName("RemoteRole");
    (*p_RemoteRole->ContainerPtrToValuePtr<TEnumAsByte<ENetRole>>(this)) = ROLE_SimulatedProxy;
    this->RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultSceneRoot"));
    this->DefaultSceneRoot = (USceneComponent*)RootComponent;
    this->WaterMeshComponent = CreateDefaultSubobject<UOceanologyWaterMeshComponent>(TEXT("WaterMesh"));
    this->UnderwaterBoxVolumeComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("UnderwaterBoxVolume"));
    this->UnderwaterPostProcessComponent = CreateDefaultSubobject<UPostProcessComponent>(TEXT("UnderwaterPostProcess"));
    this->UnderwaterComponent = CreateDefaultSubobject<UOceanologyUnderwaterComponent>(TEXT("Underwater"));
    this->VolumetricFogMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VolumetricFogMesh"));
    this->BubblesComponent = CreateDefaultSubobject<UNiagaraComponent>(TEXT("Bubbles"));
    this->WaveSolverClass = NULL;
    this->WaveSolver = NULL;
    this->DebugEnabled = false;
    this->UserOverrideMaterial = false;
    this->Material = NULL;
    this->MaterialFar = NULL;
    this->WaterMID = NULL;
    this->WaterFarDistanceMID = NULL;
    this->BubblesComponent->SetupAttachment(RootComponent);
    this->UnderwaterBoxVolumeComponent->SetupAttachment(RootComponent);
    this->UnderwaterPostProcessComponent->SetupAttachment(UnderwaterBoxVolumeComponent);
    this->VolumetricFogMeshComponent->SetupAttachment(RootComponent);
    this->WaterMeshComponent->SetupAttachment(RootComponent);
}

void AOceanologyWaterParent::SetWaterMaterialParameters(UMaterialInstanceDynamic* Mid) const {
}

void AOceanologyWaterParent::SetVectorParameterValue(const FName ParameterName, const FLinearColor Value) {
}

bool AOceanologyWaterParent::SetupWaveSolvers() {
    return false;
}

void AOceanologyWaterParent::SetTextureParameterValue(const FName ParameterName, UTexture* Value) {
}

void AOceanologyWaterParent::SetScalarParameterValue(const FName ParameterName, const double Value) {
}

void AOceanologyWaterParent::ReloadSettings() {
}

void AOceanologyWaterParent::InitSurface_Implementation() {
}

TSubclassOf<UOceanologyWaveSolverComponent> AOceanologyWaterParent::GetWaveSolverClass() {
    return NULL;
}

UOceanologyWaveSolverComponent* AOceanologyWaterParent::GetWaveSolver() const {
    return NULL;
}

FVector AOceanologyWaterParent::GetWaveHeightAtLocation(const FVector& Location) {
    return FVector{};
}

UMaterialInstanceDynamic* AOceanologyWaterParent::GetWaterMID() {
    return NULL;
}

UMaterialInstanceDynamic* AOceanologyWaterParent::GetWaterFarDistanceMID() {
    return NULL;
}

double AOceanologyWaterParent::GetWaterDensity(const AActor* Actor) {
    return 0.0;
}

bool AOceanologyWaterParent::GetValidWaveSolverByClass(TSubclassOf<UOceanologyWaveSolverComponent> InWaveSolverClass, UOceanologyWaveSolverComponent*& OutWaveSolver) const {
    return false;
}

void AOceanologyWaterParent::CreateOrUpdateWaterMID() {
}

void AOceanologyWaterParent::CreateOrUpdateWaterFarDistanceMID() {
}

void AOceanologyWaterParent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(AOceanologyWaterParent, SurfaceScattering);
    DOREPLIFETIME(AOceanologyWaterParent, Caustics);
    DOREPLIFETIME(AOceanologyWaterParent, Refraction);
    DOREPLIFETIME(AOceanologyWaterParent, HorizonCorrection);
    DOREPLIFETIME(AOceanologyWaterParent, flipbook);
    DOREPLIFETIME(AOceanologyWaterParent, Foam);
    DOREPLIFETIME(AOceanologyWaterParent, Folding);
    DOREPLIFETIME(AOceanologyWaterParent, Procedural);
    DOREPLIFETIME(AOceanologyWaterParent, RVT);
    DOREPLIFETIME(AOceanologyWaterParent, Mask);
    DOREPLIFETIME(AOceanologyWaterParent, ActorHeight);
    DOREPLIFETIME(AOceanologyWaterParent, GGX);
}


