/**
 * @file Item.h
 * @brief Abstract base class for all game items
 */

#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <memory>

/**
 * @class Item
 * @brief Abstract base class representing any item in the game
 *
 * This class defines the interface for all items. It uses polymorphism
 * to handle different item types through a common interface.
 */
class Item {
public:
    /**
     * @brief Virtual destructor for proper polymorphism
     */
    virtual ~Item() = default;

    /**
     * @brief Get the item's name
     * @return std::string The name of the item
     */
    virtual std::string getName() const = 0;

    /**
     * @brief Get the item's category
     * @return std::string The category (Weapon, Armour, Shield, Ring)
     */
    virtual std::string getCategory() const = 0;

    /**
     * @brief Get the item's weight
     * @return int The weight of the item
     */
    virtual int getWeight() const = 0;

    /**
     * @brief Get attack modification
     * @return int Attack bonus/penalty
     */
    virtual int getAttackMod() const = 0;

    /**
     * @brief Get defence modification
     * @return int Defence bonus/penalty
     */
    virtual int getDefenceMod() const = 0;

    /**
     * @brief Get health modification
     * @return int Health bonus/penalty
     */
    virtual int getHealthMod() const = 0;

    /**
     * @brief Get strength modification
     * @return int Strength bonus/penalty
     */
    virtual int getStrengthMod() const = 0;

    /**
     * @brief Get item description for UI
     * @return std::string Formatted description
     */
    virtual std::string getDescription() const = 0;
};

#endif // ITEM_H
