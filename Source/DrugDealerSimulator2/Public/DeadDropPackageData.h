#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SubstanceContentsData.h"
#include "DeadDropPackageData.generated.h"

USTRUCT(BlueprintType)
struct FDeadDropPackageData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGuid DeadDropGuid;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGuid DealerGuid;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FSubstanceContentsData> PackageContents;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PackageTimer;
    
    DRUGDEALERSIMULATOR2_API FDeadDropPackageData();
};

