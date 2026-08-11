#include "OceanBuoyancyComponent.h"
#include "Net/UnrealNetwork.h"

UOceanBuoyancyComponent::UOceanBuoyancyComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->BuoyancyUpdateInterval = 0.00f;
    this->DefaultMeshDensity = 700.00f;
    this->WaterFluidDensity = 1030.00f;
    this->WaterFluidLinearDamping = 1.00f;
    this->WaterFluidAngularDamping = 2.50f;
    this->LimitUnderwaterMaxVelocity = true;
    this->MaxUnderwaterVelocity = 100.00f;
    this->Pontoons.AddDefaulted(1);
    this->GlobalWaveForceMultiplier = 2.00f;
    this->GlobalWaveForceEnabled = false;
    this->AngleAdjustedForceStrength = 35.00f;
    this->OrientMeshRotationYawTowardsFlowDirection = false;
    this->DebugEnabled = false;
    this->DebugSphereRadiusMultiplier = 10.00f;
    this->EnteredWaterVolume = false;
    this->CharacterMovementForceMultiplier = 1.00f;
    this->EnterExitWaterTolerance = -35.00f;
    this->OceanologyWater = NULL;
    this->OceanologyWaterVolume = NULL;
    this->OwnerMesh = NULL;
    this->CharacterMovement = NULL;
    this->FlowControlSpline = NULL;
}

void UOceanBuoyancyComponent::ToggleDebug() {
}

void UOceanBuoyancyComponent::SetFlowControlSpline(USplineComponent* InFlowControlSpline, const double InUnscaledSplineWidth) {
}

FVector UOceanBuoyancyComponent::GetVelocityAtLocation(const FVector& Point) const {
    return FVector{};
}

double UOceanBuoyancyComponent::GetOwnerWaveHeightDistance() const {
    return 0.0;
}

UPrimitiveComponent* UOceanBuoyancyComponent::GetOwnerMesh_Implementation() const {
    return NULL;
}

USplineComponent* UOceanBuoyancyComponent::GetFlowControlSpline() const {
    return NULL;
}

FVector UOceanBuoyancyComponent::GetCurrentWaveHeight() const {
    return FVector{};
}

AOceanologyWaterVolume* UOceanBuoyancyComponent::GetCurrentWaterVolume() const {
    return NULL;
}

AOceanologyWaterParent* UOceanBuoyancyComponent::GetCurrentWater() const {
    return NULL;
}

UCharacterMovementComponent* UOceanBuoyancyComponent::GetCharacterMovement_Implementation() {
    return NULL;
}

void UOceanBuoyancyComponent::DebugPontoons() {
}

void UOceanBuoyancyComponent::AddForceAtLocation(const FVector& Force, const FVector& Position) const {
}

void UOceanBuoyancyComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(UOceanBuoyancyComponent, EnteredWaterVolume);
    DOREPLIFETIME(UOceanBuoyancyComponent, OceanologyWater);
    DOREPLIFETIME(UOceanBuoyancyComponent, OceanologyWaterVolume);
    DOREPLIFETIME(UOceanBuoyancyComponent, CurrentWaveHeight);
}


