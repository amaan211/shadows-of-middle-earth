/**
 * @file Ring.h
 * @brief Ring item class implementation
 */

#ifndef RING_H
#define RING_H

#include "Item.h"

/**
 * @class Ring
 * @brief Concrete class representing ring items
 *
 * Rings modify various stats and have special properties.
 * Multiple rings can be carried (unlimited by category).
 * Inherits from abstract Item class.
 */
class Ring : public Item {
private:
    std::string name;
    int weight;
    int healthMod;
    int strengthMod;

public:
    /**
     * @brief Constructor for Ring
     * @param ringName Name of the ring
     * @param ringWeight Weight of the ring
     * @param healthBonus Health modification
     * @param strengthBonus Strength modification
     */
    Ring(std::string ringName, int ringWeight, int healthBonus, int strengthBonus);

    std::string getName() const override;
    std::string getCategory() const override;
    int getWeight() const override;
    int getAttackMod() const override;
    int getDefenceMod() const override;
    int getHealthMod() const override;
    int getStrengthMod() const override;
    std::string getDescription() const override;
};

#endif // RING_H
