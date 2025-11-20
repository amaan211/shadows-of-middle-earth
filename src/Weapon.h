/**
 * @file Weapon.h
 * @brief Weapon item class implementation
 */

#ifndef WEAPON_H
#define WEAPON_H

#include "Item.h"

/**
 * @class Weapon
 * @brief Concrete class representing weapon items
 *
 * Weapons primarily modify attack stats with various weights.
 * Inherits from abstract Item class.
 */
class Weapon : public Item {
private:
    std::string name;
    int weight;
    int attackMod;

public:
    /**
     * @brief Constructor for Weapon
     * @param weaponName Name of the weapon
     * @param weaponWeight Weight of the weapon
     * @param attackBonus Attack bonus provided
     */
    Weapon(std::string weaponName, int weaponWeight, int attackBonus);

    // Item interface implementation
    std::string getName() const override;
    std::string getCategory() const override;
    int getWeight() const override;
    int getAttackMod() const override;
    int getDefenceMod() const override;
    int getHealthMod() const override;
    int getStrengthMod() const override;
    std::string getDescription() const override;
};

#endif // WEAPON_H
