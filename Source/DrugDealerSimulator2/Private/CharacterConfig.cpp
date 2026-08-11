#include "CharacterConfig.h"

FCharacterConfig::FCharacterConfig() {
    this->Avatar = NULL;
    this->CharacterTier = 0;
    this->IsTownInfluencer = false;
    this->DefaultAnimation = NULL;
    this->MeetingAnimation = NULL;
    this->UnlockXP = 0.00f;
    this->IsWholesaleClient = false;
    this->AverageOrderInterval = 0.00f;
}

