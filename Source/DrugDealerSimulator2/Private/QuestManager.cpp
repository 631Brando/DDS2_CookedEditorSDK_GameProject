#include "QuestManager.h"

UQuestManager::UQuestManager(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->TaskDatabase = NULL;
}



void UQuestManager::ShareTaskToPlayer(FGuid TaskGuid, bool Everyone, const FString& PlayerNetID) {
}

void UQuestManager::RegisterNewTask(FName TaskID, FGuid AssignedClient, const FString& AssignedPlayers, FText NameOverride, FText DescOverride, bool& Success, FGuid& NewGuid) {
}

ETaskStatus UQuestManager::GetTaskStatus(const FString& PlayerNetID, FName TaskID) {
    return ETaskStatus::Inactive;
}

void UQuestManager::GetTaskList(const FString& PlayerStringID, bool IgnorePlayerFilter, bool ActiveOnly, TArray<FTaskItemData>& OutList) {
}

void UQuestManager::GetTaskHistory(FName TaskID, bool& WasAdded, bool& WasFinished) {
}

FTaskItemData UQuestManager::GetClientTaskData(FGuid ClientGuid) {
    return FTaskItemData{};
}

bool UQuestManager::CheckTaskWasAdded(FName TaskID, const FString& PlayerNetID) {
    return false;
}

bool UQuestManager::CheckPlayerHasTask(const FString& PlayerNetID, FName TaskID) {
    return false;
}

bool UQuestManager::ChangeTaskStatusByName(FName TaskID, const FString& PlayerNetID, ETaskStatus NewStatus) {
    return false;
}

bool UQuestManager::ChangeTaskStatus(FGuid TaskGuid, const FString& PlayerNetID, ETaskStatus NewStatus) {
    return false;
}

bool UQuestManager::ChangeClientTaskStatus(FGuid ClientGuid, const FString& PlayerNetID, ETaskStatus NewStatus) {
    return false;
}


