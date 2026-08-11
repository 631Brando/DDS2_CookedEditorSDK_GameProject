#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Riverology_PluginBPLibrary.generated.h"

class ALandscape;
class ULandscapeLayerInfoObject;
class USplineComponent;
class USplineMeshComponent;

UCLASS(Blueprintable)
class URiverology_PluginBPLibrary : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    URiverology_PluginBPLibrary();

    UFUNCTION(BlueprintCallable)
    static void SetSplineStartEndLocationTangentScale(const USplineComponent* SplineComponent, USplineMeshComponent* SplineMesh, const int32 Index, const float GlobalScale, const float AdjustedLength, const float SegmentLength);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static ULandscapeLayerInfoObject* GetEditorPaintLayer(ALandscape* Landscape, const FName PaintLayerName);
    
    UFUNCTION(BlueprintCallable)
    static void CalculateSplineLength(const USplineComponent* SplineComponent, const float SegmentLength, float& TotalSplineLength, float& AdjustedLength, int32& LastIndex);
    
};

