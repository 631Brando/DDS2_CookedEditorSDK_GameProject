#include "OceanologyWaterVolume.h"
#include "Net/UnrealNetwork.h"

AOceanologyWaterVolume::AOceanologyWaterVolume(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bEnableAutoLODGeneration = false;
    this->bReplicates = true;
    const FProperty* p_RemoteRole = GetClass()->FindPropertyByName("RemoteRole");
    (*p_RemoteRole->ContainerPtrToValuePtr<TEnumAsByte<ENetRole>>(this)) = ROLE_SimulatedProxy;
    this->DebugEnabled = false;
    this->OceanologyWater = NULL;
    this->CheckInitialOverlapOnBeginPlay = true;
    this->InitialOverlapOnBeginPlayDelay = 0.50f;
    this->EnableBuoyancyInArea = true;
    this->EnableSwimmingInArea = true;
    this->PhysicsVolumeTerminalVelocity = 4000.00f;
    this->PhysicsVolumePriority = 0;
    this->PhysicsVolumeFluidFriction = 0.30f;
}

void AOceanologyWaterVolume::Server_ChangeOverlapStatus_Implementation(const AActor* OtherActor, const bool Active) {
}

void AOceanologyWaterVolume::RegisterOverlapEvents() {
}

void AOceanologyWaterVolume::OnVolume_EndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) {
}

void AOceanologyWaterVolume::OnVolume_BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
}

void AOceanologyWaterVolume::NetMulticast_ChangeOverlapStatus_Implementation(const AActor* OtherActor, const bool Active) {
}

void AOceanologyWaterVolume::InitialOverlappingCheck() {
}

void AOceanologyWaterVolume::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(AOceanologyWaterVolume, OceanologyWater);
}


