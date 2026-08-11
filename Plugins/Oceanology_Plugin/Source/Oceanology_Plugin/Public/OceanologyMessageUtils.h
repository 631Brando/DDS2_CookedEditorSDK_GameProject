#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "OceanologyMessageUtils.generated.h"

class UObject;

UCLASS(Blueprintable)
class OCEANOLOGY_PLUGIN_API UOceanologyMessageUtils : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UOceanologyMessageUtils();

    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void CreateMessage(const UObject* WorldContextObject, const FString& Message, const bool bSuccess);
    
};

