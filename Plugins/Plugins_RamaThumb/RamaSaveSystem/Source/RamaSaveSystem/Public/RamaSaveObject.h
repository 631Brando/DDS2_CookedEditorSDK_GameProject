#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "RamaSaveObject.generated.h"

UCLASS(Abstract, Blueprintable)
class RAMASAVESYSTEM_API URamaSaveObject : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float GameVersion;
    
    URamaSaveObject();

};

