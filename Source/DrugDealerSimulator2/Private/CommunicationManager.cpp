#include "CommunicationManager.h"

UCommunicationManager::UCommunicationManager(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
}

bool UCommunicationManager::RespondToMessage(FGuid MessageGuid, const FString& ResponseTypeID, const FString& PlayerNetID) {
    return false;
}

void UCommunicationManager::RegisterPlayerOnline(const FString& PlayerID) {
}

void UCommunicationManager::RedirectMessageToPlayer(FGuid MessageGuid, const FString& PlayerNetID) {
}



void UCommunicationManager::MarkSmsRead(FGuid Guid) {
}

void UCommunicationManager::GetOnlinePlayerIDs(TArray<FString>& OutPlayers) {
}

void UCommunicationManager::GetNewSMSList(TArray<FSMSData>& SMSData) {
}

TArray<FSMSListItem> UCommunicationManager::GetMessageList(const FString& PlayerNetID) {
    return TArray<FSMSListItem>();
}

void UCommunicationManager::GetCharacterSMSList(const FName& CharacterID, bool ReadOnly, TArray<FSMSData>& SMSData) {
}

void UCommunicationManager::AddNewSms(FSMSData NewSmsData, bool& Success, FGuid& OutGuid) {
}


