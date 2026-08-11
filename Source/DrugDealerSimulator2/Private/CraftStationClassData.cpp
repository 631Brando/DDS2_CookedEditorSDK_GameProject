#include "CraftStationClassData.h"

FCraftStationClassData::FCraftStationClassData() {
    this->StationIcon = NULL;
    this->EquipmentTier = 0;
    this->HasTempRegulation = false;
    this->WorkTempMin = 0.00f;
    this->WorkTempMax = 0.00f;
    this->PowerRequiresHigh = false;
    this->DailyUsageCostIncrease = 0;
    this->MaxSimProcesses = 0;
    this->WorkSpeedMultiplier = 0.00f;
    this->WasteAmountMultiplier = 0.00f;
    this->ProductionCostMultiplier = 0.00f;
}

