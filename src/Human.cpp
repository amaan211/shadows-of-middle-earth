/**
 * @file Human.cpp
 * @brief Implementation of Human class
 */

#include "Human.h"

Human::Human(std::string charName)
    : Character(charName, 30, 20, 60, 100) {
    // Base stats passed to Character constructor
    // Inventory is automatically initialized with strength capacity
}

double Human::getAttackChance(bool isDaytime) const {
    // Humans have 2/3 attack chance (both day and night)
    return 2.0 / 3.0;
}

double Human::getDefenceChance(bool isDaytime) const {
    // Humans have 1/2 defence chance (both day and night)
    return 1.0 / 2.0;
}

int Human::processSuccessfulDefence(int damage, int attackerAttack, bool isDaytime) const {
    // Human special ability: Successful defences never cause damage
    return 0;
}

std::string Human::getRace() const {
    return "Human";
}
