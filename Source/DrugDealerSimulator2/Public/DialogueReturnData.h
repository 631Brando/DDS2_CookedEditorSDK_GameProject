#pragma once
#include "CoreMinimal.h"
#include "DialogueReturnData.generated.h"

USTRUCT(BlueprintType)
struct FDialogueReturnData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName CharacterID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText DialogueText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FText> DialogueReponses;
    
    DRUGDEALERSIMULATOR2_API FDialogueReturnData();
};

