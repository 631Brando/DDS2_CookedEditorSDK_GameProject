#pragma once
#include "CoreMinimal.h"
#include "OceanologyWaterQuadTreeSettings.h"
#include "OceanologyLakeQuadTreeSettings.generated.h"

USTRUCT(BlueprintType)
struct FOceanologyLakeQuadTreeSettings : public FOceanologyWaterQuadTreeSettings {
    GENERATED_BODY()
public:
    OCEANOLOGY_PLUGIN_API FOceanologyLakeQuadTreeSettings();
};

