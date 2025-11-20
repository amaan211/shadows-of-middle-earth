/**
 * @file ItemFactory.cpp
 * @brief Implementation of ItemFactory class
 */

#include "ItemFactory.h"
#include <random> // For random item generation

// Create specific weapon items according to project specification
std::shared_ptr<Item> ItemFactory::createSword() {
    // Sword: weight 10, attack +10
    return std::make_shared<Weapon>("Sword", 10, 10);
}

std::shared_ptr<Item> ItemFactory::createDagger() {
    // Dagger: weight 5, attack +5
    return std::make_shared<Weapon>("Dagger", 5, 5);
}

// Create armour items with defence bonuses and possible attack penalties
std::shared_ptr<Item> ItemFactory::createPlateArmour() {
    // Plate Armour: weight 40, defence +10, attack -5
    return std::make_shared<Armour>("Plate Armour", 40, 10, -5);
}

std::shared_ptr<Item> ItemFactory::createLeatherArmour() {
    // Leather Armour: weight 20, defence +5, no attack penalty
    return std::make_shared<Armour>("Leather Armour", 20, 5);
}

// Create shield items with defence bonuses and possible attack penalties
std::shared_ptr<Item> ItemFactory::createLargeShield() {
    // Large Shield: weight 30, defence +10, attack -5
    return std::make_shared<Shield>("Large Shield", 30, 10, -5);
}

std::shared_ptr<Item> ItemFactory::createSmallShield() {
    // Small Shield: weight 10, defence +5, no attack penalty
    return std::make_shared<Shield>("Small Shield", 10, 5);
}

// Create ring items with special stat modifications
std::shared_ptr<Item> ItemFactory::createRingOfLife() {
    // Ring of Life: weight 1, health +10
    return std::make_shared<Ring>("Ring of Life", 1, 10, 0);
}

std::shared_ptr<Item> ItemFactory::createRingOfStrength() {
    // Ring of Strength: weight 1, strength +50, health -10 (trade-off)
    return std::make_shared<Ring>("Ring of Strength", 1, -10, 50);
}

/**
 * @brief Returns all available item types for game initialization
 * @return Vector containing one of each item type
 */
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

/**
 * @brief Creates a random item for populating the game board
 * @return std::shared_ptr<Item> Randomly selected item
 */
std::shared_ptr<Item> ItemFactory::createRandomItem() {
    // Set up random number generation
    static std::random_device rd;  // True random seed
    static std::mt19937 gen(rd()); // Mersenne Twister generator
    static std::uniform_int_distribution<> dis(0, 7); // Range: 0-7 (8 items)

    int choice = dis(gen); // Generate random number 0-7

    // Map random number to specific item type
    switch (choice) {
    case 0: return createSword();
    case 1: return createDagger();
    case 2: return createPlateArmour();
    case 3: return createLeatherArmour();
    case 4: return createLargeShield();
    case 5: return createSmallShield();
    case 6: return createRingOfLife();
    case 7: return createRingOfStrength();
    default: return createSword(); // Fallback (should never happen)
    }
}
