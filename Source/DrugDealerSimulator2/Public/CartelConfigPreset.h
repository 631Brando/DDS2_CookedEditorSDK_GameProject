#pragma once
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "CartelConfigPreset.generated.h"

class UTexture2D;

USTRUCT(BlueprintType)
struct FCartelConfigPreset : public FTableRowBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText PresetTitle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText PresetDescription;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2D* PresetIcon;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, float> PresetConfig;
    
    DRUGDEALERSIMULATOR2_API FCartelConfigPreset();
};

