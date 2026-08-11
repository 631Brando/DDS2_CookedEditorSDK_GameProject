#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "PetAnimalData.generated.h"

USTRUCT(BlueprintType)
struct FPetAnimalData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName PetID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGuid PetGuid;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGuid PetAssignedStation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString PetFollowMaster;
    
    DRUGDEALERSIMULATOR2_API FPetAnimalData();
};

