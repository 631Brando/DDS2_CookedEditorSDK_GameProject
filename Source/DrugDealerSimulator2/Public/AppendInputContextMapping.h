#pragma once
#include "CoreMinimal.h"
#include "GameFeatureAction.h"
#include "AppendInputContextMappingEntry.h"
#include "AppendInputContextMapping.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class DRUGDEALERSIMULATOR2_API UAppendInputContextMapping : public UGameFeatureAction {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FAppendInputContextMappingEntry> InputMappings;
    
    UAppendInputContextMapping();

};

