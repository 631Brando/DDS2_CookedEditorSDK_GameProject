#include "TaskData.h"

FTaskData::FTaskData() {
    this->TaskImage = NULL;
    this->AutoFocusTask = false;
    this->RequiredMoney = 0;
    this->CartelXPOnComplete = 0.00f;
    this->IsAreaTask = false;
    this->AreaRange = 0.00f;
    this->SharingPolicy = ETaskSharePolicy::SharedSingle;
    this->OneTimeTask = false;
}

