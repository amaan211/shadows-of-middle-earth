#ifndef ITEMFACTORY_H
#define ITEMFACTORY_H

#include <memory>
#include "Weapon.h"
#include <vector>

class ItemFactory {
public:
    static std::shared_ptr<Item> createSword();
    static std::shared_ptr<Item> createDagger();
    static std::shared_ptr<Item> createPlateArmour();
    static std::shared_ptr<Item> createLeatherArmour();
    static std::shared_ptr<Item> createLargeShield();
    static std::shared_ptr<Item> createSmallShield();
    static std::shared_ptr<Item> createRingOfLife();
    static std::shared_ptr<Item> createRingOfStrength();

    static std::vector<std::shared_ptr<Item>> getAllItemTypes();
    static std::shared_ptr<Item> createRandomItem();
};

#endif
