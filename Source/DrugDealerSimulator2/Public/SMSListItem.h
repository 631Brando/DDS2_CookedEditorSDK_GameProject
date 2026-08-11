#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SMSData.h"
#include "SMSListItem.generated.h"

USTRUCT(BlueprintType)
struct FSMSListItem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGuid SmsGuid;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSMSData SMSData;
    
    DRUGDEALERSIMULATOR2_API FSMSListItem();
};

