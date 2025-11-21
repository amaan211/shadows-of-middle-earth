/**
 * @file Character.h
 * @brief Abstract base class for all game characters
 */

#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <memory>
#include "Inventory.h"

/**
 * @class Character
 * @brief Abstract base class representing any character in the game
 *
 * Defines the interface for all character types including players and enemies.
 * Uses polymorphism to handle different races through common interface.
 */
class Character {
protected:
    std::string name;
    int attack;
    int defence;
    int health;
    int strength;
    double attackChance;
    double defenceChance;
    Inventory inventory;

public:
    /**
     * @brief Virtual destructor for proper polymorphism
     */
    virtual ~Character() = default;

    /**
     * @brief Constructor for Character
     * @param charName Character name
     * @param baseAttack Base attack value
     * @param baseDefence Base defence value
     * @param baseHealth Base health value
     * @param baseStrength Base strength value
     */
    Character(std::string charName, int baseAttack, int baseDefence,
              int baseHealth, int baseStrength);

    /**
     * @brief Get character's current attack value
     * @return int Total attack including item modifications
     */
    virtual int getAttack() const;

    /**
     * @brief Get character's current defence value
     * @return int Total defence including item modifications
     */
    virtual int getDefence() const;

    /**
     * @brief Get character's current health
     * @return int Current health points
     */
    virtual int getHealth() const;

    /**
     * @brief Get character's strength (carrying capacity)
     * @return int Strength value
     */
    virtual int getStrength() const;

    /**
     * @brief Get attack success probability
     * @param isDaytime Current time of day
     * @return double Attack chance (0.0 to 1.0)
     */
    virtual double getAttackChance(bool isDaytime) const = 0;

    /**
     * @brief Get defence success probability
     * @param isDaytime Current time of day
     * @return double Defence chance (0.0 to 1.0)
     */
    virtual double getDefenceChance(bool isDaytime) const = 0;

    /**
     * @brief Process successful defence against an attack
     * @param damage The potential damage from the attack
     * @param attackerAttack The attacker's attack value
     * @param isDaytime Current time of day
     * @return int Actual damage taken after defence
     */
    virtual int processSuccessfulDefence(int damage, int attackerAttack, bool isDaytime) const = 0;

    /**
     * @brief Take damage from an attack
     * @param damage Amount of damage to take
     */
    virtual void takeDamage(int damage);

    /**
     * @brief Check if character is defeated
     * @return bool True if health <= 0
     */
    virtual bool isDefeated() const;

    /**
     * @brief Get character's name
     * @return std::string Character name
     */
    virtual std::string getName() const;

    /**
     * @brief Get character's race
     * @return std::string Race name
     */
    virtual std::string getRace() const = 0;

    /**
     * @brief Get gold value when defeated
     * @return int Gold awarded to victor
     */
    virtual int getGoldValue() const;

    /**
     * @brief Get character's inventory
     * @return Reference to inventory object
     */
    virtual Inventory& getInventory();
};

#endif // CHARACTER_H
