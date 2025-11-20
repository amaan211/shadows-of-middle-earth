/**
 * @file ItemFactory.h
 * @brief Factory class for creating game items
 */

#ifndef ITEMFACTORY_H
#define ITEMFACTORY_H

#include <memory>
#include <vector>
#include "Weapon.h"
#include "Armour.h"
#include "Shield.h"
#include "Ring.h"

/**
 * @class ItemFactory
 * @brief Creates predefined game items using factory pattern
 *
 * Provides static methods to create all required items from the specification.
 * This centralizes item creation and makes it easy to extend.
 */
class ItemFactory {
public:
    // Weapon creations
    static std::shared_ptr<Item> createSword();
    static std::shared_ptr<Item> createDagger();

    // Armour creations
    static std::shared_ptr<Item> createPlateArmour();
    static std::shared_ptr<Item> createLeatherArmour();

    // Shield creations
    static std::shared_ptr<Item> createLargeShield();
    static std::shared_ptr<Item> createSmallShield();

    // Ring creations
    static std::shared_ptr<Item> createRingOfLife();
    static std::shared_ptr<Item> createRingOfStrength();

    /**
     * @brief Get all available item types
     * @return Vector of all creatable items
     */
    static std::vector<std::shared_ptr<Item>> getAllItemTypes();

    /**
     * @brief Create a random item for board initialization
     * @return std::shared_ptr<Item> Randomly selected item
     */
    static std::shared_ptr<Item> createRandomItem();
};

#endif // ITEMFACTORY_H
