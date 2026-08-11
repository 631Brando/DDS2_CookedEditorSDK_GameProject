#pragma once
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "NarrationTextEntry.h"
#include "NarrationData.generated.h"

class USoundBase;

USTRUCT(BlueprintType)
struct FNarrationData : public FTableRowBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString Notatka;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FNarrationTextEntry> EddieText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundBase* EddieAudio;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FNarrationTextEntry> MarcusText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundBase* MarcusAudio;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool TriggerForAll;
    
    DRUGDEALERSIMULATOR2_API FNarrationData();
};

