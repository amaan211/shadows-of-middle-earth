#include "ItemFactory.h"

std::shared_ptr<Item> ItemFactory::createSword() {
    return std::make_shared<Weapon>("Sword", 10, 5);
}

std::shared_ptr<Item> ItemFactory::createDagger() {
    return std::make_shared<Weapon>("Dagger", 5, 3);
}

std::shared_ptr<Item> ItemFactory::createPlateArmour() {
    return nullptr;
}

std::shared_ptr<Item> ItemFactory::createLeatherArmour() {
    return nullptr;
}

std::shared_ptr<Item> ItemFactory::createLargeShield() {
    return nullptr;
}

std::shared_ptr<Item> ItemFactory::createSmallShield() {
    return nullptr;
}

std::shared_ptr<Item> ItemFactory::createRingOfLife() {
    return nullptr;
}

std::shared_ptr<Item> ItemFactory::createRingOfStrength() {
    return nullptr;
}

std::vector<std::shared_ptr<Item>> ItemFactory::getAllItemTypes() {
    return {createSword(), createDagger()};
}

std::shared_ptr<Item> ItemFactory::createRandomItem() {
    return createSword();
}
