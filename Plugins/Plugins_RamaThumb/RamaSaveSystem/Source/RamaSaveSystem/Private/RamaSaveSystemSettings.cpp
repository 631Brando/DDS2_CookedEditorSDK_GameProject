#include "RamaSaveSystemSettings.h"
#include "RamaSaveEngine.h"

URamaSaveSystemSettings::URamaSaveSystemSettings() {
    this->GameVersion = 1.00f;
    this->RamaSaveEngineBP = ARamaSaveEngine::StaticClass();
    this->SaveAllPropertiesMarkedAsSaveGame = true;
    this->UseUncompressedSaveFiles = false;
    this->AsyncSave = false;
    this->AsyncSaveTickInterval = 0.01f;
    this->AsyncSaveActorChunkSize = 1.00f;
    this->Saving_PerformObjectValidityChecks = true;
    this->Loading_GlobalVerboseLogging = false;
    this->Loading_GlobalDisablePhysicsLoad = false;
    this->LogSavingAndLoadingOfEachStaticDataProperty = false;
    this->LogLoadedActorClassPath = false;
}

URamaSaveSystemSettings* URamaSaveSystemSettings::Get() {
    return NULL;
}


