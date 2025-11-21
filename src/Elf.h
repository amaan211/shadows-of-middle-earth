/**
 * @file Elf.h
 * @brief Elf race character implementation
 */

#ifndef ELF_H
#define ELF_H

#include "Character.h"

/**
 * @class Elf
 * @brief Concrete class representing Elf characters
 *
 * Elfs have high attack but low defence and special ability:
 * Successful defences always increase health by 1.
 */
class Elf : public Character {
public:
    /**
     * @brief Constructor for Elf character
     * @param charName Name of the elf character
     */
    Elf(std::string charName);

    double getAttackChance(bool isDaytime) const override;
    double getDefenceChance(bool isDaytime) const override;
    int processSuccessfulDefence(int damage, int attackerAttack, bool isDaytime) const override;
    std::string getRace() const override;
};

#endif // ELF_H
