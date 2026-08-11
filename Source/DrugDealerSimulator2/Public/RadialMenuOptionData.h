#pragma once
#include "CoreMinimal.h"
#include "RadialMenuOptionData.generated.h"

class UTexture2D;

USTRUCT(BlueprintType)
struct FRadialMenuOptionData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2D* OptionIcon;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText OptionName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText OptionDescription;
    
    DRUGDEALERSIMULATOR2_API FRadialMenuOptionData();
};

