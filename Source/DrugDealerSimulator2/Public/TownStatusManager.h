#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DrugDemandListResult.h"
#include "RandomClientData.h"
#include "TownDistrictDemand.h"
#include "TownStatusManager.generated.h"

class UDataTable;

UCLASS(Blueprintable)
class DRUGDEALERSIMULATOR2_API ATownStatusManager : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDataTable* DrugDatabase;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDataTable* TownDatabase;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName TownID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, float> DrugDemandLevel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, bool> DrugSaleEnabled;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, FTownDistrictDemand> DistrictDemands;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FRandomClientData> RandomClients;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, int32> DrugPricesSet;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CurTownReputationLevel;
    
    ATownStatusManager(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void TownRepChanged();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void TownDemandChanged();
    
    UFUNCTION(BlueprintCallable)
    void SetDrugSaleEnabled(FName DrugID, bool IsEnabled);
    
    UFUNCTION(BlueprintCallable)
    void SetDrugPrice(FName DrugID, int32 DrugPrice);
    
    UFUNCTION(BlueprintCallable)
    void SetDrugDemand(FName DrugID, FName DistrictID, float DemandAmount, bool ForceCreate);
    
    UFUNCTION(BlueprintCallable)
    void RemoveDrugDemand(FName DrugID, FName DistrictID, float DemandAmount);
    
    UFUNCTION(BlueprintCallable)
    bool HasDrugOffer();
    
    UFUNCTION(BlueprintCallable)
    void GetTownReputation(int32& ReputationLevel, float& ReputationValue);
    
    UFUNCTION(BlueprintCallable)
    bool GetDrugSaleEnabled(FName DrugID);
    
    UFUNCTION(BlueprintCallable)
    int32 GetDrugPrice(FName DrugID);
    
    UFUNCTION(BlueprintCallable)
    float GetDrugMultiplier(FName DrugID);
    
    UFUNCTION(BlueprintCallable)
    void GetDrugDemandList(FName DistrictID, TArray<FDrugDemandListResult>& OutList);
    
    UFUNCTION(BlueprintCallable)
    float GetDrugDemand(FName DrugID, FName DistrictID);
    
    UFUNCTION(BlueprintCallable)
    void ChangeTownReputation(float ReputationChange);
    
    UFUNCTION(BlueprintCallable)
    float CalcMaxReputationPool();
    
    UFUNCTION(BlueprintCallable)
    void AddDrugDemand(FName DrugID, FName DistrictID, float DemandAmount, bool ForceCreate);
    
};

