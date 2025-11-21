/**
 * @file Hobbit.h
 * @brief Hobbit race character implementation
 */

#ifndef HOBBIT_H
#define HOBBIT_H

#include "Character.h"
#include <random>

/**
 * @class Hobbit
 * @brief Concrete class representing Hobbit characters
 *
 * Hobbits have high health but low attack with special ability:
 * Successful defences cause 0-5 damage regardless of attack value.
 */
class Hobbit : public Character {
public:
    /**
     * @brief Constructor for Hobbit character
     * @param charName Name of the hobbit character
     */
    Hobbit(std::string charName);

    double getAttackChance(bool isDaytime) const override;
    double getDefenceChance(bool isDaytime) const override;
    int processSuccessfulDefence(int damage, int attackerAttack, bool isDaytime) const override;
    std::string getRace() const override;
};

#endif // HOBBIT_H
