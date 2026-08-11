#include "OceanSwimmingComponent.h"
#include "Net/UnrealNetwork.h"

UOceanSwimmingComponent::UOceanSwimmingComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->SwimmingUpdateInterval = 0.00f;
    this->BuoyancyPontoonSocketForEnterWaterEvent = TEXT("Head");
    this->SwimmingBuoyancyForceMultiplier = 0.03f;
    this->Immersion = 100.00f;
    this->SwimUpLimiter = 10.00f;
    this->SwimMaxSpeed = 300.00f;
    this->SwimFastMaxSpeed = 600.00f;
    this->SurfaceLockedSwimmingLimiter = 50.00f;
    this->EnterExitWaterToleranceOffset = 0.00f;
    this->DrowningEnabled = true;
    this->DrowningTimeWarningInSeconds = 7;
    this->DrowningTimeDeathInSeconds = 5;
    this->EnableUnderwaterEffects = false;
    this->HeadBubblesEffectNiagara = NULL;
    this->HeadSocketName = TEXT("head_Socket");
    this->RightFootBubblesEffectNiagara = NULL;
    this->LeftFootBubblesEffectNiagara = NULL;
    this->RightFootSocketName = TEXT("foot_r_Socket");
    this->LeftFootSocketName = TEXT("foot_l_Socket");
    this->StopHeadBubblesWhileSwimFast = true;
    this->StopRightFootBubblesWhileSwimFast = true;
    this->StopLeftFootBubblesWhileSwimFast = true;
    this->SwimFastTrailEffectNiagara = NULL;
    this->SwimFastTrailSocketName = TEXT("swim_fast_trail_Socket");
    this->SwimFastTrailSound = NULL;
    this->DebugEnabled = false;
    this->EnteredWaterVolume = false;
    this->EnteredWater = false;
    this->Submerged = false;
    this->Swimming = false;
    this->UnderwaterTimeCounter = 0;
    this->UnderwaterTaskRunning = false;
    this->DrowningTimeCounter = 0;
    this->DrowningTaskRunning = false;
    this->DrownedToDeath = false;
    this->SurfaceLockedSwimming = false;
    this->SwimDown = false;
    this->SwimUp = false;
    this->SwimFast = false;
    this->SwimUpOrDownAxis = 0.00f;
    this->LookUpAxis = 0.00f;
    this->MoveForwardBackwardAxis = 0.00f;
    this->MoveLeftRightAxis = 0.00f;
    this->SwimmingOrientRotationToMovement = true;
    this->SwimmingUseControllerRotationYaw = false;
    this->OceanologyWater = NULL;
    this->OceanologyWaterVolume = NULL;
    this->OriginalMaxWalkSpeed = 0.00f;
    this->OriginalMaxSwimSpeed = 0.00f;
    this->OriginalOrientRotationToMovement = false;
    this->OriginalUseControllerRotationYaw = false;
    this->OriginalBuoyancy = 1.00f;
    this->EffectiveSwimmingBuoyancyForce = 0.03f;
    this->EffectiveSurfaceLockedSwimming = false;
    this->LastMovementMode = MOVE_Walking;
    this->HeadBubblesEffect = NULL;
    this->RightFootBubblesEffect = NULL;
    this->LeftFootBubblesEffect = NULL;
    this->SwimFastTrailEffect = NULL;
    this->SwimmingBubblesMID = NULL;
}

void UOceanSwimmingComponent::UnderwaterTask() {
}

void UOceanSwimmingComponent::ToggleDebug() {
}

void UOceanSwimmingComponent::Server_SwimUpOrDown_Implementation(const bool Value, const double AxisValue) {
}
bool UOceanSwimmingComponent::Server_SwimUpOrDown_Validate(const bool Value, const double AxisValue) {
    return true;
}

void UOceanSwimmingComponent::Server_SwimFast_Implementation(const bool Value) {
}
bool UOceanSwimmingComponent::Server_SwimFast_Validate(const bool Value) {
    return true;
}

void UOceanSwimmingComponent::Server_SurfaceLockedSwimming_Implementation(const bool Value) {
}
bool UOceanSwimmingComponent::Server_SurfaceLockedSwimming_Validate(const bool Value) {
    return true;
}

void UOceanSwimmingComponent::Server_MoveLeftRight_Implementation(const double AxisValue) {
}
bool UOceanSwimmingComponent::Server_MoveLeftRight_Validate(const double AxisValue) {
    return true;
}

void UOceanSwimmingComponent::Server_MoveForwardBackward_Implementation(const double AxisValue) {
}
bool UOceanSwimmingComponent::Server_MoveForwardBackward_Validate(const double AxisValue) {
    return true;
}

void UOceanSwimmingComponent::Server_LookUp_Implementation(const double AxisValue) {
}
bool UOceanSwimmingComponent::Server_LookUp_Validate(const double AxisValue) {
    return true;
}

void UOceanSwimmingComponent::OnExitedWater(const FName Socket, const bool Underwater) {
}

void UOceanSwimmingComponent::OnEnteredWater(const FName Socket, const bool Underwater) {
}

void UOceanSwimmingComponent::NetMulticast_SwimUpOrDown_Implementation(const bool Value, const double AxisValue) {
}

void UOceanSwimmingComponent::NetMulticast_SwimFast_Implementation(const bool Value) {
}

void UOceanSwimmingComponent::NetMulticast_SurfaceLockedSwimming_Implementation(const bool Value) {
}

void UOceanSwimmingComponent::NetMulticast_MoveLeftRight_Implementation(const double AxisValue) {
}

void UOceanSwimmingComponent::NetMulticast_MoveForwardBackward_Implementation(const double AxisValue) {
}

void UOceanSwimmingComponent::NetMulticast_LookUp_Implementation(const double AxisValue) {
}

bool UOceanSwimmingComponent::IsSurfaceLockedSwimming() const {
    return false;
}

AOceanologyWaterVolume* UOceanSwimmingComponent::GetCurrentWaterVolume() const {
    return NULL;
}

AOceanologyWaterParent* UOceanSwimmingComponent::GetCurrentWater() const {
    return NULL;
}

UCharacterMovementComponent* UOceanSwimmingComponent::GetCharacterMovement_Implementation() {
    return NULL;
}

void UOceanSwimmingComponent::DrownToDeath() {
}

void UOceanSwimmingComponent::DrowningTask() {
}

void UOceanSwimmingComponent::ComputeWaterFloorHeight() {
}

bool UOceanSwimmingComponent::CanStopSwim_Implementation() {
    return false;
}

bool UOceanSwimmingComponent::CanStartSwim_Implementation() {
    return false;
}

bool UOceanSwimmingComponent::CanExitWater_Implementation(const FName Socket, const bool Underwater) {
    return false;
}

bool UOceanSwimmingComponent::CanEnterWater_Implementation(const FName Socket, const bool Underwater) {
    return false;
}

bool UOceanSwimmingComponent::CanAlterState_Implementation() {
    return false;
}

void UOceanSwimmingComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(UOceanSwimmingComponent, EnteredWaterVolume);
    DOREPLIFETIME(UOceanSwimmingComponent, EnteredWater);
    DOREPLIFETIME(UOceanSwimmingComponent, Submerged);
    DOREPLIFETIME(UOceanSwimmingComponent, Swimming);
    DOREPLIFETIME(UOceanSwimmingComponent, UnderwaterTimeCounter);
    DOREPLIFETIME(UOceanSwimmingComponent, UnderwaterTaskRunning);
    DOREPLIFETIME(UOceanSwimmingComponent, DrowningTimeCounter);
    DOREPLIFETIME(UOceanSwimmingComponent, DrowningTaskRunning);
    DOREPLIFETIME(UOceanSwimmingComponent, DrownedToDeath);
    DOREPLIFETIME(UOceanSwimmingComponent, SurfaceLockedSwimming);
    DOREPLIFETIME(UOceanSwimmingComponent, SwimDown);
    DOREPLIFETIME(UOceanSwimmingComponent, SwimUp);
    DOREPLIFETIME(UOceanSwimmingComponent, SwimFast);
    DOREPLIFETIME(UOceanSwimmingComponent, SwimUpOrDownAxis);
    DOREPLIFETIME(UOceanSwimmingComponent, LookUpAxis);
    DOREPLIFETIME(UOceanSwimmingComponent, MoveForwardBackwardAxis);
    DOREPLIFETIME(UOceanSwimmingComponent, MoveLeftRightAxis);
    DOREPLIFETIME(UOceanSwimmingComponent, OceanologyWater);
    DOREPLIFETIME(UOceanSwimmingComponent, OceanologyWaterVolume);
    DOREPLIFETIME(UOceanSwimmingComponent, FindFloorResult);
    DOREPLIFETIME(UOceanSwimmingComponent, OriginalMaxWalkSpeed);
    DOREPLIFETIME(UOceanSwimmingComponent, OriginalMaxSwimSpeed);
    DOREPLIFETIME(UOceanSwimmingComponent, OriginalOrientRotationToMovement);
    DOREPLIFETIME(UOceanSwimmingComponent, OriginalUseControllerRotationYaw);
    DOREPLIFETIME(UOceanSwimmingComponent, OriginalBuoyancy);
    DOREPLIFETIME(UOceanSwimmingComponent, EffectiveSwimmingBuoyancyForce);
    DOREPLIFETIME(UOceanSwimmingComponent, EffectiveSurfaceLockedSwimming);
    DOREPLIFETIME(UOceanSwimmingComponent, LastMovementMode);
}


