#include "PetAnimalConfig.h"

FPetAnimalConfig::FPetAnimalConfig() {
    this->PetAvatar = NULL;
    this->LayerMeshScale = 0.00f;
    this->LayerAnimation = NULL;
    this->PetCategory = EPetCategory::Dog;
    this->PetIdleSound = NULL;
    this->PetGreetSound = NULL;
}

