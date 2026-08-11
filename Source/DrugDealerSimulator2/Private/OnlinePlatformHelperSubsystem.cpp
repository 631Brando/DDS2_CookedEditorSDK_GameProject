#include "OnlinePlatformHelperSubsystem.h"

UOnlinePlatformHelperSubsystem::UOnlinePlatformHelperSubsystem() {
    this->LocalPlr = NULL;
    this->bIsJoiningSession = false;
}

void UOnlinePlatformHelperSubsystem::UnloadDlcRelatedGameFeaturePlugin(FName DlcEntryRowName, bool bKeepFeatureRegistered) {
}

void UOnlinePlatformHelperSubsystem::MountPlugin(const FString& PluginName) {
}

bool UOnlinePlatformHelperSubsystem::LoadShaderbytecode(const FString& LibraryName, const FString& LibraryDir, bool bNative) {
    return false;
}

void UOnlinePlatformHelperSubsystem::LoadDlcRelatedGameFeaturePlugin(FName DlcEntryRowName) {
}

bool UOnlinePlatformHelperSubsystem::LoadAssetRegistry(const FString& LibraryName, const FString& LibraryDir) {
    return false;
}

void UOnlinePlatformHelperSubsystem::LoadAndActivateDlcRelatedGameFeaturePlugin(FName DlcEntryRowName) {
}

void UOnlinePlatformHelperSubsystem::GetDlcRelatedGameFeaturePluginUrl(FName DlcEntryRowName, FString& DlcGameFeaturePluginUrl) {
}

void UOnlinePlatformHelperSubsystem::GetDlcRelatedGameFeaturePluginNameString(FName DlcEntryRowName, FString& DlcGameFeaturePluginNameString) {
}

void UOnlinePlatformHelperSubsystem::GetDlcEntryUnlockCraftingGroups(FName DlcEntryRowName, FName& UnlockCraftingGroupName) {
}

void UOnlinePlatformHelperSubsystem::FindAllDdsSessions() {
}

void UOnlinePlatformHelperSubsystem::DestroySession() {
}

void UOnlinePlatformHelperSubsystem::DeactivateDlcRelatedGameFeaturePlugin(FName DlcEntryRowName) {
}

void UOnlinePlatformHelperSubsystem::DdsJoinSession(const FBlueprintSessionResult& OnlineSession) {
}

void UOnlinePlatformHelperSubsystem::CreateDdsSession(FDdsUserSessionSettings UserSessionData) {
}

void UOnlinePlatformHelperSubsystem::CheckForDlcOwneship(FName DlcEntryRowName, bool& bLocalUserOwnsDlc) {
}

void UOnlinePlatformHelperSubsystem::AttemptLocalPlayerSet() {
}

void UOnlinePlatformHelperSubsystem::AttemptAutoLogin() {
}

bool UOnlinePlatformHelperSubsystem::AddToPluginsList(const FString& PluginFilename) {
    return false;
}


