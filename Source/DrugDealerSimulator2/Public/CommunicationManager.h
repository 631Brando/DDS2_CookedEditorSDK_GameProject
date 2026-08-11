#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Components/ActorComponent.h"
#include "MessageResponseData.h"
#include "PlayerOnlineStatus.h"
#include "SMSData.h"
#include "SMSListItem.h"
#include "CommunicationManager.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class DRUGDEALERSIMULATOR2_API UCommunicationManager : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FText> SmsContent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> SmsCharacter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FGuid> SMSRelatedAction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<bool> SmsRead;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FGuid, FSMSData> SMSDataList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> PhonecallID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FGuid> PhonecallRelatedAction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<bool> PhonecallActivated;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FString, FPlayerOnlineStatus> PlayersOnlineList;
    
    UCommunicationManager(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    bool RespondToMessage(FGuid MessageGuid, const FString& ResponseTypeID, const FString& PlayerNetID);
    
    UFUNCTION(BlueprintCallable)
    void RegisterPlayerOnline(const FString& PlayerID);
    
    UFUNCTION(BlueprintCallable)
    void RedirectMessageToPlayer(FGuid MessageGuid, const FString& PlayerNetID);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void MessagesUpdated();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void MessageResponseEvent(FMessageResponseData ResponseData);
    
    UFUNCTION(BlueprintCallable)
    void MarkSmsRead(FGuid Guid);
    
    UFUNCTION(BlueprintCallable)
    void GetOnlinePlayerIDs(TArray<FString>& OutPlayers);
    
    UFUNCTION(BlueprintCallable)
    void GetNewSMSList(TArray<FSMSData>& SMSData);
    
    UFUNCTION(BlueprintCallable)
    TArray<FSMSListItem> GetMessageList(const FString& PlayerNetID);
    
    UFUNCTION(BlueprintCallable)
    void GetCharacterSMSList(const FName& CharacterID, bool ReadOnly, TArray<FSMSData>& SMSData);
    
    UFUNCTION(BlueprintCallable)
    void AddNewSms(FSMSData NewSmsData, bool& Success, FGuid& OutGuid);
    
};

