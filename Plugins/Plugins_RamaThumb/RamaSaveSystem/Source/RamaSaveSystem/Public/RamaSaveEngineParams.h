#pragma once
#include "CoreMinimal.h"
#include "RamaSaveEngineParams.generated.h"

USTRUCT(BlueprintType)
struct FRamaSaveEngineParams {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FString> LoadOnlyActorsWithSaveTags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString Filename;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool DestroyActorsBeforeLoad;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool DontLoadPlayerPawns;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString LoadOnlyStreamingLevel;
    
    RAMASAVESYSTEM_API FRamaSaveEngineParams();
};

