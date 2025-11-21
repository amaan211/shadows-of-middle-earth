/**
 * @file Dwarf.h
 * @brief Dwarf race character implementation
 */

#ifndef DWARF_H
#define DWARF_H

#include "Character.h"

/**
 * @class Dwarf
 * @brief Concrete class representing Dwarf characters
 *
 * Dwarfs have good defence and high strength with special ability:
 * Successful defences never cause damage.
 */
class Dwarf : public Character {
public:
    /**
     * @brief Constructor for Dwarf character
     * @param charName Name of the dwarf character
     */
    Dwarf(std::string charName);

    double getAttackChance(bool isDaytime) const override;
    double getDefenceChance(bool isDaytime) const override;
    int processSuccessfulDefence(int damage, int attackerAttack, bool isDaytime) const override;
    std::string getRace() const override;
};

#endif // DWARF_H
