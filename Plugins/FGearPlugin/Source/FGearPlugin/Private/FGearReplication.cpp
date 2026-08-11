#include "FGearReplication.h"
#include "Net/UnrealNetwork.h"

UFGearReplication::UFGearReplication(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->mOverrideSettings = false;
    this->mEnabled = true;
    this->mInputSendRate = 20;
    this->mStateSendRate = 20;
    this->mPositionError = NULL;
    this->mRotationError = NULL;
    this->mCollisionError = NULL;
    this->mMinCollisionBlendSpeed = 10.00f;
    this->mForceSnapDistance = 15.00f;
}

void UFGearReplication::serverReceiveState_Implementation(float Time, FVector_NetQuantize100 Pos, FVector_NetQuantize100 rot, FVector_NetQuantize100 vel, FVector_NetQuantize100 avel) {
}

void UFGearReplication::serverReceiveInputs_Implementation(uint64 pckt) {
}

void UFGearReplication::resetCollisionTime(float thresholdTime) {
}

bool UFGearReplication::IsEnabled() const {
    return false;
}

void UFGearReplication::clientReceiveState_Implementation(float Time, FVector_NetQuantize100 Pos, FVector_NetQuantize100 rot, FVector_NetQuantize100 vel, FVector_NetQuantize100 avel) {
}

void UFGearReplication::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(UFGearReplication, mCurrentInput);
}


