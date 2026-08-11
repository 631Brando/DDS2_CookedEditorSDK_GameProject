#pragma once
#include "CoreMinimal.h"
#include "MessageResponseData.generated.h"

USTRUCT(BlueprintType)
struct FMessageResponseData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString ReponseTargetID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString ReponseTypeID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString ReponseContent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString ReponsePlayerNetID;
    
    DRUGDEALERSIMULATOR2_API FMessageResponseData();
};

