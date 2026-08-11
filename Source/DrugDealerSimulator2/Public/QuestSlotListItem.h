#pragma once
#include "CoreMinimal.h"
#include "QuestSlotListItem.generated.h"

USTRUCT(BlueprintType)
struct FQuestSlotListItem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ItemId;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Quantity;
    
    DRUGDEALERSIMULATOR2_API FQuestSlotListItem();
};

