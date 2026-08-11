#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Components/ActorComponent.h"
#include "EMoneyDenomination.h"
#include "InventoryGridData.h"
#include "InventoryObjectData.h"
#include "InventoryWeightDetails.h"
#include "ItemData.h"
#include "PropertyListItem.h"
#include "QuestSlotListItem.h"
#include "SpecialSlotListItem.h"
#include "InventoryComponent.generated.h"

class UDataTable;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class DRUGDEALERSIMULATOR2_API UInventoryComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName InventoryConfig;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 BaseQuickSlotCount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool IsPlayerInventory;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FGuid, FInventoryObjectData> StoredItems;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, FInventoryObjectData> SpecialItems;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, FInventoryObjectData> WornClothes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<int32, FGuid> AssignedIndexes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, int32> QuestItems;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> SpecialSlots;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool UsesClothes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool UnboundSize;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ItemTypeRestriction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDataTable* ClothesSlotDT;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDataTable* ItemDatabase;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDataTable* ConfigDatabase;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDataTable* PropertyDatabase;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDataTable* ItemConvertionDatabase;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, FName> CurrencySmallMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, FName> CurrencyLargeMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, FName> DefaultClothes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 CustomSizeBoost;
    
    UInventoryComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    bool UseStackItem(FGuid StackGuid);
    
    UFUNCTION(BlueprintCallable)
    int32 UseItemType(FName SpecialTypeID, int32 UseQuantity);
    
    UFUNCTION(BlueprintCallable)
    bool TrySetSpecialSlotContent(FName SlotID, FInventoryObjectData content);
    
    UFUNCTION(BlueprintCallable)
    bool TrySetClothesSlotContent(FName SlotID, FInventoryObjectData content);
    
    UFUNCTION(BlueprintCallable)
    bool SwitchStacks(FGuid Stack01, FGuid Stack02);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SpecialSlotsUpdated();
    
    UFUNCTION(BlueprintCallable)
    void SpecialSlotDamage(FName SlotID, float Damage, bool DestroyOnZero);
    
    UFUNCTION(BlueprintCallable)
    void SetDefaultClothes();
    
    UFUNCTION(BlueprintCallable)
    void SetCustomSizeBoost(int32 SizeBoost);
    
    UFUNCTION(BlueprintCallable)
    void SetBlockInventoryUpdate(bool BlockState);
    
    UFUNCTION(BlueprintCallable)
    bool RemoveStackQuantity(FGuid StackGuid, int32 Quantity);
    
    UFUNCTION(BlueprintCallable)
    bool RemoveStack(FGuid StackGuid);
    
    UFUNCTION(BlueprintCallable)
    void RemoveSpecialSlotItem(FName SlotID);
    
    UFUNCTION(BlueprintCallable)
    void RemoveQuestItem(FName ItemId, int32 Quantity);
    
    UFUNCTION(BlueprintCallable)
    void RemoveItemQuantity(FName ItemId, int32 Quantity, int32& RemovedTotal);
    
    UFUNCTION(BlueprintCallable)
    void RemoveClothItem(FName SlotID);
    
    UFUNCTION(BlueprintCallable)
    void RemoveAllQuestItems(FName ItemId);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void QuickSlotsUpdated();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void QuickSlotDestroyed();
    
    UFUNCTION(BlueprintCallable)
    void QuickSlotDamage(int32 Index, float Damage, bool DestroyOnZero);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void QuestItemsUpdated();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void QuestItemRemoved(FName ItemId);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void QuestItemAdded(FName ItemId);
    
    UFUNCTION(BlueprintCallable)
    void PurgeQuestItems();
    
    UFUNCTION(BlueprintCallable)
    void PurgeInventory();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void NewKeyObtained(FName KeyID);
    
    UFUNCTION(BlueprintCallable)
    void MoveItem(FGuid ItemToMove, int32 TargetIndex, int32 MoveQuantity, bool& CanMove, int32& StackLeft);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ItemTypeFailure(FName ItemId);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ItemRemoved(FName ItemId, int32 Quantity);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ItemAdded(FName ItemId, int32 Qantity);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void InventoryUpdated();
    
    UFUNCTION(BlueprintCallable)
    bool HasQuestItem(FName ItemId, int32 Quantity);
    
    UFUNCTION(BlueprintCallable)
    bool HasInventorySpaceForTransaction(FName ItemId, int32 ItemCount, TArray<FGuid> SourceGuids, TArray<int32> SourceQuantities);
    
    UFUNCTION(BlueprintCallable)
    void GetWornAllClothes(TArray<FInventoryObjectData>& OutClothes);
    
    UFUNCTION(BlueprintCallable)
    void GetSpecialSlotsList(TArray<FSpecialSlotListItem>& OutSlots);
    
    UFUNCTION(BlueprintCallable)
    FInventoryGridData GetSpecialSlotContent(FName SlotID);
    
    UFUNCTION(BlueprintCallable)
    int32 GetQuickSlotNum();
    
    UFUNCTION(BlueprintCallable)
    TArray<FInventoryGridData> GetQuickSlotList();
    
    UFUNCTION(BlueprintCallable)
    FInventoryObjectData GetQuickSlotItemData(int32 Index);
    
    UFUNCTION(BlueprintCallable)
    FName GetQuickSlotItem(int32 Index);
    
    UFUNCTION(BlueprintCallable)
    TArray<FQuestSlotListItem> GetQuestItemList();
    
    UFUNCTION(BlueprintCallable)
    void GetInventoryWeight(float& WeightTotal, FInventoryWeightDetails& WeightDetails);
    
    UFUNCTION(BlueprintCallable)
    int32 GetInventoryStackSpaceDynamic(FInventoryObjectData ObjectData);
    
    UFUNCTION(BlueprintCallable)
    int32 GetInventoryStackSpace(FName ItemId);
    
    UFUNCTION(BlueprintCallable)
    int32 GetInventoryLenght();
    
    UFUNCTION(BlueprintCallable)
    int32 GetInventoryItemSpace(FName ItemId);
    
    UFUNCTION(BlueprintCallable)
    void GetInventoryGrid(TArray<FInventoryGridData>& OutGridData);
    
    UFUNCTION(BlueprintCallable)
    int32 GetInventoryFreeSpace();
    
    UFUNCTION(BlueprintCallable)
    int32 GetInventoryDamagedSlotCount();
    
    UFUNCTION(BlueprintCallable)
    int32 GetInventoryConceladSlotCount();
    
    UFUNCTION(BlueprintCallable)
    FItemData GetDynamicPackageMeta(FInventoryObjectData ObjectData);
    
    UFUNCTION(BlueprintCallable)
    void GetClothSlotsList(TArray<FSpecialSlotListItem>& OutSlots);
    
    UFUNCTION(BlueprintCallable)
    void GetClothesStats(TArray<FPropertyListItem>& AllProperties);
    
    UFUNCTION(BlueprintCallable)
    FInventoryGridData GetClothesSlotContent(FName SlotID);
    
    UFUNCTION(BlueprintCallable)
    TArray<FInventoryObjectData> DecodeInventoryContentString(const FString& JsonString);
    
    UFUNCTION(BlueprintCallable)
    FString CreateInventoryContentString(const TArray<FInventoryObjectData>& InventoryData);
    
    UFUNCTION(BlueprintCallable)
    int32 CountPlayerMoney(FName CurrencyID);
    
    UFUNCTION(BlueprintCallable)
    void CountItems(FName ItemId, FName ItemSpecialType, bool SumAmounts, int32& OutNumber);
    
    UFUNCTION(BlueprintCallable)
    FInventoryObjectData ConstructInventoryDefaults(FName SourceItemID);
    
    UFUNCTION(BlueprintCallable)
    bool CompareItemsStackable(FInventoryObjectData Object1, FInventoryObjectData Object2);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ClothesUpdated();
    
    UFUNCTION(BlueprintCallable)
    bool CheckStackQuantityExists(FGuid StackGuid, int32 Quantity);
    
    UFUNCTION(BlueprintCallable)
    bool CheckStackExists(FGuid StackGuid);
    
    UFUNCTION(BlueprintCallable)
    bool CheckIndexOccupied(int32 IndexToCheck);
    
    UFUNCTION(BlueprintCallable)
    void ChargePlayerMoney(FName CurrencyID, int32 Quantity);
    
    UFUNCTION(BlueprintCallable)
    void AddSpecificItem(FInventoryObjectData InventoryData, bool CheckOnly, int32& Leftover, int32 Quantity, int32 IndexOverride);
    
    UFUNCTION(BlueprintCallable)
    void AddQuestItem(FName ItemId, int32 Quantity);
    
    UFUNCTION(BlueprintCallable)
    void AddNewItemArray(TArray<FName> ItemIDs, TArray<int32> Quantities);
    
    UFUNCTION(BlueprintCallable)
    void AddNewItem(FName ItemId, int32 Quantity, bool CheckOnly, const FString& TimeoutStatus, int32& Leftover);
    
    UFUNCTION(BlueprintCallable)
    void AddMoney(FName CurrencyID, EMoneyDenomination Denomination, int32 Quantity);
    
    UFUNCTION(BlueprintCallable)
    void AddClothDamage(FName SlotID, float Damage);

protected:
    // modkit: not reflected properties (no UPROPERTY) in the real source, so the SDK's reflection-based header
    // dump never picked them up even though the compiled game still has them. Restored from real dev-provided
    // source so the ported logic below (which reads/writes both) has somewhere to live.
    bool BlockInventoryUpdate = false;
    int32 PropertyConcealedSlots = 0;

};

