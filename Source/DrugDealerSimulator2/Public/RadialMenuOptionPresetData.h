#pragma once
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "RadialMenuOptionData.h"
#include "RadialMenuOptionPresetData.generated.h"

USTRUCT(BlueprintType)
struct FRadialMenuOptionPresetData : public FTableRowBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText PresetName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FRadialMenuOptionData> OptionList;
    
    DRUGDEALERSIMULATOR2_API FRadialMenuOptionPresetData();
};

