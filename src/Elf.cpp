/**
 * @file Elf.cpp
 * @brief Implementation of Elf class
 */

#include "Elf.h"

Elf::Elf(std::string charName)
    : Character(charName, 40, 10, 40, 70) {
    // Base stats passed to Character constructor
}

double Elf::getAttackChance(bool isDaytime) const {
    // Elfs have 1/1 attack chance (always successful)
    return 1.0;
}

double Elf::getDefenceChance(bool isDaytime) const {
    // Elfs have 1/4 defence chance
    return 1.0 / 4.0;
}

int Elf::processSuccessfulDefence(int damage, int attackerAttack, bool isDaytime) const {
    // Elf special ability: Successful defences always increase health by 1
    // Note: This would require modifying health, but we return damage here
    // The combat system will handle the health increase
    return -1; // Negative damage means health increase
}

std::string Elf::getRace() const {
    return "Elf";
}
