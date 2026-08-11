#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Components/ActorComponent.h"
#include "BankAccountData.h"
#include "CartelCharacterData.h"
#include "CartelCharacterListItem.h"
#include "CartelClientData.h"
#include "CartelClientOrderData.h"
#include "CharacterConfig.h"
#include "CharacterStatData.h"
#include "DeadDropPackageData.h"
#include "DrugMixListItem.h"
#include "ECartelCharacterJobType.h"
#include "EEquipmentCollectionListFilters.h"
#include "EMixStatus.h"
#include "EquipmentCollectionListItem.h"
#include "EquipmentOfferData.h"
#include "InventoryObjectData.h"
#include "MixProportions.h"
#include "PetAnimalData.h"
#include "ShopOfferItemConfig.h"
#include "ShopOfferListItem.h"
#include "ShopStockData.h"
#include "SubstanceContentsData.h"
#include "TimeData.h"
#include "UnlockGroupData.h"
#include "CartelManagerComponent.generated.h"

class UDataTable;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class DRUGDEALERSIMULATOR2_API UCartelManagerComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FGuid, FBankAccountData> BankAccounts;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGuid MainBankAccount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, FUnlockGroupData> UnlockGroupData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FGuid, FInventoryObjectData> ClothesCollectionCartel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FGuid, FString> ClothesPrivateAssigns;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDataTable* EquipmentDatabase;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDataTable* ShopDatabase;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, FEquipmentOfferData> EquipmentOffer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, int32> EquipmentCollection;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, float> ShopReputationPoints;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, int32> ShopCurBuyAmount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, FShopStockData> ShopStockUses;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, int32> ShopLastRestock;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, FShopStockData> CurStockRotary;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, FShopStockData> CurStockSpecial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDataTable* CharacterDatabase;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FGuid, FCartelCharacterData> CartelCharacters;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FGuid, FCharacterStatData> CartelCharacterStats;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FGuid, FCartelClientData> CartelClients;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FGuid, FCartelClientOrderData> CartelClientOrders;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FGuid, FPetAnimalData> CartelPets;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, FGuid> CartelPetGuids;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FDeadDropPackageData> DeadDropPackages;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FGuid, FMixProportions> DrugMixDatabase;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FGuid, FMixProportions> DrugMixArchive;
    
    UCartelManagerComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    bool UnlockNewCartelPet(FName PetID);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void UnlockLocalElement(FName GroupID, FName ElementID);
    
    UFUNCTION(BlueprintCallable)
    void UnlockElement(FName UnlockGroup, FName NewUnlockElement, const FString& SpecificPlayer);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ShopReputationLevelChange(FName ShopID, int32 NewLevel, int32 Change);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ShopItemsObtained(FName ShopID, FName OfferId, int32 Quantity);
    
    UFUNCTION(BlueprintCallable)
    void SetShopReputationPoints(FName ShopID, float Amount);
    
    UFUNCTION(BlueprintCallable)
    void SetMainAccount(FGuid Guid);
    
    UFUNCTION(BlueprintCallable)
    void SetClothPrivate(FGuid ClothGuid, const FString& PlayerID);
    
    UFUNCTION(BlueprintCallable)
    void SetClientActive(FGuid ClientGuid);
    
    UFUNCTION(BlueprintCallable)
    void SetBankMoney(float CashAmount);
    
    UFUNCTION(BlueprintCallable)
    void SetAccountMoney(FGuid AccountGuid, float CashAmount);
    
    UFUNCTION(BlueprintCallable)
    void SellCollectionEquipment(FName EquipmentID, int32 Quantity);
    
    UFUNCTION(BlueprintCallable)
    void ResupplyEquipmentOffer(FName ShopID);
    
    UFUNCTION(BlueprintCallable)
    void RestockAllShops(int32 CurDayNum);
    
    UFUNCTION(BlueprintCallable)
    void ResetShopStock(FName ShopID);
    
    UFUNCTION(BlueprintCallable)
    void ResetShopBuyLimit(FName ShopID);
    
    UFUNCTION(BlueprintCallable)
    void ResetAllShopStocks();
    
    UFUNCTION(BlueprintCallable)
    void ResetAllShopsBuyLimit();
    
    UFUNCTION(BlueprintCallable)
    void RemoveShopStockItem(FName ShopID, FName OfferId, int32 Quantity);
    
    UFUNCTION(BlueprintCallable)
    void RemoveMix(FGuid MixGuid);
    
    UFUNCTION(BlueprintCallable)
    void RemoveEquipmentFromOffer(FName EquipmentID, FName ShopID, int32 Quantity);
    
    UFUNCTION(BlueprintCallable)
    void RemoveEquipmentFromCollection(FName EquipmentID, int32 Quantity);
    
    UFUNCTION(BlueprintCallable)
    void RemoveClothFromCollection(FGuid ListGuid);
    
    UFUNCTION(BlueprintCallable)
    void RemoveCharacterTerrainSpot(FGuid CharacterGuid);
    
    UFUNCTION(BlueprintCallable)
    void RemoveCharacterMaster(FGuid SlaveGuid);
    
    UFUNCTION(BlueprintCallable)
    void RemoveCartelCharacter(FGuid CharacterGuid);
    
    UFUNCTION(BlueprintCallable)
    void RemoveBankMoney(float CashAmount);
    
    UFUNCTION(BlueprintCallable)
    void RemoveAccountMoney(FGuid AccountGuid, float CashAmount);
    
    UFUNCTION(BlueprintCallable)
    void RegisterShopEarnings(FName ShopID, int32 Earnings, bool FromBuy, float AddBonus);
    
    UFUNCTION(BlueprintCallable)
    void RegisterCharactarStats(FGuid CharacterGuid, FCharacterStatData InitStats);
    
    UFUNCTION(BlueprintCallable)
    void RegisterBankAccount(FText AccountName, FName Currency, FBankAccountData& RegisteredAccount);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void PetDataChanged();
    
    UFUNCTION(BlueprintCallable)
    void OverrideMixSettings(FGuid MixGuid, FMixProportions MixProportions);
    
    UFUNCTION(BlueprintCallable)
    void OutputDeadDropPackage(FDeadDropPackageData PackageData);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void MixListChanged();
    
    UFUNCTION(BlueprintCallable)
    void KillCartelCharacter(FGuid CharacterGuid);
    
    UFUNCTION(BlueprintCallable)
    bool IsElementUnlockedForPlayer(FName UnlockGroup, FName NewUnlockElement, const FString& PlayerID);
    
    UFUNCTION(BlueprintCallable)
    bool IsElementUnlocked(FName UnlockGroup, FName NewUnlockElement);
    
    UFUNCTION(BlueprintCallable)
    bool HasBankMoney(float CashAmount);
    
    UFUNCTION(BlueprintCallable)
    float GetShopReputationPoints(FName ShopID);
    
    UFUNCTION(BlueprintCallable)
    int32 GetShopReputationLevel(FName ShopID);
    
    UFUNCTION(BlueprintCallable)
    int32 GetShopOfferStock(FName ShopID, FName OfferId);
    
    UFUNCTION(BlueprintCallable)
    void GetShopOfferSpecial(FName ShopID, TArray<FShopOfferListItem>& OutList);
    
    UFUNCTION(BlueprintCallable)
    void GetShopOfferRotary(FName ShopID, TArray<FShopOfferListItem>& OutList);
    
    UFUNCTION(BlueprintCallable)
    void GetShopOfferRegular(FName ShopID, TArray<FShopOfferListItem>& OutList);
    
    UFUNCTION(BlueprintCallable)
    FShopOfferItemConfig GetShopOfferConfig(FName ShopID, FName OfferId);
    
    UFUNCTION(BlueprintCallable)
    float GetShopMaxReputation(FName ShopID);
    
    UFUNCTION(BlueprintCallable)
    FPetAnimalData GetPetData(FGuid PetGuid);
    
    UFUNCTION(BlueprintCallable)
    int32 GetNextRestockDay(FName ShopID);
    
    UFUNCTION(BlueprintCallable)
    EMixStatus GetMixStatus(FGuid MixGuid);
    
    UFUNCTION(BlueprintCallable)
    FMixProportions GetMixContents(FGuid MixGuid);
    
    UFUNCTION(BlueprintCallable)
    float GetMainAccountMoney();
    
    UFUNCTION(BlueprintCallable)
    int32 GetEquipmentPrice(FName EquipmentID, FName ShopID);
    
    UFUNCTION(BlueprintCallable)
    int32 GetEquipmentCollectionQuantity(FName EquipmentID);
    
    UFUNCTION(BlueprintCallable)
    void GetEquipmentCollectionList(EEquipmentCollectionListFilters Filter, TArray<FEquipmentCollectionListItem>& OutList);
    
    UFUNCTION(BlueprintCallable)
    TArray<FDrugMixListItem> GetDrugMixesList();
    
    UFUNCTION(BlueprintCallable)
    TArray<FDrugMixListItem> GetDrugMixArchive();
    
    UFUNCTION(BlueprintCallable)
    TArray<FDeadDropPackageData> GetDeadDropPackageList(FGuid DeadDropGuid);
    
    UFUNCTION(BlueprintCallable)
    int32 GetDaysTillRestock(FName ShopID, int32 CurDay);
    
    UFUNCTION(BlueprintCallable)
    int32 GetCurShopBuyLimit(FName ShopID);
    
    UFUNCTION(BlueprintCallable)
    int32 GetCurClientCount(FName TownID);
    
    UFUNCTION(BlueprintCallable)
    void GetClothesCollection(const FString& PlayerFilter, TArray<FInventoryObjectData>& OutClothes);
    
    UFUNCTION(BlueprintCallable)
    bool GetClientHasOrder(FGuid ClientGuid);
    
    UFUNCTION(BlueprintCallable)
    FCharacterStatData GetCharacterStats(FGuid CharacterGuid);
    
    UFUNCTION(BlueprintCallable)
    TArray<FPetAnimalData> GetCartelPets();
    
    UFUNCTION(BlueprintCallable)
    FCartelClientOrderData GetCartelClientOrderData(FGuid ClientGuid);
    
    UFUNCTION(BlueprintCallable)
    FCartelClientData GetCartelClientData(FGuid ClientGuid);
    
    UFUNCTION(BlueprintCallable)
    void GetCartelCharacters(TArray<FCartelCharacterListItem>& OutList);
    
    UFUNCTION(BlueprintCallable)
    FCharacterConfig GetCartelCharacterMeta(FGuid CharacterGuid);
    
    UFUNCTION(BlueprintCallable)
    FCartelCharacterData GetCartelCharacterData(FGuid CharacterGuid);
    
    UFUNCTION(BlueprintCallable)
    ECartelCharacterJobType GetCartelCharacterCurJob(FGuid CharacterGuid);
    
    UFUNCTION(BlueprintCallable)
    float GetAllAccountsMoney();
    
    UFUNCTION(BlueprintCallable)
    void GetAccountList(TArray<FBankAccountData>& AccountList);
    
    UFUNCTION(BlueprintCallable)
    FBankAccountData GetAccountData(FGuid AccountGuid);
    
    UFUNCTION(BlueprintCallable)
    void GenerateShopSpecialOffer(FName ShopID);
    
    UFUNCTION(BlueprintCallable)
    void GenerateShopRotaryOffer(FName ShopID);
    
    UFUNCTION(BlueprintCallable)
    void GenerateNewCharacter(FName CharacterID, const FString& PlayerNetID, FCharacterConfig ConfigOverride, FGuid& GeneratedGuid);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void EquipmentCollectionChanged();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void DrugMixRemoved(FGuid MixGuid);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void DeadDropPackagesChanged();
    
    UFUNCTION(BlueprintCallable)
    int32 CountCartelRanks(bool HiredOnly);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ClothCollectionChanged();
    
    UFUNCTION(BlueprintCallable)
    void ClientUpdateOrderStatus(FGuid ClientGuid, int32 OrderStatus);
    
    UFUNCTION(BlueprintCallable)
    void ClientGenerateOrder(FGuid ClientGuid, FCartelClientOrderData OrderData);
    
    UFUNCTION(BlueprintCallable)
    void ClearPetStation(FGuid PetGuid);
    
    UFUNCTION(BlueprintCallable)
    void ClearPetMaster(FGuid PetGuid);
    
    UFUNCTION(BlueprintCallable)
    void ClearCharacterSlaves(FGuid MasterGuid);
    
    UFUNCTION(BlueprintCallable)
    bool CheckPetUnlocked(FName PetID);
    
    UFUNCTION(BlueprintCallable)
    bool CheckClientOrderTime(FGuid ClientGuid, FTimeData CurTime);
    
    UFUNCTION(BlueprintCallable)
    void CharStatAddSale(FGuid CharGuid, int32 SaleGrams);
    
    UFUNCTION(BlueprintCallable)
    void CharStatAddRep(FGuid CharGuid, float RepAmount);
    
    UFUNCTION(BlueprintCallable)
    void CharacterRemoveSubstance(FGuid CharacterGuid, FSubstanceContentsData Substance);
    
    UFUNCTION(BlueprintCallable)
    void CharacterRemoveMoney(FGuid CharacterGuid, int32 CashAmount);
    
    UFUNCTION(BlueprintCallable)
    void CharacterRemoveDrug(FGuid CharacterGuid, FName DrugID, float Amount);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void CharacterRemoved(FGuid CharGuid);
    
    UFUNCTION(BlueprintCallable)
    void CharacterGiveSubstance(FGuid CharacterGuid, FSubstanceContentsData Substance);
    
    UFUNCTION(BlueprintCallable)
    void CharacterGiveMoney(FGuid CharacterGuid, int32 CashAmount);
    
    UFUNCTION(BlueprintCallable)
    bool CharacterExists(FGuid CharacterGuid);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void CharacterDataChanged(FGuid CharGuid);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void BankMoneyChanged(float CurBankMoney);
    
    UFUNCTION(BlueprintCallable)
    void AssignPetStation(FGuid PetGuid, FGuid StationGuid);
    
    UFUNCTION(BlueprintCallable)
    void AssignPetMaster(FGuid PetGuid, const FString& PetMaster);
    
    UFUNCTION(BlueprintCallable)
    bool AssignCharacterToMaster(FGuid SlaveGuid, FGuid MasterGuid);
    
    UFUNCTION(BlueprintCallable)
    void AssignCharacterTerrainSpot(FGuid CharacterGuid, FGuid TerrainSpotGuid);
    
    UFUNCTION(BlueprintCallable)
    void AssignCharacterJob(FGuid CharacterGuid, ECartelCharacterJobType Job);
    
    UFUNCTION(BlueprintCallable)
    void AssignCharacterHideout(FGuid CharacterGuid, FName HideoutID);
    
    UFUNCTION(BlueprintCallable)
    void ArchiveMix(FGuid MixGuid);
    
    UFUNCTION(BlueprintCallable)
    void AddShopReputationPoints(FName ShopID, float Amount);
    
    UFUNCTION(BlueprintCallable)
    void AddShopBuyLimit(FName ShopID, int32 Quantity);
    
    UFUNCTION(BlueprintCallable)
    FGuid AddNewMix(FMixProportions MixProportions);
    
    UFUNCTION(BlueprintCallable)
    void AddNewClient(FGuid CharacterGuid, FCartelClientData ClientData);
    
    UFUNCTION(BlueprintCallable)
    void AddEquipmentToCollection(FName EquipmentID, int32 Quantity);
    
    UFUNCTION(BlueprintCallable)
    void AddEquipmentOffer(FName EquipmentID, FName ShopID, int32 Quantity, bool& New);
    
    UFUNCTION(BlueprintCallable)
    void AddDeadDropPackage(FDeadDropPackageData PackageData);
    
    UFUNCTION(BlueprintCallable)
    void AddClothToCollection(FInventoryObjectData ClothData, const FString& PrivatePlayerID);
    
    UFUNCTION(BlueprintCallable)
    void AddBankMoney(float CashAmount);
    
    UFUNCTION(BlueprintCallable)
    void AddAccountMoney(FGuid AccountGuid, float CashAmount);
    
};

