#pragma once
#include "CoreMinimal.h"
#include "EOceanologyBubbleActivation.h"
#include "OceanologyBubbles.h"
#include "OceanologyBubblesSettings.generated.h"

class UMaterialInterface;
class UNiagaraSystem;

USTRUCT(BlueprintType)
struct FOceanologyBubblesSettings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<EOceanologyBubbleActivation> EnableBubbles;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOceanologyBubbles Bubbles;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 BubbleSpawnCount;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double BubbleSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UMaterialInterface> BubblesMaterial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UNiagaraSystem> BubblesEffect;
    
    OCEANOLOGY_PLUGIN_API FOceanologyBubblesSettings();
};

