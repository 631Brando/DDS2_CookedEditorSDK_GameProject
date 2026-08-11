#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/Actor.h"
#include "FGearSpline.generated.h"

class USplineComponent;

UCLASS(Blueprintable)
class FGEARPLUGIN_API AFGearSpline : public AActor {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USplineComponent* mSplineComp;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool mDebug;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FColor mDebugColor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mDebugThickness;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mDebugIterator;
    
public:
    AFGearSpline(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    FVector moveParam(float& P, float Distance);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector getTangent(float P) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    USplineComponent* getSpline() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector getPoint(float P) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector getDirection(float P) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getClosestParam(FVector P) const;
    
};

