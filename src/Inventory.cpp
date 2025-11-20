#include "Inventory.h"
#include <algorithm>

Inventory::Inventory(int maxCapacity)
    : currentWeight(0), maxWeight(maxCapacity) {}

bool Inventory::addItem(std::shared_ptr<Item> item) {
    if (!item) {
        return false;
    }

    if (currentWeight + item->getWeight() > maxWeight) {
        return false;
    }

    if (item->getCategory() != "Ring" && isCategoryFull(item->getCategory())) {
        return false;
    }

    items.push_back(item);
    currentWeight += item->getWeight();
    return true;
}

bool Inventory::removeItem(const std::string& itemName) {
    auto it = std::find_if(items.begin(), items.end(),
                           [&itemName](const std::shared_ptr<Item>& item) {
                               return item->getName() == itemName;
                           });

    if (it != items.end()) {
        currentWeight -= (*it)->getWeight();
        items.erase(it);
        return true;
    }
    return false;
}

bool Inventory::removeItem(int index) {
    if (index < 0 || index >= static_cast<int>(items.size())) {
        return false;
    }

    currentWeight -= items[index]->getWeight();
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
    return currentWeight + additionalWeight <= maxWeight;
}

const std::vector<std::shared_ptr<Item>>& Inventory::getItems() const {
    return items;
}

std::shared_ptr<Item> Inventory::getItem(int index) const {
    if (index < 0 || index >= static_cast<int>(items.size())) {
        return nullptr;
    }
    return items[index];
}

int Inventory::getItemCount() const {
    return items.size();
}

Inventory::ItemStats Inventory::getTotalModifications() const {
    ItemStats stats = {0, 0, 0, 0};

    for (const auto& item : items) {
        stats.attack += item->getAttackMod();
        stats.defence += item->getDefenceMod();
        stats.health += item->getHealthMod();
        stats.strength += item->getStrengthMod();
    }

    return stats;
}

bool Inventory::isCategoryFull(const std::string& category) const {
    if (category == "Ring") {
        return false;
    }

    for (const auto& item : items) {
        if (item->getCategory() == category) {
            return true;
        }
    }
    return false;
}

std::string Inventory::getInventorySummary() const {
    std::string summary = "Inventory (" + std::to_string(currentWeight) + "/" + std::to_string(maxWeight) + " weight):\n";

    if (items.empty()) {
        summary += "  Empty\n";
    } else {
        for (size_t i = 0; i < items.size(); ++i) {
            summary += "  " + std::to_string(i + 1) + ". " + items[i]->getDescription() + "\n";
        }
    }

    auto mods = getTotalModifications();
    summary += "Total Modifications: ";
    summary += "Attack: " + std::to_string(mods.attack) + ", ";
    summary += "Defence: " + std::to_string(mods.defence) + ", ";
    summary += "Health: " + std::to_string(mods.health) + ", ";
    summary += "Strength: " + std::to_string(mods.strength);

    return summary;
}

void Inventory::clear() {
    items.clear();
    currentWeight = 0;
}
