#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "UStreamlineFeatureSupport.h"
#include "UStreamlineDeepDVCMode.h"
#include "StreamlineLibraryDeepDVC.generated.h"

UCLASS(Blueprintable, MinimalAPI)
class UStreamlineLibraryDeepDVC : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UStreamlineLibraryDeepDVC();

    UFUNCTION(BlueprintCallable)
    static void SetDeepDVCSaturationBoost(float Intensity);
    
    UFUNCTION(BlueprintCallable)
    static void SetDeepDVCMode(UStreamlineDeepDVCMode DeepDVCMode);
    
    UFUNCTION(BlueprintCallable)
    static void SetDeepDVCIntensity(float Intensity);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static UStreamlineFeatureSupport QueryDeepDVCSupport();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsDeepDVCSupported();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsDeepDVCModeSupported(UStreamlineDeepDVCMode DeepDVCMode);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static TArray<UStreamlineDeepDVCMode> GetSupportedDeepDVCModes();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static UStreamlineDeepDVCMode GetDefaultDeepDVCMode();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static float GetDeepDVCSaturationBoost();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static UStreamlineDeepDVCMode GetDeepDVCMode();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static float GetDeepDVCIntensity();
    
};

