#include "Weapon.h"

Weapon::Weapon(std::string weaponName, int weaponWeight, int attackBonus)
    : name(weaponName), weight(weaponWeight), attackMod(attackBonus) {}

std::string Weapon::getName() const {
    return name;
}

std::string Weapon::getCategory() const {
    return "Weapon";
}

int Weapon::getWeight() const {
    return weight;
}

int Weapon::getAttackMod() const {
    return attackMod;
}

int Weapon::getDefenceMod() const {
    return 0;
}

int Weapon::getHealthMod() const {
    return 0;
}

int Weapon::getStrengthMod() const {
    return 0;
}

std::string Weapon::getDescription() const {
    return name + " [Weapon] - Attack: +" + std::to_string(attackMod) + ", Weight: " + std::to_string(weight);
}
