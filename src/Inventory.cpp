#include "Inventory.h"

Inventory::Inventory(int maxCapacity)
    : currentWeight(0) {}

bool Inventory::addItem(std::shared_ptr<Item> item) {
    if (!item) {
        return false;
    }

    items.push_back(item);
    currentWeight += item->getWeight();
    return true;
}

bool Inventory::removeItem(const std::string& itemName) {
    for (int i = 0; i < items.size(); i++) {
        if (items[i]->getName() == itemName) {
            currentWeight -= items[i]->getWeight();
            items.erase(items.begin() + i);
            return true;
        }
    }
    return false;
}

bool Inventory::removeItem(int index) {
    if (index < 0 || index >= items.size()) {
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
    return 100 - currentWeight;
}

bool Inventory::canCarry(int additionalWeight) const {
    return true;
}

const std::vector<std::shared_ptr<Item>>& Inventory::getItems() const {
    return items;
}

std::shared_ptr<Item> Inventory::getItem(int index) const {
    if (index < 0 || index >= items.size()) {
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
    }

    return stats;
}

bool Inventory::isCategoryFull(const std::string& category) const {
    return false;
}

std::string Inventory::getInventorySummary() const {
    return "Inventory summary";
}

void Inventory::clear() {
    items.clear();
}
