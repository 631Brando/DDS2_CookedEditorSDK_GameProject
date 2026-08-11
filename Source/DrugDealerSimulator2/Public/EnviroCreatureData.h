#pragma once
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "EnviroCreatureData.generated.h"

class UTexture2D;

USTRUCT(BlueprintType)
struct FEnviroCreatureData : public FTableRowBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText CreatureName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText CreatureDescription;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2D* CreatureImage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName BiteUsageEffectID;
    
    DRUGDEALERSIMULATOR2_API FEnviroCreatureData();
};

