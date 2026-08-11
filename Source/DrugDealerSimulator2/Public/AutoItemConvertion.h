#pragma once
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "ItemConvertionOutput.h"
#include "AutoItemConvertion.generated.h"

USTRUCT(BlueprintType)
struct FAutoItemConvertion : public FTableRowBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool InstantItemConvertion;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ConvertionRealTimeSeconds;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FItemConvertionOutput> ConvertionOutput;
    
    DRUGDEALERSIMULATOR2_API FAutoItemConvertion();
};

