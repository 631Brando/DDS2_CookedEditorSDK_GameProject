#include "GearTelemetryOptions.h"

FGearTelemetryOptions::FGearTelemetryOptions() {
    this->mShow = false;
    this->mShowGauge = false;
    this->mShowAeroDynamics = false;
    this->mShowAxles = false;
    this->mShowEngine = false;
    this->mShowInput = false;
    this->mShowTransmission = false;
    this->mShowVehicle = false;
    this->mShowWheels = false;
    this->mShowReplication = false;
    this->mShowStats = false;
    this->mShowGizmos = false;
    this->mPrintCollisionLogs = false;
}

