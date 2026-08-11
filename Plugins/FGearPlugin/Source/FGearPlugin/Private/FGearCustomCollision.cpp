#include "FGearCustomCollision.h"

UFGearCustomCollision::UFGearCustomCollision(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bHiddenInGame = true;
    this->CastShadow = false;
    this->bReceiveMobileCSMShadows = false;
    this->OverrideMaterials.AddDefaulted(1);
    this->mOverrideChannel = false;
    this->mChannel = ECC_WorldStatic;
}


