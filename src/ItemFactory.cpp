#include "ItemFactory.h"
#include <random>

std::shared_ptr<Item> ItemFactory::createSword() {
    return std::make_shared<Weapon>("Sword", 10, 10);
}

std::shared_ptr<Item> ItemFactory::createDagger() {
    return std::make_shared<Weapon>("Dagger", 5, 5);
}

std::shared_ptr<Item> ItemFactory::createPlateArmour() {
    return std::make_shared<Armour>("Plate Armour", 40, 10, -5);
}

std::shared_ptr<Item> ItemFactory::createLeatherArmour() {
    return std::make_shared<Armour>("Leather Armour", 20, 5);
}

std::shared_ptr<Item> ItemFactory::createLargeShield() {
    return std::make_shared<Shield>("Large Shield", 30, 10, -5);
}

std::shared_ptr<Item> ItemFactory::createSmallShield() {
    return std::make_shared<Shield>("Small Shield", 10, 5);
}

std::shared_ptr<Item> ItemFactory::createRingOfLife() {
    return std::make_shared<Ring>("Ring of Life", 1, 10, 0);
}

std::shared_ptr<Item> ItemFactory::createRingOfStrength() {
    return std::make_shared<Ring>("Ring of Strength", 1, -10, 50);
}

std::vector<std::shared_ptr<Item>> ItemFactory::getAllItemTypes() {
    return {
        createSword(),
        createDagger(),
        createPlateArmour(),
        createLeatherArmour(),
        createLargeShield(),
        createSmallShield(),
        createRingOfLife(),
        createRingOfStrength()
    };
}

std::shared_ptr<Item> ItemFactory::createRandomItem() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<> dis(0, 7);

    int choice = dis(gen);
    switch (choice) {
    case 0: return createSword();
    case 1: return createDagger();
    case 2: return createPlateArmour();
    case 3: return createLeatherArmour();
    case 4: return createLargeShield();
    case 5: return createSmallShield();
    case 6: return createRingOfLife();
    case 7: return createRingOfStrength();
    default: return createSword();
    }
}
