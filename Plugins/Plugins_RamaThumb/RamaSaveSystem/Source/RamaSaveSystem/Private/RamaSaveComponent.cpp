#include "RamaSaveComponent.h"

URamaSaveComponent::URamaSaveComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->RamaSave_LogPersistentActorGUID = true;
    this->RamaSave_ShouldLoadActorWorldPosition = true;
    this->RamaSave_ShouldSaveActor = true;
    this->DestroyBeforeLoad = true;
    this->RamaSave_VerboseLog = false;
    this->RamaSave_LogAllSavedComponentProperties = false;
    this->RamaSave_SavePhysicsData = false;
    this->LoadedGameVersion = 1.00f;
}



bool URamaSaveComponent::RamaSave_HasSaveTag(const FString& SaveTag) {
    return false;
}

bool URamaSaveComponent::RamaSave_HasAnyOfSaveTags(const TArray<FString>& SaveTags) {
    return false;
}

FString URamaSaveComponent::GetActorStreamingLevelPackageName() {
    return TEXT("");
}

bool URamaSaveComponent::GetActorIsInPersistentLevel() {
    return false;
}


