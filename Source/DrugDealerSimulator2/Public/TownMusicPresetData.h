#pragma once
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "TownMusicPresetData.generated.h"

class USoundBase;

USTRUCT(BlueprintType)
struct FTownMusicPresetData : public FTableRowBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText PresetName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundBase* ChaseMusicMetasound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DefaultVolume;
    
    DRUGDEALERSIMULATOR2_API FTownMusicPresetData();
};

