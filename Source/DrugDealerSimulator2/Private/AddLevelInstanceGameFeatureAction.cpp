#include "AddLevelInstanceGameFeatureAction.h"

UAddLevelInstanceGameFeatureAction::UAddLevelInstanceGameFeatureAction() {
    this->bRuntimeFeatureActionActivation = false;
    this->bServerSideOnly = false;
    this->bShouldRebuildNavigationPostLoad = false;
}

void UAddLevelInstanceGameFeatureAction::OnLevelInstanceShown() {
}


