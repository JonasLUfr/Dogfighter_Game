#include "Enhance.h"

Enhance::Enhance() : weaponLevel(1), weaponTrajectory(1), weaponFireRate(1.0f) {
    updateWeaponAttributes();
}

int Enhance::getWeaponLevel() const {
    return weaponLevel;
}

bool Enhance::upgradeWeapon(int points) {
    const int requiredPoints = weaponLevel * 10;

    if (points >= requiredPoints) {
        weaponLevel++;
        updateWeaponAttributes();
        return true;
    }

    return false;
}

int Enhance::getWeaponTrajectory() const {
    return weaponTrajectory;
}

float Enhance::getWeaponFireRate() const {
    return weaponFireRate;
}

void Enhance::updateWeaponAttributes() {
    weaponTrajectory += 1;
    weaponFireRate -= 100 ;
}
