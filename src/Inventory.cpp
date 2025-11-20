/**
 * @file Inventory.cpp
 * @brief Implementation of Inventory class
 */

#include "Inventory.h"
#include <algorithm> // for std::find_if

/**
 * @brief Constructs an Inventory with specified capacity
 * @param maxCapacity Maximum weight the inventory can hold
 */
Inventory::Inventory(int maxCapacity)
    : currentWeight(0), maxWeight(maxCapacity) {
    // Initialize with zero weight and set maximum capacity
}

/**
 * @brief Attempts to add an item to the inventory
 * @param item Shared pointer to the item to add
 * @return bool True if item was successfully added
 *
 * Pseudo-code:
 * 1. Check if item weight would exceed max capacity
 * 2. Check if category is already full (except rings)
 * 3. If both checks pass, add item to vector
 * 4. Update current weight
 * 5. Return success status
 */
bool Inventory::addItem(std::shared_ptr<Item> item) {
    // Check for null pointer first - safety check
    if (!item) {
        return false;
    }

    // Check if adding this item would exceed our weight capacity
    if (currentWeight + item->getWeight() > maxWeight) {
        return false; // Too heavy to carry
    }

    // Check category restrictions: only one of each category except rings
    // Rings can be carried in unlimited quantities
    if (item->getCategory() != "Ring" && isCategoryFull(item->getCategory())) {
        return false; // Already have an item of this category
    }

    // All checks passed - add the item to our inventory vector
    items.push_back(item);
    // Update the current weight total
    currentWeight += item->getWeight();
    return true; // Successfully added
}

/**
 * @brief Removes an item from inventory by name
 * @param itemName Name of the item to remove
 * @return bool True if item was found and removed
 *
 * Pseudo-code:
 * 1. Iterate through items vector
 * 2. Find item with matching name
 * 3. If found, remove from vector and update weight
 * 4. Return true if removed, false if not found
 */
bool Inventory::removeItem(const std::string& itemName) {
    // Use STL algorithm to find the item by name
    auto it = std::find_if(items.begin(), items.end(),
                           [&itemName](const std::shared_ptr<Item>& item) {
                               return item->getName() == itemName; // Lambda comparison
                           });

    // Check if we found the item
    if (it != items.end()) {
        // Item found - subtract its weight from current total
        currentWeight -= (*it)->getWeight();
        // Remove from vector using iterator
        items.erase(it);
        return true; // Successfully removed
    }
    return false; // Item not found
}

/**
 * @brief Removes an item by its index position in the inventory
 * @param index Position of item to remove (0-based)
 * @return bool True if index was valid and item removed
 */
bool Inventory::removeItem(int index) {
    // Validate index range to prevent out-of-bounds access
    if (index < 0 || index >= static_cast<int>(items.size())) {
        return false; // Invalid index
    }

    // Subtract the item's weight before removing it
    currentWeight -= items[index]->getWeight();
    // Remove item at the specified index
    items.erase(items.begin() + index);
    return true;
}

int Inventory::getTotalWeight() const {
    return currentWeight;
}

int Inventory::getRemainingCapacity() const {
    return maxWeight - currentWeight;
}

bool Inventory::canCarry(int additionalWeight) const {
    // Simple check: current + additional must be <= max capacity
    return currentWeight + additionalWeight <= maxWeight;
}

const std::vector<std::shared_ptr<Item>>& Inventory::getItems() const {
    return items;
}

std::shared_ptr<Item> Inventory::getItem(int index) const {
    // Bounds checking to prevent crashes
    if (index < 0 || index >= static_cast<int>(items.size())) {
        return nullptr; // Invalid index returns null
    }
    return items[index]; // Return shared pointer to item
}

int Inventory::getItemCount() const {
    return items.size();
}

/**
 * @brief Calculates the total stat modifications from all equipped items
 * @return ItemStats structure with summed modifications
 */
Inventory::ItemStats Inventory::getTotalModifications() const {
    ItemStats stats = {0, 0, 0, 0}; // Initialize all stats to zero

    // Iterate through all items and sum their modifications
    for (const auto& item : items) {
        stats.attack += item->getAttackMod();
        stats.defence += item->getDefenceMod();
        stats.health += item->getHealthMod();
        stats.strength += item->getStrengthMod();
    }

    return stats;
}

/**
 * @brief Checks if a specific item category is already at capacity
 * @param category The item category to check
 * @return bool True if category is full (cannot add more)
 */
bool Inventory::isCategoryFull(const std::string& category) const {
    // Rings have no limit - can carry unlimited rings
    if (category == "Ring") {
        return false;
    }

    // For non-ring categories, check if we already have one
    for (const auto& item : items) {
        if (item->getCategory() == category) {
            return true; // Found one - category is full
        }
    }
    return false; // No items of this category found
}

/**
 * @brief Generates a formatted string showing inventory contents
 * @return std::string Formatted inventory summary
 */
std::string Inventory::getInventorySummary() const {
    std::string summary = "Inventory (" + std::to_string(currentWeight) +
                          "/" + std::to_string(maxWeight) + " weight):\n";

    // Check if inventory is empty
    if (items.empty()) {
        summary += "  Empty\n";
    } else {
        // List all items with their descriptions
        for (size_t i = 0; i < items.size(); ++i) {
            summary += "  " + std::to_string(i + 1) + ". " +
                       items[i]->getDescription() + "\n";
        }
    }

    // Add total stat modifications
    auto mods = getTotalModifications();
    summary += "Total Modifications: ";
    summary += "Attack: " + std::to_string(mods.attack) + ", ";
    summary += "Defence: " + std::to_string(mods.defence) + ", ";
    summary += "Health: " + std::to_string(mods.health) + ", ";
    summary += "Strength: " + std::to_string(mods.strength);

    return summary;
}

/**
 * @brief Clears all items from the inventory
 */
void Inventory::clear() {
    items.clear();      // Remove all items from vector
    currentWeight = 0;  // Reset weight counter
}
