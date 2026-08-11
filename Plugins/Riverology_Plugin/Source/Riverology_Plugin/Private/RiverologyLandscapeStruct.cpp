#include "RiverologyLandscapeStruct.h"

FRiverologyLandscapeStruct::FRiverologyLandscapeStruct() {
    this->ApplyLandscapeSpline = false;
    this->Landscape = NULL;
    this->RaiseHeights = false;
    this->LowerHeights = false;
    this->DeformWidth = 0.00f;
    this->DeformFalloff = 0.00f;
    this->RefreshGrassFoliage = false;
}

