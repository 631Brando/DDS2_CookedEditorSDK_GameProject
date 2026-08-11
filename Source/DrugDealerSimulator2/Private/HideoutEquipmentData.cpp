#include "HideoutEquipmentData.h"

FHideoutEquipmentData::FHideoutEquipmentData() {
    this->EquipmentImage = NULL;
    this->EquipmentActorClass = NULL;
    this->EquipmentSalePrice = 0.00f;
    this->EquipmentWorkWattage = 0.00f;
    this->QuantityLimit = 0;
    this->CanPlaceFloor = false;
    this->CanPlaceWall = false;
    this->CanPlaceCeiling = false;
    this->CanPlaceOutdoors = false;
    this->CanPlaceOnDirt = false;
    this->CanPlaceOnTabletop = false;
    this->HasTabletop = false;
}

