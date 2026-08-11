#include "CartelManagerComponent.h"

UCartelManagerComponent::UCartelManagerComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->EquipmentDatabase = NULL;
    this->ShopDatabase = NULL;
    this->CharacterDatabase = NULL;
}

bool UCartelManagerComponent::UnlockNewCartelPet(FName PetID) {
    return false;
}


void UCartelManagerComponent::UnlockElement(FName UnlockGroup, FName NewUnlockElement, const FString& SpecificPlayer) {
}



void UCartelManagerComponent::SetShopReputationPoints(FName ShopID, float Amount) {
}

void UCartelManagerComponent::SetMainAccount(FGuid Guid) {
}

void UCartelManagerComponent::SetClothPrivate(FGuid ClothGuid, const FString& PlayerID) {
}

void UCartelManagerComponent::SetClientActive(FGuid ClientGuid) {
}

void UCartelManagerComponent::SetBankMoney(float CashAmount) {
}

void UCartelManagerComponent::SetAccountMoney(FGuid AccountGuid, float CashAmount) {
}

void UCartelManagerComponent::SellCollectionEquipment(FName EquipmentID, int32 Quantity) {
}

void UCartelManagerComponent::ResupplyEquipmentOffer(FName ShopID) {
}

void UCartelManagerComponent::RestockAllShops(int32 CurDayNum) {
}

void UCartelManagerComponent::ResetShopStock(FName ShopID) {
}

void UCartelManagerComponent::ResetShopBuyLimit(FName ShopID) {
}

void UCartelManagerComponent::ResetAllShopStocks() {
}

void UCartelManagerComponent::ResetAllShopsBuyLimit() {
}

void UCartelManagerComponent::RemoveShopStockItem(FName ShopID, FName OfferId, int32 Quantity) {
}

void UCartelManagerComponent::RemoveMix(FGuid MixGuid) {
}

void UCartelManagerComponent::RemoveEquipmentFromOffer(FName EquipmentID, FName ShopID, int32 Quantity) {
}

void UCartelManagerComponent::RemoveEquipmentFromCollection(FName EquipmentID, int32 Quantity) {
}

void UCartelManagerComponent::RemoveClothFromCollection(FGuid ListGuid) {
}

void UCartelManagerComponent::RemoveCharacterTerrainSpot(FGuid CharacterGuid) {
}

void UCartelManagerComponent::RemoveCharacterMaster(FGuid SlaveGuid) {
}

void UCartelManagerComponent::RemoveCartelCharacter(FGuid CharacterGuid) {
}

void UCartelManagerComponent::RemoveBankMoney(float CashAmount) {
}

void UCartelManagerComponent::RemoveAccountMoney(FGuid AccountGuid, float CashAmount) {
}

void UCartelManagerComponent::RegisterShopEarnings(FName ShopID, int32 Earnings, bool FromBuy, float AddBonus) {
}

void UCartelManagerComponent::RegisterCharactarStats(FGuid CharacterGuid, FCharacterStatData InitStats) {
}

void UCartelManagerComponent::RegisterBankAccount(FText AccountName, FName Currency, FBankAccountData& RegisteredAccount) {
}


void UCartelManagerComponent::OverrideMixSettings(FGuid MixGuid, FMixProportions MixProportions) {
}

void UCartelManagerComponent::OutputDeadDropPackage(FDeadDropPackageData PackageData) {
}


void UCartelManagerComponent::KillCartelCharacter(FGuid CharacterGuid) {
}

bool UCartelManagerComponent::IsElementUnlockedForPlayer(FName UnlockGroup, FName NewUnlockElement, const FString& PlayerID) {
    return false;
}

bool UCartelManagerComponent::IsElementUnlocked(FName UnlockGroup, FName NewUnlockElement) {
    return false;
}

bool UCartelManagerComponent::HasBankMoney(float CashAmount) {
    return false;
}

float UCartelManagerComponent::GetShopReputationPoints(FName ShopID) {
    return 0.0f;
}

int32 UCartelManagerComponent::GetShopReputationLevel(FName ShopID) {
    return 0;
}

int32 UCartelManagerComponent::GetShopOfferStock(FName ShopID, FName OfferId) {
    return 0;
}

void UCartelManagerComponent::GetShopOfferSpecial(FName ShopID, TArray<FShopOfferListItem>& OutList) {
}

void UCartelManagerComponent::GetShopOfferRotary(FName ShopID, TArray<FShopOfferListItem>& OutList) {
}

void UCartelManagerComponent::GetShopOfferRegular(FName ShopID, TArray<FShopOfferListItem>& OutList) {
}

FShopOfferItemConfig UCartelManagerComponent::GetShopOfferConfig(FName ShopID, FName OfferId) {
    return FShopOfferItemConfig{};
}

float UCartelManagerComponent::GetShopMaxReputation(FName ShopID) {
    return 0.0f;
}

FPetAnimalData UCartelManagerComponent::GetPetData(FGuid PetGuid) {
    return FPetAnimalData{};
}

int32 UCartelManagerComponent::GetNextRestockDay(FName ShopID) {
    return 0;
}

EMixStatus UCartelManagerComponent::GetMixStatus(FGuid MixGuid) {
    return EMixStatus::DoesNotExist;
}

FMixProportions UCartelManagerComponent::GetMixContents(FGuid MixGuid) {
    return FMixProportions{};
}

float UCartelManagerComponent::GetMainAccountMoney() {
    return 0.0f;
}

int32 UCartelManagerComponent::GetEquipmentPrice(FName EquipmentID, FName ShopID) {
    return 0;
}

int32 UCartelManagerComponent::GetEquipmentCollectionQuantity(FName EquipmentID) {
    return 0;
}

void UCartelManagerComponent::GetEquipmentCollectionList(EEquipmentCollectionListFilters Filter, TArray<FEquipmentCollectionListItem>& OutList) {
}

TArray<FDrugMixListItem> UCartelManagerComponent::GetDrugMixesList() {
    return TArray<FDrugMixListItem>();
}

TArray<FDrugMixListItem> UCartelManagerComponent::GetDrugMixArchive() {
    return TArray<FDrugMixListItem>();
}

TArray<FDeadDropPackageData> UCartelManagerComponent::GetDeadDropPackageList(FGuid DeadDropGuid) {
    return TArray<FDeadDropPackageData>();
}

int32 UCartelManagerComponent::GetDaysTillRestock(FName ShopID, int32 CurDay) {
    return 0;
}

int32 UCartelManagerComponent::GetCurShopBuyLimit(FName ShopID) {
    return 0;
}

int32 UCartelManagerComponent::GetCurClientCount(FName TownID) {
    return 0;
}

void UCartelManagerComponent::GetClothesCollection(const FString& PlayerFilter, TArray<FInventoryObjectData>& OutClothes) {
}

bool UCartelManagerComponent::GetClientHasOrder(FGuid ClientGuid) {
    return false;
}

FCharacterStatData UCartelManagerComponent::GetCharacterStats(FGuid CharacterGuid) {
    return FCharacterStatData{};
}

TArray<FPetAnimalData> UCartelManagerComponent::GetCartelPets() {
    return TArray<FPetAnimalData>();
}

FCartelClientOrderData UCartelManagerComponent::GetCartelClientOrderData(FGuid ClientGuid) {
    return FCartelClientOrderData{};
}

FCartelClientData UCartelManagerComponent::GetCartelClientData(FGuid ClientGuid) {
    return FCartelClientData{};
}

void UCartelManagerComponent::GetCartelCharacters(TArray<FCartelCharacterListItem>& OutList) {
}

FCharacterConfig UCartelManagerComponent::GetCartelCharacterMeta(FGuid CharacterGuid) {
    return FCharacterConfig{};
}

FCartelCharacterData UCartelManagerComponent::GetCartelCharacterData(FGuid CharacterGuid) {
    return FCartelCharacterData{};
}

ECartelCharacterJobType UCartelManagerComponent::GetCartelCharacterCurJob(FGuid CharacterGuid) {
    return ECartelCharacterJobType::Boss;
}

float UCartelManagerComponent::GetAllAccountsMoney() {
    return 0.0f;
}

void UCartelManagerComponent::GetAccountList(TArray<FBankAccountData>& AccountList) {
}

FBankAccountData UCartelManagerComponent::GetAccountData(FGuid AccountGuid) {
    return FBankAccountData{};
}

void UCartelManagerComponent::GenerateShopSpecialOffer(FName ShopID) {
}

void UCartelManagerComponent::GenerateShopRotaryOffer(FName ShopID) {
}

void UCartelManagerComponent::GenerateNewCharacter(FName CharacterID, const FString& PlayerNetID, FCharacterConfig ConfigOverride, FGuid& GeneratedGuid) {
}




int32 UCartelManagerComponent::CountCartelRanks(bool HiredOnly) {
    return 0;
}


void UCartelManagerComponent::ClientUpdateOrderStatus(FGuid ClientGuid, int32 OrderStatus) {
}

void UCartelManagerComponent::ClientGenerateOrder(FGuid ClientGuid, FCartelClientOrderData OrderData) {
}

void UCartelManagerComponent::ClearPetStation(FGuid PetGuid) {
}

void UCartelManagerComponent::ClearPetMaster(FGuid PetGuid) {
}

void UCartelManagerComponent::ClearCharacterSlaves(FGuid MasterGuid) {
}

bool UCartelManagerComponent::CheckPetUnlocked(FName PetID) {
    return false;
}

bool UCartelManagerComponent::CheckClientOrderTime(FGuid ClientGuid, FTimeData CurTime) {
    return false;
}

void UCartelManagerComponent::CharStatAddSale(FGuid CharGuid, int32 SaleGrams) {
}

void UCartelManagerComponent::CharStatAddRep(FGuid CharGuid, float RepAmount) {
}

void UCartelManagerComponent::CharacterRemoveSubstance(FGuid CharacterGuid, FSubstanceContentsData Substance) {
}

void UCartelManagerComponent::CharacterRemoveMoney(FGuid CharacterGuid, int32 CashAmount) {
}

void UCartelManagerComponent::CharacterRemoveDrug(FGuid CharacterGuid, FName DrugID, float Amount) {
}


void UCartelManagerComponent::CharacterGiveSubstance(FGuid CharacterGuid, FSubstanceContentsData Substance) {
}

void UCartelManagerComponent::CharacterGiveMoney(FGuid CharacterGuid, int32 CashAmount) {
}

bool UCartelManagerComponent::CharacterExists(FGuid CharacterGuid) {
    return false;
}



void UCartelManagerComponent::AssignPetStation(FGuid PetGuid, FGuid StationGuid) {
}

void UCartelManagerComponent::AssignPetMaster(FGuid PetGuid, const FString& PetMaster) {
}

bool UCartelManagerComponent::AssignCharacterToMaster(FGuid SlaveGuid, FGuid MasterGuid) {
    return false;
}

void UCartelManagerComponent::AssignCharacterTerrainSpot(FGuid CharacterGuid, FGuid TerrainSpotGuid) {
}

void UCartelManagerComponent::AssignCharacterJob(FGuid CharacterGuid, ECartelCharacterJobType Job) {
}

void UCartelManagerComponent::AssignCharacterHideout(FGuid CharacterGuid, FName HideoutID) {
}

void UCartelManagerComponent::ArchiveMix(FGuid MixGuid) {
}

void UCartelManagerComponent::AddShopReputationPoints(FName ShopID, float Amount) {
}

void UCartelManagerComponent::AddShopBuyLimit(FName ShopID, int32 Quantity) {
}

FGuid UCartelManagerComponent::AddNewMix(FMixProportions MixProportions) {
    return FGuid{};
}

void UCartelManagerComponent::AddNewClient(FGuid CharacterGuid, FCartelClientData ClientData) {
}

void UCartelManagerComponent::AddEquipmentToCollection(FName EquipmentID, int32 Quantity) {
}

void UCartelManagerComponent::AddEquipmentOffer(FName EquipmentID, FName ShopID, int32 Quantity, bool& New) {
}

void UCartelManagerComponent::AddDeadDropPackage(FDeadDropPackageData PackageData) {
}

void UCartelManagerComponent::AddClothToCollection(FInventoryObjectData ClothData, const FString& PrivatePlayerID) {
}

void UCartelManagerComponent::AddBankMoney(float CashAmount) {
}

void UCartelManagerComponent::AddAccountMoney(FGuid AccountGuid, float CashAmount) {
}


