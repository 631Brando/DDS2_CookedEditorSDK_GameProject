#pragma once
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "DialogueTagCategoryData.generated.h"

class UTexture2D;

USTRUCT(BlueprintType)
struct FDialogueTagCategoryData : public FTableRowBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText CategoryName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText CategoryDescription;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2D* TagImage;
    
    DRUGDEALERSIMULATOR2_API FDialogueTagCategoryData();
};

