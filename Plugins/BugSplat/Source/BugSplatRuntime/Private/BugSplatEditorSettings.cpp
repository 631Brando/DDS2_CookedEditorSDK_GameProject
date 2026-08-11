#include "BugSplatEditorSettings.h"

UBugSplatEditorSettings::UBugSplatEditorSettings() {
    this->BugSplatDatabase = TEXT("drug-dealer-simulator-2");
    this->BugSplatApp = TEXT("DrugDealerSimulator2");
    this->BugSplatVersion = TEXT("1.1.36");
    this->BugSplatClientId = TEXT("");
    this->BugSplatClientSecret = TEXT("");
    this->bUpdateEngineDataRouterUrl = true;
    this->bUploadDebugSymbols = false;
    this->bEnableCrashReportingAndroid = true;
    this->bEnableCrashReportingIos = true;
}


