/**
 * @file Character.h
 * @brief BAse character class representing all playable and enemy characters.
 */

#ifndef CHARACTER_H
#define CHARACTER_H

#include "Race.h"
#include <string>
#include <vector>
#include <memory>
#include <random>
#include <algorithm>
#include <iostream>
/**
 * @struct Item
 * @brief Represents an item in the game that can modify character stats.
 *
 * Items can affect attack, defence, health, strength and weight,
 * different items will use this structure during the gameplay.
 */

struct Item{
    std::string name;   //Name of Item
    int attackMod = 0;  //increae/decrease attack
    int defenceMod = 0; //defence modifier
    int healthMod = 0;
    int strengthMod = 0;    //When carrying items like swords can modify
    int weight = 0;
};

/**
 * @class Character
 * @brief Base class for all characters in the game including enemies
 *
 * This class stores shared data like race, stats, inventory and
 * behaviour such as attack/defence calculations.
 * Race-specific behaviour is implemented by overriding the onSuccessfulDefence()
 */

class Character{
protected:
    std::string name;       //Basic info
    Race race;
    TimeOfDay tod;
    RaceProperties baseProps;

    int health;         //dynamically changing stats
    int strength;

    std::vector<Item> inventory;    //holds all items of the character

    std::mt19937 rng;       //This is used for attack chances, damage, etc

public:         //When a character is initiated, we can load their base stats based on their race.
    /**
     * @brief Constructor for Character
     * @param n Name of the Character
     * @param r Race
     * @param t Current time of game(Day/Night)
     */

    Character(const std::string& n, Race r, TimeOfDay t = TimeOfDay::Day): name(n), race(r), tod(t){
        baseProps = getRaceProperties(r, t);
        health = baseProps.baseHealth;      //set initial health and strength values
        strength = baseProps.baseStrength;
        std::random_device rd;      //This random generator will ensure randomness for different chances
        rng.seed(rd());
    }

    /**
     * @brief ~Character - Virtual Destructor
     */
    virtual ~Character() = default;

    /**
     * @brief getName
     * @return Character's name
     */
    std::string getName() const {return name;}
    /**
     * @brief getRace
     * @return Character's race
     */
    Race getRace() const {return race;}
    /**
     * @brief getHealth
     * @return Current health value of the character
     */
    int getHealth() const {return health;}
    /**
     * @brief isAlive
     * @return True if characters health is above 0
     */
    bool isAlive() const {return health > 0;}   //Checks if the character is alive

    /**
     * @brief getAttackValue - computes total attack value
     * @return Base attack plus all item modifiers
     */
    virtual int getAttackValue() const {    //calculates total attack value + any attack bonuses
        int total = baseProps.baseAttack;
        for (auto &it : inventory) total += it.attackMod;
        return total;
    }
    /**
     * @brief getDefenceValue - computes total defence value
     * @return Base defence plus all modifiers
     */
    virtual int getDefenceValue() const {       //calculates total defence value + any defence bonuses
        int total = baseProps.baseDefence;
        for( auto &it : inventory) total += it.defenceMod;
        return total;
    }

    /**
     * @brief getAttackChance - Retrieves attack success probability
     * @return pair(numerator/denominator)
     */
    virtual std::pair<int,int> getAttackChance() const {
        return {baseProps.attackChanceNum, baseProps.attackChanceDen};
    }
    /**
     * @brief getDefenceChance - Retrieves defence success probability
     * @return pair(numerator/denominator)
     */
    virtual std:: pair<int,int> getDefenceChance() const {
        return {baseProps.defenceChanceNum, baseProps.defenceChanceDen};
    }

    /**
     * @brief called when a character successfully defends a attack
     *
     * Default is 0 damage, bt races override this method to implement special abilities
     *
     * @param attackerAdjustedAttack attack value after modifier
     * @return Damage applied to defender
     */

    virtual int onSuccessfulDefence(int attackerAdjustedAttack){
        return 0;       //by default successful defence causes no damage unless item ability provides
    }

    /**
     * @brief Applies damage to character
     * @param damage amount of health lost
     */
    void takeDamage(int damage){
        if(damage <= 0){
            return;
        }
        health -= damage;
        if(health < 0){
            health = 0;
        }
    }

    /**
     * @brief addItem - will add an item to the inventory and apply stat bonuses
     * @param it Item to add
     */
    void addItem(const Item &it){
        inventory.push_back(it);        // should apply the health/strength modifications
        health += it.healthMod;
        strength += it.strengthMod;
    }

    /**
     * @brief rollChance - Performs a probability roll
     * @param num Success numerator
     * @param den Denominator
     * @return True if roll succeeds
     */
    bool rollChance(int num, int den){
        if(num <=0) {
            return false;
        }
        if (num >= den){
            return true;
        }
        std::uniform_int_distribution<int> dist(1,den);
        int v = dist(rng);
        return v <= num;
    }

    /**
     * @brief printStats - prints character stats to console
     */
    virtual void printStats() const {
        std::cout << name << " (" << baseProps.name << ") A:" << getAttackValue() << " D:" << getDefenceValue() << " H:" << health << " S:" << strength << "\n";
    }
};

#endif // CHARACTER_H
