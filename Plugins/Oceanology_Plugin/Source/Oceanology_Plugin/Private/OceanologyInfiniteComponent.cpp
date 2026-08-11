#include "OceanologyInfiniteComponent.h"

UOceanologyInfiniteComponent::UOceanologyInfiniteComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bAutoActivate = true;
    this->EnableInfinity = true;
    this->EnableInfinityInEditor = true;
    this->EnableInfinityInGame = true;
    this->FollowUpdateInterval = 0.00f;
    this->TimeJump = 20000.00f;
    this->EnableDebug = false;
    this->Origin = NULL;
    this->ParentActor = NULL;
}

void UOceanologyInfiniteComponent::SetParentActor(AActor* Actor) {
}

void UOceanologyInfiniteComponent::SetOrigin(UWorld* InOrigin) {
}

void UOceanologyInfiniteComponent::InitDefaultOrigin() {
}

void UOceanologyInfiniteComponent::Init(AActor* Actor, UWorld* InOrigin) {
}

void UOceanologyInfiniteComponent::ForceFollow() {
}

void UOceanologyInfiniteComponent::Follow(const bool NewForceFollow) {
}


