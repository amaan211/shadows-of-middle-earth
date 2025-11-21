/**
 * @file Orc.cpp
 * @brief Implementation of Orc class
 */

#include "Orc.h"

Orc::Orc(std::string charName)
    : Character(charName, 25, 10, 50, 130),
    dayAttack(25), dayDefence(10), nightAttack(45), nightDefence(25) {
    // Base stats passed to Character constructor (using daytime stats as default)
}

int Orc::getAttack() const {
    // Orc attack depends on time of day, handled by combat system
    // Return base value, combat will adjust based on time
    return attack;
}

int Orc::getDefence() const {
    // Orc defence depends on time of day, handled by combat system
    // Return base value, combat will adjust based on time
    return defence;
}

double Orc::getAttackChance(bool isDaytime) const {
    if (isDaytime) {
        return 1.0 / 4.0; // Poor attack chance during day
    } else {
        return 1.0; // Perfect attack chance at night
    }
}

double Orc::getDefenceChance(bool isDaytime) const {
    if (isDaytime) {
        return 1.0 / 4.0; // Poor defence chance during day
    } else {
        return 1.0 / 2.0; // Good defence chance at night
    }
}

int Orc::processSuccessfulDefence(int damage, int attackerAttack, bool isDaytime) const {
    if (isDaytime) {
        // Daytime: defences cause 1/4 of adjusted damage
        int adjustedDamage = (attackerAttack - getDefence()) / 4;
        return adjustedDamage > 0 ? adjustedDamage : 0;
    } else {
        // Nighttime: defences increase health by 1
        return -1; // Negative damage means health increase
    }
}

std::string Orc::getRace() const {
    return "Orc";
}
