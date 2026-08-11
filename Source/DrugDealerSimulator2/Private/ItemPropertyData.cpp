#include "ItemPropertyData.h"

FItemPropertyData::FItemPropertyData() {
    this->PropertyIcon = NULL;
    this->HiddenProperty = false;
    this->PropertyMin = 0.00f;
    this->PropertyMax = 0.00f;
    this->DisplayRule = EItemPropertyDisplayRule::DirectFloat;
    this->ValueNeutral = false;
    this->PropertyPositiveDirection = 0;
    this->ShowPositivePlus = false;
}

