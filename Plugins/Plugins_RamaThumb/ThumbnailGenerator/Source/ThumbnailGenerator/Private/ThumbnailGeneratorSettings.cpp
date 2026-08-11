#include "ThumbnailGeneratorSettings.h"

UThumbnailGeneratorSettings::UThumbnailGeneratorSettings() {
    this->AssetRefs.AddDefaulted(4);
    this->MaxRenderTargetCacheSize = 50;
}


