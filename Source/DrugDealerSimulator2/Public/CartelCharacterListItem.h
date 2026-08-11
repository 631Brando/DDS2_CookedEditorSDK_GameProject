#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CartelCharacterData.h"
#include "ECartelCharacterJobType.h"
#include "CartelCharacterListItem.generated.h"

USTRUCT(BlueprintType)
struct FCartelCharacterListItem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCartelCharacterData CharacterData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGuid CharacterGuid;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ECartelCharacterJobType CurJob;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool IsClient;
    
    DRUGDEALERSIMULATOR2_API FCartelCharacterListItem();
};

