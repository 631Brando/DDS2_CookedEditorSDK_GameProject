#include "ReputationEventData.h"

FReputationEventData::FReputationEventData() {
    this->EventPicture = NULL;
    this->ManualUnlockOnly = false;
    this->EventMinTownLevel = 0;
    this->EventMinCartelLevel = 0;
    this->MeetingDiscoverChance = 0.00f;
    this->EventExecutionTime = 0.00f;
    this->EventCostMoney = 0;
    this->EventReputation = 0.00f;
    this->EventCartelExperience = 0.00f;
}

