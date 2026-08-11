#pragma once
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "CharacterClothElementHard.generated.h"

class UMaterialInstance;
class USkeletalMesh;

USTRUCT(BlueprintType)
struct FCharacterClothElementHard : public FTableRowBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USkeletalMesh* BaseMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInstance* MaterialVariant;
    
    DRUGDEALERSIMULATOR2_API FCharacterClothElementHard();
};

