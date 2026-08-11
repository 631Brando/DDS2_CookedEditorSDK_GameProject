#pragma once
#include "CoreMinimal.h"
#include "PropertyListItem.generated.h"

USTRUCT(BlueprintType)
struct FPropertyListItem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName PropertyID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PropertyValue;
    
    DRUGDEALERSIMULATOR2_API FPropertyListItem();
};

