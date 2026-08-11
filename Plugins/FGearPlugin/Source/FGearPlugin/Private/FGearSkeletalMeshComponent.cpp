#include "FGearSkeletalMeshComponent.h"

UFGearSkeletalMeshComponent::UFGearSkeletalMeshComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bReceivesDecals = false;
    this->bApplyImpulseOnDamage = false;
    this->bPerBoneMotionBlur = false;
}


