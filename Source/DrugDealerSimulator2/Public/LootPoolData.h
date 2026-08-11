#pragma once
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "LootPoolItem.h"
#include "LootPoolData.generated.h"

USTRUCT(BlueprintType)
struct FLootPoolData : public FTableRowBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString Notatka;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FLootPoolItem> ItemPool;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 RefreshIntervalHours;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 RefreshIntervalRand;
    
    DRUGDEALERSIMULATOR2_API FLootPoolData();
};

