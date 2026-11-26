#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/Actor.h"
#include "CraftingQueryItem.h"
#include "HideoutDeployedEqData.h"
#include "MixingQueryItem.h"
#include "PropertyListItem.h"
#include "StoredSubstanceData.h"
#include "HideoutMaster.generated.h"

class UDataTable;

UCLASS(Blueprintable)
class DRUGDEALERSIMULATOR2_API AHideoutMaster : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName HideoutID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDataTable* HideoutDatabase;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDataTable* EquipmentDatabase;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDataTable* CraftingStationDatabase;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDataTable* SubstanceDatabase;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDataTable* CraftingRecipiesDatabase;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, float> CraftingStationSpeedMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CheatCraftSpeedMultiplier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FGuid, FHideoutDeployedEqData> DeployedEquipment;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, int32> DeployedEqQuantities;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, FStoredSubstanceData> StoredSubstances;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FGuid, FStoredSubstanceData> StoredMixes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FGuid, FCraftingQueryItem> CraftingQuery;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FGuid, FMixingQueryItem> MixingQuery;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FGuid> CraftingQueryPriority;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool CraftingTickEnabled;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool CraftFillDuplicated;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, float> CurEquipmentProperties;
    
    AHideoutMaster(const FObjectInitializer& ObjectInitializer);

    virtual void Tick(float DeltaSeconds) override;

    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void WasteGenerated(float WasteAmount);
    
    UFUNCTION(BlueprintCallable)
    void UpdateEquipmentProperties();
    
    UFUNCTION(BlueprintCallable)
    bool UpdateDeployedEquipmentTransform(FHideoutDeployedEqData EqData, FGuid EqGuid);
    
    UFUNCTION(BlueprintCallable)
    void UpdateCraftingFlow(float TimeElapsed);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void TryOutputCraft(FName CraftID, FGuid QueryGuid, FGuid EquipmentGuid, bool Simulation);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SubstanceStorageChanged();
    
    UFUNCTION(BlueprintCallable)
    void SetCraftingTickEnabled(bool TickEnabled, float TimeElapsed);
    
    UFUNCTION(BlueprintCallable)
    void SetCheatCraftMultiplier(float NewMultiplier);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ReturnCraftingContents(FName RecipieID, int32 Quantity);
    
    UFUNCTION(BlueprintCallable)
    void RemoveSubstance(FName SubstanceID, float RemoveAmount, bool RemoveAll);
    
    UFUNCTION(BlueprintCallable)
    void RemoveMix(FGuid MixGuid, float RemoveAmount, bool RemoveAll);
    
    UFUNCTION(BlueprintCallable)
    void RemoveDeployedEquipment(FGuid EqGuid);
    
    UFUNCTION(BlueprintCallable)
    void PurgeAllSubstanceStorage();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OutputMixingBatch(FGuid MixGuid, FGuid StationGuid, float BatchSize);
    
    UFUNCTION(BlueprintCallable)
    void OutputCraftingQueryItem(FGuid ItemGuid, bool Simulation, float SpeedOverride, float CartelSpeedMultiplier);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void NewSubstanceProduced(FGuid StationGuid, FName SubstanceID, float BatchSize);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void MixQueryCancelled(FGuid QueryGuid);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void MixingQueryChanged();
    
    UFUNCTION(BlueprintCallable)
    void LoopCraftingQuery(FGuid ItemGuid);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void HideoutPropertiesChanged();
    
    UFUNCTION(BlueprintCallable)
    float GetTotalWasteAmount();
    
    UFUNCTION(BlueprintCallable)
    float GetTotalStorageMass();
    
    UFUNCTION(BlueprintCallable)
    float GetTotalStorageFreeSpace();
    
    UFUNCTION(BlueprintCallable)
    void GetSubstanceStorageSize(FName SubstanceID, bool DedicatedOnly, float& TotalStored, float& MaxStorage);
    
    UFUNCTION(BlueprintCallable)
    void GetSubstanceList(TArray<FStoredSubstanceData>& SubstanceList);
    
    UFUNCTION(BlueprintCallable)
    void GetMixStorageSize(FGuid MixGuid, bool DedicatedOnly, float& TotalStored, float& MaxStorage);
    
    UFUNCTION(BlueprintCallable)
    TArray<FMixingQueryItem> GetMixingQuery(FGuid EquipmentGuid, bool SkipFiltering);
    
    UFUNCTION(BlueprintCallable)
    float GetMaxGeneralStorage();
    
    UFUNCTION(BlueprintCallable)
    TArray<FPropertyListItem> GetHideoutTotalProperties();
    
    UFUNCTION(BlueprintCallable)
    float GetHideoutPropertyValue(FName PropertyID);
    
    UFUNCTION(BlueprintCallable)
    TArray<FPropertyListItem> GetHideoutDefaultProperties();
    
    UFUNCTION(BlueprintCallable)
    TArray<FStoredSubstanceData> GetDrugStock();
    
    UFUNCTION(BlueprintCallable)
    TArray<FPropertyListItem> GetDeployedEquipmentProperties();
    
    UFUNCTION(BlueprintCallable)
    int32 GetDeployedEqCount(const FName& EquipmentID);
    
    UFUNCTION(BlueprintCallable)
    void GetCraftingQuery(FGuid EquipmentGuid, bool SkipFiltering, TArray<FCraftingQueryItem>& OutQuery);
    
    UFUNCTION(BlueprintCallable)
    FGuid GetCraftDuplicate(FName RecipieID, FGuid StationGuid);
    
    UFUNCTION(BlueprintCallable)
    float GetCategoryMaxStorage(FGuid CategoryGuid);
    
    UFUNCTION(BlueprintCallable)
    void GatherCraftingSationMaps();
    
    UFUNCTION(BlueprintCallable)
    void CraftingTick(float deltaTime, bool Simulation);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void CraftingQueryChanged();
    
    UFUNCTION(BlueprintCallable)
    int32 CheckMaxCrafterQuerySpace(FGuid CrafterGuid, bool HasLabTech);
    
    UFUNCTION(BlueprintCallable)
    bool CheckCanFitSubstance(FName SubstanceID, float SubstanceAmount);
    
    UFUNCTION(BlueprintCallable)
    bool CheckCanFitMix(FName MixGuid, float MixAmount);
    
    UFUNCTION(BlueprintCallable)
    bool CanDeployEquipmentCount(const FName& EquipmentID, const int32& Quantity);
    
    UFUNCTION(BlueprintCallable)
    void CancelCraftingQuery(FGuid QueryGuid);
    
    UFUNCTION(BlueprintCallable)
    void AddSubstance(FName SubstanceID, float SubstanceAmount, bool SkipUpdate, float& Leftover);
    
    UFUNCTION(BlueprintCallable)
    void AddMixingQueue(FMixingQueryItem MixQueryConfig);
    
    UFUNCTION(BlueprintCallable)
    void AddMix(FGuid MixGuid, float MixAmount, bool SkipUpdate);
    
    UFUNCTION(BlueprintCallable)
    FGuid AddDeployedEquipment(FHideoutDeployedEqData EqData, FGuid GuidOverride, int32 Quantity);
    
    UFUNCTION(BlueprintCallable)
    void AddCraftingQueue(FName RecipieID, FGuid CraftingStationGuid, int32 Quantity, float EqSpeedMultiplier, bool InsertFirst);

private:
    // Acknowledgements belong to the current synchronous Blueprint output attempt.
    FGuid PieOutputAttempt;
    bool bPieCraftTickInProgress = false;
};

