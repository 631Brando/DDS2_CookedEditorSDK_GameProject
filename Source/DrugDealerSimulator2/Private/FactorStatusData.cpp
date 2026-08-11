#include "FactorStatusData.h"

FFactorStatusData::FFactorStatusData() {
    this->StatusIcon = NULL;
    this->HiddenStatus = false;
    this->StatusTotalTimeout = 0.00f;
    this->StrengthTimeDistribution = NULL;
    this->AccumulateDoses = false;
    this->MinPassOutLevel = 0.00f;
}

