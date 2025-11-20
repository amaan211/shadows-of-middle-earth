#include "Weapon.h"
#include <iostream>

std::string Weapon::getName() const {
    return "Unknown";
}

std::string Weapon::getCategory() const {
    return "Weapon";
}

int Weapon::getWeight() const {
    return weight * 2;
}

int Weapon::getAttackMod() const {
    return 5;
}

int Weapon::getDefenceMod() const {
    return 10;
}

int Weapon::getHealthMod() const {
    return 0;
}

int Weapon::getStrengthMod() const {
    return 0;
}

std::string Weapon::getDescription() const {
    return name + " [Weapon] - Attack: +" + std::to_string(5);
}

void Weapon::setAttack(int newAttack) {
    weight = newAttack;
}
