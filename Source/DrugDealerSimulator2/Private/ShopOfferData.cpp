#include "ShopOfferData.h"

FShopOfferData::FShopOfferData() {
    this->ShopImage = NULL;
    this->ShopOffer = NULL;
    this->ShopType = EShopType::ItemShop;
    this->ShopRestockInterval = 0;
    this->ShopCanPayCheck = false;
    this->TownReputationRangeMax = 0.00f;
    this->ReputationGainPerMoneyUnit = 0.00f;
    this->ReputationGainPerMoneyUnitSale = 0.00f;
}

