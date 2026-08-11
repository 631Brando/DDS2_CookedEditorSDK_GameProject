#include "OceanologyLake.h"
#include "OceanologyWaterMeshComponent.h"
#include "Components/DecalComponent.h"
#include "Net/UnrealNetwork.h"
#include "OceanAudioComponent.h"

AOceanologyLake::AOceanologyLake(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->OceanAudioUnderwaterComponent = CreateDefaultSubobject<UOceanAudioComponent>(TEXT("OceanAudioUnderwater"));
    this->OceanAudioWaveComponent = CreateDefaultSubobject<UOceanAudioComponent>(TEXT("OceanAudioWave"));
    this->CausticsComponent = CreateDefaultSubobject<UDecalComponent>(TEXT("Caustics"));
    this->Preset = NULL;
    this->PresetMode = EOceanologyWaterPresetMode::UsePresetDirectly;
    this->PresetInclusionGroups.AddDefaulted(24);
    this->EnableCausticsOnGround = true;
    this->CausticsMaterial = NULL;
    this->CausticsMID = NULL;
    this->CausticsComponent->SetupAttachment(WaterMeshComponent);
    this->OceanAudioUnderwaterComponent->SetupAttachment(RootComponent);
    this->OceanAudioWaveComponent->SetupAttachment(RootComponent);
}

void AOceanologyLake::RegisterUnderwaterOverlapEvents() {
}

void AOceanologyLake::OnUnderwater_EndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) {
}

void AOceanologyLake::OnUnderwater_BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
}

void AOceanologyLake::LoadPreset(UOceanologyLakePreset* InPreset) {
}

void AOceanologyLake::InitCaustics() {
}

void AOceanologyLake::InitAudio() {
}

UMaterialInstanceDynamic* AOceanologyLake::GetCausticsMID() {
    return NULL;
}

void AOceanologyLake::CreateOrUpdateCausticsMID() {
}

void AOceanologyLake::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(AOceanologyLake, GroundCaustics);
    DOREPLIFETIME(AOceanologyLake, WaterProjection);
}


