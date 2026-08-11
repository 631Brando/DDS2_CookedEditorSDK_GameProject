#pragma once
#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "EInfinityCategory.h"
#include "Infinite_Compound.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class OCEANOLOGY_PLUGIN_API UInfinite_Compound : public USceneComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool Realtime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TimeJump;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EInfinityCategory InfinityCategory;
    
    UInfinite_Compound(const FObjectInitializer& ObjectInitializer);

};

