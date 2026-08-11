#pragma once
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "EnviroDeadDropConfig.generated.h"

USTRUCT(BlueprintType)
struct FEnviroDeadDropConfig : public FTableRowBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText DeadDropName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName TownID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 PackageMaxSize;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 PackageMaxCount;
    
    DRUGDEALERSIMULATOR2_API FEnviroDeadDropConfig();
};

