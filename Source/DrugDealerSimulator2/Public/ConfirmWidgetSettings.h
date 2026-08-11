#pragma once
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "ConfirmWidgetConfigData.h"
#include "ConfirmWidgetSettings.generated.h"

USTRUCT(BlueprintType)
struct FConfirmWidgetSettings : public FTableRowBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FConfirmWidgetConfigData ConfigOverride;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 QuantityDefault;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 QuantityMax;
    
    DRUGDEALERSIMULATOR2_API FConfirmWidgetSettings();
};

