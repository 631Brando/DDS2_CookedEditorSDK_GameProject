#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "DLCBlueprintFunctionLibrary.generated.h"

UCLASS(Blueprintable)
class DRUGDEALERSIMULATOR2_API UDLCBlueprintFunctionLibrary : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UDLCBlueprintFunctionLibrary();

    UFUNCTION(BlueprintCallable)
    static void OpenStore(int32 DLC_AppID);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool BIsDlcInstalled(int32 AppID);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool BIsAppInstalled(int32 AppID);
    
};

