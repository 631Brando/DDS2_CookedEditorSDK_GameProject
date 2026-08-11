#include "MeleeWeaponData.h"

FMeleeWeaponData::FMeleeWeaponData() {
    this->WeaponType = EWeaponType::OneHandedBat;
    this->WeaponMesh = NULL;
    this->Concealed = false;
    this->WeaponDamage = 0.00f;
    this->WeaponRange = 0.00f;
    this->WeaponSpeed = 0.00f;
    this->WeaponStaminaUseSwing = 0.00f;
    this->WeaponForce = 0.00f;
    this->WeaponBleedChance = 0.00f;
    this->WeaponStunChance = 0.00f;
    this->WeaponFearFactor = 0.00f;
    this->WeaponSusFactor = 0.00f;
}

