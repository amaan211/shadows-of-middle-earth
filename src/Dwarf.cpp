/**
 * @file Dwarf.cpp
 * @brief Implementation of Dwarf class
 */

#include "Dwarf.h"

Dwarf::Dwarf(std::string charName)
    : Character(charName, 30, 20, 50, 130) {
    // Base stats passed to Character constructor
}

double Dwarf::getAttackChance(bool isDaytime) const {
    // Dwarfs have 2/3 attack chance
    return 2.0 / 3.0;
}

double Dwarf::getDefenceChance(bool isDaytime) const {
    // Dwarfs have 2/3 defence chance
    return 2.0 / 3.0;
}

int Dwarf::processSuccessfulDefence(int damage, int attackerAttack, bool isDaytime) const {
    // Dwarf special ability: Successful defences never cause damage
    return 0;
}

std::string Dwarf::getRace() const {
    return "Dwarf";
}
