/**
 * @file Shield.h
 * @brief Shield item class implementation
 */

#ifndef SHIELD_H
#define SHIELD_H

#include "Item.h"

/**
 * @class Shield
 * @brief Concrete class representing shield items
 *
 * Shields primarily modify defence stats, may penalize attack.
 * Inherits from abstract Item class.
 */
class Shield : public Item {
private:
    std::string name;
    int weight;
    int defenceMod;
    int attackMod;

public:
    /**
     * @brief Constructor for Shield
     * @param shieldName Name of the shield
     * @param shieldWeight Weight of the shield
     * @param defenceBonus Defence bonus provided
     * @param attackPenalty Attack penalty (default 0)
     */
    Shield(std::string shieldName, int shieldWeight, int defenceBonus, int attackPenalty = 0);

    std::string getName() const override;
    std::string getCategory() const override;
    int getWeight() const override;
    int getAttackMod() const override;
    int getDefenceMod() const override;
    int getHealthMod() const override;
    int getStrengthMod() const override;
    std::string getDescription() const override;
};

#endif // SHIELD_H
