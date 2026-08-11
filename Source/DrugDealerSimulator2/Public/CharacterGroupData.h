#pragma once
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "CharacterGroupData.generated.h"

class UTexture2D;

USTRUCT(BlueprintType)
struct FCharacterGroupData : public FTableRowBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText GroupName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText GroupDescription;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2D* GroupImage;
    
    DRUGDEALERSIMULATOR2_API FCharacterGroupData();
};

