#pragma once
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "CurrencyData.generated.h"

USTRUCT(BlueprintType)
struct FCurrencyData : public FTableRowBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText CurrencyName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText CurrencyDescription;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 CurrencyValue;
    
    DRUGDEALERSIMULATOR2_API FCurrencyData();
};

