/**
 * @file Combat.cpp
 * @brief Implementation of Combat system
 */

#include "Combat.h"

Combat::Combat() : gen(rd()) {
    // Initialize random number generator
}

std::pair<bool, int> Combat::executeCombatRound(std::shared_ptr<Character> attacker,
                                                std::shared_ptr<Character> defender,
                                                bool isDaytime) {
    int goldEarned = 0;

    // Step 1: Check if attacker's attack succeeds
    double attackProbability = attacker->getAttackChance(isDaytime);
    bool attackSucceeded = checkSuccess(attackProbability);

    if (!attackSucceeded) {
        // Attack failed - combat round ends
        return std::make_pair(false, 0);
    }

    // Step 2: Attack succeeded, now check defender's defence
    double defenceProbability = defender->getDefenceChance(isDaytime);
    bool defenceSucceeded = checkSuccess(defenceProbability);

    int damage = 0;

    if (!defenceSucceeded) {
        // Defence failed - apply full damage
        damage = calculateDamage(attacker->getAttack(), defender->getDefence());
        defender->takeDamage(damage);
    } else {
        // Defence succeeded - apply race-specific damage
        damage = defender->processSuccessfulDefence(
            calculateDamage(attacker->getAttack(), defender->getDefence()),
            attacker->getAttack(),
            isDaytime
            );

        if (damage < 0) {
            // Negative damage means health increase (Elf/Orc night ability)
            // Note: This would require modifying the character interface
            // For now, we'll handle this specially in the game logic
            defender->takeDamage(damage); // Negative damage increases health
        } else {
            defender->takeDamage(damage);
        }
    }

    // Step 3: Check if defender is defeated
    if (defender->isDefeated()) {
        // Award gold equal to defender's defence value including items
        goldEarned = defender->getGoldValue();
    }

    return std::make_pair(true, goldEarned);
}

bool Combat::checkSuccess(double probability) {
    // Generate random number between 0.0 and 1.0
    std::uniform_real_distribution<> dis(0.0, 1.0);
    double randomValue = dis(gen);

    // Check if random value is within success probability
    return randomValue <= probability;
}

int Combat::calculateDamage(int attackerAttack, int defenderDefence) {
    // Calculate damage as attack minus defence
    int damage = attackerAttack - defenderDefence;

    // Ensure minimum damage of 1 if attack exceeds defence
    if (damage < 1 && attackerAttack > defenderDefence) {
        damage = 1;
    }

    // If defence is higher than attack, no damage
    if (damage < 0) {
        damage = 0;
    }

    return damage;
}
