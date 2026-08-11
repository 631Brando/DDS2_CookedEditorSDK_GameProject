#pragma once
#include "CoreMinimal.h"
#include "OceanologyWaterQuadTreeSettings.h"
#include "OceanologyOceanQuadTreeSettings.generated.h"

USTRUCT(BlueprintType)
struct FOceanologyOceanQuadTreeSettings : public FOceanologyWaterQuadTreeSettings {
    GENERATED_BODY()
public:
    OCEANOLOGY_PLUGIN_API FOceanologyOceanQuadTreeSettings();
};

