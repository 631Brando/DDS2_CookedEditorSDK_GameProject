#include "TownData.h"

FTownData::FTownData() {
    this->TownPicture = NULL;
    this->bDisplayableOnMap = false;
    this->bUsesReputationSystem = false;
    this->ReputationOverflowMax = 0.00f;
    this->ReputationDropPerDay = 0.00f;
    this->ReputationEventsDatabase = NULL;
    this->AverageDrugPotencyExpectations = 0.00f;
    this->ExpectationVariation = 0.00f;
    this->InfluencerMaxGramDistributionPerDay = 0;
    this->InfluencerPackageFrequency = 0;
    this->PopulationClothPresets = NULL;
    this->PopulationFacePool = NULL;
    this->PopulationHairPool = NULL;
    this->PopulationFacialHairPool = NULL;
    this->PopulationSpecialMeshPool = NULL;
    this->GeneralWeaponChance = 0.00f;
    this->GeneralBossChance = 0.00f;
    this->GeneralEnemyLimit = 0;
}

