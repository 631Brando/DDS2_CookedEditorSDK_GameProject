#pragma once
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "GameDlcEntry.generated.h"

USTRUCT(BlueprintType)
struct FGameDlcEntry : public FTableRowBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText DlcDisplayText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 DlcSteamAppId;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString DlcRelatedGameFeaturePluginNameString;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName CraftingGroupUnlockName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDisableActivationInEditor;
    
    DRUGDEALERSIMULATOR2_API FGameDlcEntry();
};

