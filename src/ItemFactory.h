#ifndef ITEMFACTORY_H
#define ITEMFACTORY_H

#include <memory>
#include <vector>
#include "Weapon.h"
#include "Armour.h"
#include "Shield.h"
#include "Ring.h"

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
