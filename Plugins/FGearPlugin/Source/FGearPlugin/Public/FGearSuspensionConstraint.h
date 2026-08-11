#pragma once
#include "CoreMinimal.h"
#include "FGearTelemetryDrawer.h"
#include "FGearSuspensionConstraint.generated.h"

class UPhysicsConstraintComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class FGEARPLUGIN_API UFGearSuspensionConstraint : public UFGearTelemetryDrawer {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool mIsEnabled;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, NoClear, meta=(AllowPrivateAccess=true))
    TArray<UPhysicsConstraintComponent*> mJTS;
    
public:
    UFGearSuspensionConstraint(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void SetEnabled(bool Enable);
    
};

