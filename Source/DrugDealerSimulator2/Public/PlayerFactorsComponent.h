#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "FactorStatusDoseData.h"
#include "FactorStatusListItem.h"
#include "PlayerFactorsComponent.generated.h"

class UDataTable;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class DRUGDEALERSIMULATOR2_API UPlayerFactorsComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FFactorStatusDoseData> FactorDoses;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDataTable* FactorStatusDatabase;
    
    UPlayerFactorsComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void RemoveFactorDose(FName FactorStatusID, float Dose);
    
    UFUNCTION(BlueprintCallable)
    TArray<FFactorStatusListItem> GetFactorStatusList(bool FilterHidden);
    
    UFUNCTION(BlueprintCallable)
    float GetCurrentFactorPower(FName FactorStatusID);
    
    UFUNCTION(BlueprintCallable)
    float GetCurrentFactorDose(FName FactorStatusID);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void FactorStatusChanged(FName StatusID, bool Active);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void FactorListChanged();
    
    UFUNCTION(BlueprintCallable)
    void AddFactorDose(FName FactorStatusID, float Dose);
    
};

