#pragma once
#include "CoreMinimal.h"
#include "RamaSaveSystemAssetPathRemap.generated.h"

USTRUCT(BlueprintType)
struct FRamaSaveSystemAssetPathRemap {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString OldPath;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString NewPath;
    
    RAMASAVESYSTEM_API FRamaSaveSystemAssetPathRemap();
};

