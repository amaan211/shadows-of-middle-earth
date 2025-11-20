/**
 * @file Weapon.cpp
 * @brief Implementation of Weapon class
 */

#include "Weapon.h"

/**
 * @brief Constructs a Weapon object
 * @param weaponName Name of the weapon
 * @param weaponWeight Weight of the weapon
 * @param attackBonus Attack bonus provided by weapon
 */
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
    return 0; // Weapons don't provide defence
}

int Weapon::getHealthMod() const {
    return 0; // Weapons don't affect health
}

int Weapon::getStrengthMod() const {
    return 0; // Weapons don't affect strength
}

std::string Weapon::getDescription() const {
    // Build descriptive string showing weapon stats
    return name + " [Weapon] - Attack: +" + std::to_string(attackMod) +
           ", Weight: " + std::to_string(weight);
}
