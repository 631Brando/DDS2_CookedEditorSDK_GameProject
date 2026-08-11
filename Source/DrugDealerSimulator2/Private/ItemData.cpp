#include "ItemData.h"

FItemData::FItemData() {
    this->ItemIcon = NULL;
    this->ItemTier = 0;
    this->ItemDisplayQuantity = 0;
    this->ItemCategory = EItemCategory::Miscellaneous;
    this->SpawnActorClass = NULL;
    this->ClothThickness = 0.00f;
    this->InventoryMaxStack = 0;
    this->InventoryWeightGrams = 0.00f;
    this->InventoryMaxHealth = 0.00f;
    this->InventoryMaxUses = 0;
    this->InventorySizeNerf = 0;
    this->CanPlaceQuickslot = false;
    this->UseOnHotkey = false;
    this->UseTimeoutSeconds = 0.00f;
    this->ValuePerPiece = 0;
}

