/**
 * @file Orc.h
 * @brief Orc race character implementation
 */

#ifndef ORC_H
#define ORC_H

#include "Character.h"

/**
 * @class Orc
 * @brief Concrete class representing Orc characters
 *
 * Orcs have day/night dependent stats with special abilities:
 * - Day: Poor stats, defences cause 1/4 adjusted damage
 * - Night: Excellent stats, defences increase health by 1
 */
class Orc : public Character {
private:
    int dayAttack;
    int dayDefence;
    int nightAttack;
    int nightDefence;

public:
    /**
     * @brief Constructor for Orc character
     * @param charName Name of the orc character
     */
    Orc(std::string charName);

    int getAttack() const override;
    int getDefence() const override;
    double getAttackChance(bool isDaytime) const override;
    double getDefenceChance(bool isDaytime) const override;
    int processSuccessfulDefence(int damage, int attackerAttack, bool isDaytime) const override;
    std::string getRace() const override;
};

#endif // ORC_H
