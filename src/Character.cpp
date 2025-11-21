/**
 * @file Character.cpp
 * @brief Implementation of Character base class
 */

#include "Character.h"

Character::Character(std::string charName, int baseAttack, int baseDefence,
                     int baseHealth, int baseStrength)
    : name(charName), attack(baseAttack), defence(baseDefence),
    health(baseHealth), strength(baseStrength), inventory(baseStrength) {
    // Initialize with provided stats and inventory with strength capacity
}

int Character::getAttack() const {
    // Calculate total attack including item modifications
    auto mods = inventory.getTotalModifications();
    return attack + mods.attack;
}

int Character::getDefence() const {
    // Calculate total defence including item modifications
    auto mods = inventory.getTotalModifications();
    return defence + mods.defence;
}

int Character::getHealth() const {
    // Calculate total health including item modifications
    auto mods = inventory.getTotalModifications();
    return health + mods.health;
}

int Character::getStrength() const {
    // Calculate total strength including item modifications
    auto mods = inventory.getTotalModifications();
    return strength + mods.strength;
}

void Character::takeDamage(int damage) {
    if (damage < 0) {
        health += abs(damage); // Increase health for negative damage
    } else {
        health -= damage;
        if (health < 0) health = 0;
    }
}

bool Character::isDefeated() const {
    return health <= 0;
}

std::string Character::getName() const {
    return name;
}

int Character::getGoldValue() const {
    // Gold value is based on defence value including items
    return getDefence();
}

Inventory& Character::getInventory() {
    return inventory;
}
