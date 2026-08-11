#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "EOceanBuoyancyPontoonMode.h"
#include "OceanBuoyancyPontoon.generated.h"

USTRUCT(BlueprintType)
struct OCEANOLOGY_PLUGIN_API FOceanBuoyancyPontoon {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Socket;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector Pontoon;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double Radius;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double DensityOverride;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<EOceanBuoyancyPontoonMode> Mode;
    
    FOceanBuoyancyPontoon();
};

