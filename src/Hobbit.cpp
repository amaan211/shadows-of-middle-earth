/**
 * @file Hobbit.cpp
 * @brief Implementation of Hobbit class
 */


#include "Hobbit.h"

Hobbit::Hobbit(std::string charName)
    : Character(charName, 25, 20, 70, 85) {
    // Base stats passed to Character constructor
}


double Hobbit::getAttackChance(bool isDaytime) const {
    // Hobbits have 1/3 attack chance
    return 1.0 / 3.0;
}

double Hobbit::getDefenceChance(bool isDaytime) const {
    // Hobbits have 2/3 defence chance
    return 2.0 / 3.0;
}

int Hobbit::processSuccessfulDefence(int damage, int attackerAttack, bool isDaytime) const {
    // Hobbit special ability: Successful defences cause 0-5 random damage
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<> dis(0, 5);

    return dis(gen); // Random damage between 0-5
}

std::string Hobbit::getRace() const {
    return "Hobbit";
}
