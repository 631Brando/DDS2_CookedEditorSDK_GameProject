#pragma once
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "WorldKeyData.generated.h"

class UTexture2D;

USTRUCT(BlueprintType)
struct FWorldKeyData : public FTableRowBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText KeyName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText KeyDescription;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2D* KeyIcon;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 KeyTier;
    
    DRUGDEALERSIMULATOR2_API FWorldKeyData();
};

