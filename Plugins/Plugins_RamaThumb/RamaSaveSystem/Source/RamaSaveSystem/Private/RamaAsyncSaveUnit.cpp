#include "RamaAsyncSaveUnit.h"

FRamaAsyncSaveUnit::FRamaAsyncSaveUnit() {
    this->UpdateUI = false;
    this->Index = 0;
    this->TotalComponents = 0;
    this->Finished = false;
    this->CompressionStarted = false;
}

