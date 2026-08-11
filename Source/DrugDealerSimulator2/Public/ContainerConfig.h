#pragma once
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "InventorySpecialSlotData.h"
#include "ContainerConfig.generated.h"

USTRUCT(BlueprintType)
struct FContainerConfig : public FTableRowBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 BaseContainerSize;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 BaseGridMaxWidth;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 BaseConcealedSlots;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<int32> SlotDivision;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FInventorySpecialSlotData> SpecialSlotList;
    
    DRUGDEALERSIMULATOR2_API FContainerConfig();
};

