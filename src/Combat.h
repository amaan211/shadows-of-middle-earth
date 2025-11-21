/**
 * @file Combat.h
 * @brief Combat system implementation
 */

#ifndef COMBAT_H
#define COMBAT_H

#include <memory>
#include "Character.h"
#include <random>

/**
 * @class Combat
 * @brief Handles all combat logic between characters
 *
 * Manages attack/defense cycles, probability calculations,
 * damage application, and special race abilities.
 */
class Combat {
private:
    std::random_device rd;
    std::mt19937 gen;

public:
    /**
     * @brief Constructor for Combat system
     */
    Combat();

    /**
     * @brief Execute a combat round between attacker and defender
     * @param attacker The character initiating the attack
     * @param defender The character being attacked
     * @param isDaytime Current time of day for race abilities
     * @return std::pair<bool, int> (combat completed, gold earned if enemy defeated)
     *
     * Pseudo-code:
     * 1. Check if attacker's attack succeeds based on attack chance
     * 2. If attack fails, return immediately
     * 3. If attack succeeds, check if defender's defence succeeds
     * 4. Apply damage based on defence success/failure
     * 5. Check if defender is defeated and award gold
     * 6. Return combat result
     */
    std::pair<bool, int> executeCombatRound(std::shared_ptr<Character> attacker,
                                            std::shared_ptr<Character> defender,
                                            bool isDaytime);

    /**
     * @brief Check if a probability-based action succeeds
     * @param probability Success probability (0.0 to 1.0)
     * @return bool True if action succeeds
     */
    bool checkSuccess(double probability);

    /**
     * @brief Calculate damage when defence fails
     * @param attackerAttack Attacker's total attack value
     * @param defenderDefence Defender's total defence value
     * @return int Damage to apply to defender
     */
    int calculateDamage(int attackerAttack, int defenderDefence);
};

#endif // COMBAT_H
