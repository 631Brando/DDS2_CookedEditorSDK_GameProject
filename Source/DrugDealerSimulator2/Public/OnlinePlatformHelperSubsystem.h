#pragma once
#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "FindSessionsCallbackProxy.h"
#include "DdsUserSessionSettings.h"
#include "MultiplayerOnCreateSessionCompleteDelegate.h"
#include "MultiplayerOnDestroySessionCompleteDelegate.h"
#include "MultiplayerOnJoinSessionCompleteParsedDelegate.h"
#include "MultiplayerOnSessionInviteAcceptedCompleteDelegate.h"
#include "MultiplayerOnSessionInviteReceivedCompleteDelegate.h"
#include "MultiplayerOnStartSessionCompleteDelegate.h"
#include "OnFindSessionAllSessionsCompleteDelegate.h"
#include "OnlinePlatformHelperSubsystem.generated.h"

class ULocalPlayer;

UCLASS(Blueprintable)
class DRUGDEALERSIMULATOR2_API UOnlinePlatformHelperSubsystem : public UGameInstanceSubsystem {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ULocalPlayer* LocalPlr;
    
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMultiplayerOnCreateSessionComplete MultiplayerOnCreateSessionComplete;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMultiplayerOnStartSessionComplete MultiplayerOnStartSessionComplete;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMultiplayerOnSessionInviteReceivedComplete MultiplayerOnSessionInviteReceivedComplete;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMultiplayerOnSessionInviteAcceptedComplete MultiplayerOnSessionInviteAcceptedComplete;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMultiplayerOnJoinSessionCompleteParsed MultiplayerOnJoinSessionCompleteParsed;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnFindSessionAllSessionsComplete OnFindSessionAllSessionsComplete;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMultiplayerOnDestroySessionComplete MultiplayerOnDestroySessionComplete;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName OnCreateSessionTravelLevelName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsJoiningSession;
    
    UOnlinePlatformHelperSubsystem();

    UFUNCTION(BlueprintCallable)
    void UnloadDlcRelatedGameFeaturePlugin(FName DlcEntryRowName, bool bKeepFeatureRegistered);
    
    UFUNCTION(BlueprintCallable)
    void MountPlugin(const FString& PluginName);
    
    UFUNCTION(BlueprintCallable)
    bool LoadShaderbytecode(const FString& LibraryName, const FString& LibraryDir, bool bNative);
    
    UFUNCTION(BlueprintCallable)
    void LoadDlcRelatedGameFeaturePlugin(FName DlcEntryRowName);
    
    UFUNCTION(BlueprintCallable)
    bool LoadAssetRegistry(const FString& LibraryName, const FString& LibraryDir);
    
    UFUNCTION(BlueprintCallable)
    void LoadAndActivateDlcRelatedGameFeaturePlugin(FName DlcEntryRowName);
    
    UFUNCTION(BlueprintCallable)
    void GetDlcRelatedGameFeaturePluginUrl(FName DlcEntryRowName, FString& DlcGameFeaturePluginUrl);
    
    UFUNCTION(BlueprintCallable)
    void GetDlcRelatedGameFeaturePluginNameString(FName DlcEntryRowName, FString& DlcGameFeaturePluginNameString);
    
    UFUNCTION(BlueprintCallable)
    void GetDlcEntryUnlockCraftingGroups(FName DlcEntryRowName, FName& UnlockCraftingGroupName);
    
    UFUNCTION(BlueprintCallable)
    void FindAllDdsSessions();
    
    UFUNCTION(BlueprintCallable)
    void DestroySession();
    
    UFUNCTION(BlueprintCallable)
    void DeactivateDlcRelatedGameFeaturePlugin(FName DlcEntryRowName);
    
    UFUNCTION(BlueprintCallable)
    void DdsJoinSession(const FBlueprintSessionResult& OnlineSession);
    
    UFUNCTION(BlueprintCallable)
    void CreateDdsSession(FDdsUserSessionSettings UserSessionData);
    
    UFUNCTION(BlueprintCallable)
    void CheckForDlcOwneship(FName DlcEntryRowName, bool& bLocalUserOwnsDlc);
    
    UFUNCTION(BlueprintCallable)
    void AttemptLocalPlayerSet();
    
    UFUNCTION(BlueprintCallable)
    void AttemptAutoLogin();
    
    UFUNCTION(BlueprintCallable)
    bool AddToPluginsList(const FString& PluginFilename);
    
};

