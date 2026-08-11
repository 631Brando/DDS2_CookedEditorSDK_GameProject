#include "CraftRecipeeData.h"

FCraftRecipeeData::FCraftRecipeeData() {
    this->RecipeeIcon = NULL;
    this->AllowExperimentalDiscovery = false;
    this->UnlockRequired = false;
    this->ShowInJournalSearch = false;
    this->WasteAmount = 0.00f;
    this->XPEarned = 0.00f;
    this->RoomTemperature = false;
    this->OptimalTemperature = 0.00f;
    this->TempMin = 0.00f;
    this->TempMax = 0.00f;
    this->MinEquipmentTier = 0;
    this->BaseCraftTime = 0.00f;
    this->TempLowSpeedLossPercent = 0.00f;
    this->TempHighSpeedBoostPercent = 0.00f;
    this->TempHighCostRisePercent = 0.00f;
}

