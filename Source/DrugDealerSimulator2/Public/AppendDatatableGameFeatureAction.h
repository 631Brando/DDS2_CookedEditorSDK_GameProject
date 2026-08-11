#pragma once
#include "CoreMinimal.h"
#include "GameFeatureAction.h"
#include "AppendDatatableGameFeatureAction.generated.h"

class UDataTable;

UCLASS(Blueprintable, EditInlineNew)
class DRUGDEALERSIMULATOR2_API UAppendDatatableGameFeatureAction : public UGameFeatureAction {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UDataTable> DataTableToAppendTo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UDataTable> DataTableToAppendFrom;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bRuntimeFeatureActionActivation;
    
public:
    UAppendDatatableGameFeatureAction();

};

