/**
 * @file Inventory.h
 * @brief Inventory management system using dynamic data structures
 */

#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>
#include <memory>
#include <string>
#include "Item.h"

/**
 * @class Inventory
 * @brief Manages character's items using STL dynamic containers
 *
 * Uses std::vector for unbounded item storage as required by the project.
 * Implements weight constraints and category restrictions.
 */
class Inventory {
private:
    std::vector<std::shared_ptr<Item>> items;
    int currentWeight;
    int maxWeight;

public:
    /**
     * @brief Constructor
     * @param maxCapacity Maximum weight capacity
     */
    explicit Inventory(int maxCapacity);

    /**
     * @brief Attempt to add an item to inventory
     * @param item Shared pointer to the item
     * @return bool True if item was added successfully
     *
     * Pseudo-code:
     * 1. Check if adding item would exceed weight limit
     * 2. Check category restrictions (only one per category except rings)
     * 3. If checks pass, add item and update current weight
     * 4. Return success status
     */
    bool addItem(std::shared_ptr<Item> item);

    /**
     * @brief Remove an item from inventory by name
     * @param itemName Name of item to remove
     * @return bool True if item was removed
     *
     * Pseudo-code:
     * 1. Find item by name in items vector
     * 2. If found, remove it and update current weight
     * 3. Return true if removed, false if not found
     */
    bool removeItem(const std::string& itemName);

    /**
     * @brief Remove an item from inventory by index
     * @param index Position in inventory
     * @return bool True if item was removed
     */
    bool removeItem(int index);

    /**
     * @brief Get total weight of all items
     * @return int Current inventory weight
     */
    int getTotalWeight() const;

    /**
     * @brief Get remaining weight capacity
     * @return int Available weight capacity
     */
    int getRemainingCapacity() const;

    /**
     * @brief Check if character can carry more items of a given weight
     * @param additionalWeight Weight to check
     * @return bool True if weight can be carried
     */
    bool canCarry(int additionalWeight) const;

    /**
     * @brief Get all items in inventory
     * @return const std::vector<std::shared_ptr<Item>>& Reference to items vector
     */
    const std::vector<std::shared_ptr<Item>>& getItems() const;

    /**
     * @brief Get item by index
     * @param index Position in inventory
     * @return std::shared_ptr<Item> Pointer to item or nullptr
     */
    std::shared_ptr<Item> getItem(int index) const;

    /**
     * @brief Get number of items in inventory
     * @return int Number of items
     */
    int getItemCount() const;

    /**
     * @brief Calculate total stat modifications from all items
     * @return struct containing total modifications
     */
    struct ItemStats {
        int attack;
        int defence;
        int health;
        int strength;
    };
    ItemStats getTotalModifications() const;

    /**
     * @brief Check if category limit is reached (for non-ring items)
     * @param category Item category to check
     * @return bool True if category is at capacity
     */
    bool isCategoryFull(const std::string& category) const;

    /**
     * @brief Get inventory summary for display
     * @return std::string Formatted inventory summary
     */
    std::string getInventorySummary() const;

    /**
     * @brief Clear all items from inventory
     */
    void clear();
};

#endif // INVENTORY_H
