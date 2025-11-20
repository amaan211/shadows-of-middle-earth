/**
 * @file Armour.h
 * @brief Armour item class implementation
 */

#ifndef ARMOUR_H
#define ARMOUR_H

#include "Item.h"

/**
 * @class Armour
 * @brief Concrete class representing armour items
 *
 * Armour primarily modifies defence stats, may penalize attack.
 * Inherits from abstract Item class.
 */
class Armour : public Item {
private:
    std::string name;
    int weight;
    int defenceMod;
    int attackMod;

public:
    /**
     * @brief Constructor for Armour
     * @param armourName Name of the armour
     * @param armourWeight Weight of the armour
     * @param defenceBonus Defence bonus provided
     * @param attackPenalty Attack penalty (default 0)
     */
    Armour(std::string armourName, int armourWeight, int defenceBonus, int attackPenalty = 0);

    std::string getName() const override;
    std::string getCategory() const override;
    int getWeight() const override;
    int getAttackMod() const override;
    int getDefenceMod() const override;
    int getHealthMod() const override;
    int getStrengthMod() const override;
    std::string getDescription() const override;
};

#endif // ARMOUR_H
