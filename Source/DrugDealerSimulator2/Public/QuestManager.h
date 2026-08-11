#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Components/ActorComponent.h"
#include "ETaskStatus.h"
#include "TaskItemData.h"
#include "QuestManager.generated.h"

class UDataTable;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class DRUGDEALERSIMULATOR2_API UQuestManager : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDataTable* TaskDatabase;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FGuid, FTaskItemData> TaskList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, FGuid> TaskNameMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FGuid, FGuid> TaskClientMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, FString> TasksHistory;
    
public:
    UQuestManager(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void TaskStatusChanged(FGuid TaskGuid, FTaskItemData TaskData);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void TaskListUpdated();
    
    UFUNCTION(BlueprintCallable)
    void ShareTaskToPlayer(FGuid TaskGuid, bool Everyone, const FString& PlayerNetID);
    
    UFUNCTION(BlueprintCallable)
    void RegisterNewTask(FName TaskID, FGuid AssignedClient, const FString& AssignedPlayers, FText NameOverride, FText DescOverride, bool& Success, FGuid& NewGuid);
    
    UFUNCTION(BlueprintCallable)
    ETaskStatus GetTaskStatus(const FString& PlayerNetID, FName TaskID);
    
    UFUNCTION(BlueprintCallable)
    void GetTaskList(const FString& PlayerStringID, bool IgnorePlayerFilter, bool ActiveOnly, TArray<FTaskItemData>& OutList);
    
    UFUNCTION(BlueprintCallable)
    void GetTaskHistory(FName TaskID, bool& WasAdded, bool& WasFinished);
    
    UFUNCTION(BlueprintCallable)
    FTaskItemData GetClientTaskData(FGuid ClientGuid);
    
    UFUNCTION(BlueprintCallable)
    bool CheckTaskWasAdded(FName TaskID, const FString& PlayerNetID);
    
    UFUNCTION(BlueprintCallable)
    bool CheckPlayerHasTask(const FString& PlayerNetID, FName TaskID);
    
    UFUNCTION(BlueprintCallable)
    bool ChangeTaskStatusByName(FName TaskID, const FString& PlayerNetID, ETaskStatus NewStatus);
    
    UFUNCTION(BlueprintCallable)
    bool ChangeTaskStatus(FGuid TaskGuid, const FString& PlayerNetID, ETaskStatus NewStatus);
    
    UFUNCTION(BlueprintCallable)
    bool ChangeClientTaskStatus(FGuid ClientGuid, const FString& PlayerNetID, ETaskStatus NewStatus);
    
};

