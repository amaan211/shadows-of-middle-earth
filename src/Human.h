/**
 * @file Human.h
 * @brief Human race character implementation
 */

#ifndef HUMAN_H
#define HUMAN_H

#include "Character.h"

/**
 * @class Human
 * @brief Concrete class representing Human characters
 *
 * Humans have balanced stats and special ability:
 * Successful defences never cause damage.
 */
class Human : public Character {
public:
    /**
     * @brief Constructor for Human character
     * @param charName Name of the human character
     */
    Human(std::string charName);

    double getAttackChance(bool isDaytime) const override;
    double getDefenceChance(bool isDaytime) const override;
    int processSuccessfulDefence(int damage, int attackerAttack, bool isDaytime) const override;
    std::string getRace() const override;
};

#endif // HUMAN_H
