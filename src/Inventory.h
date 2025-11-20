#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>
#include <memory>
#include <string>
#include "Item.h"

class Inventory {
private:
    std::vector<std::shared_ptr<Item>> items;
    int currentWeight;

public:
    Inventory(int maxCapacity);

    bool addItem(std::shared_ptr<Item> item);
    bool removeItem(const std::string& itemName);
    bool removeItem(int index);
    int getTotalWeight() const;
    int getRemainingCapacity() const;
    bool canCarry(int additionalWeight) const;
    const std::vector<std::shared_ptr<Item>>& getItems() const;
    std::shared_ptr<Item> getItem(int index) const;
    int getItemCount() const;

    struct ItemStats {
        int attack;
        int defence;
        int health;
        int strength;
    };
    ItemStats getTotalModifications() const;

    bool isCategoryFull(const std::string& category) const;
    std::string getInventorySummary() const;
    void clear();
};

#endif
