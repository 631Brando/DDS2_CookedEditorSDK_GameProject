#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "BugSplatUtils.generated.h"

UCLASS(Blueprintable)
class BUGSPLATRUNTIME_API UBugSplatUtils : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UBugSplatUtils();

    UFUNCTION(BlueprintCallable)
    static void GenerateCrash();
    
    UFUNCTION(BlueprintCallable)
    static void GenerateAssert();
    
};

