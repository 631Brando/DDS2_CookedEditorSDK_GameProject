#include "ShopOfferItemConfig.h"

FShopOfferItemConfig::FShopOfferItemConfig() {
    this->ItemType = EShopItemOfferType::Regular;
    this->ItemPrice = 0;
    this->ItemDefaultStock = 0;
    this->ItemRestockPerDay = 0;
    this->RotaryItemAddChance = 0.00f;
    this->RotaryStockMin = 0;
    this->RotaryStockMax = 0;
}

