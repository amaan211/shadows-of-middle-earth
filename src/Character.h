#ifndef CHARACTER_H
#define CHARACTER_H

#include "Race.h"
#include <string>
#include <vector>
#include <memory>
#include <random>
#include <algorithm>
#include <iostream>

//Minimal Item struct for stat modifiers which will expand further on during the gameplay
//Every item in the game can modify a characters stats.
struct Item{
    std::string name;   //Name of Item
    int attackMod = 0;  //increae/decrease attack
    int defenceMod = 0; //defence modifier
    int healthMod = 0;
    int strengthMod = 0;    //When carrying items like swords can modify
    int weight = 0;
};
//This class represents any character in the game, it stores race, stats, items
//THis class will be inherited by specific races with special abilities.
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
    Character(const std::string& n, Race r, TimeOfDay t = TimeOfDay::Day): name(n), race(r), tod(t){
        baseProps = getRaceProperties(r, t);
        health = baseProps.baseHealth;      //set initial health and strength values
        strength = baseProps.baseStrength;
        std::random_device rd;      //This random generator will ensure randomness for different chances
        rng.seed(rd());
    }

    virtual ~Character() = default;
    std::string getName() const {return name;}
    Race getRace() const {return race;}
    int getHealth() const {return health;}
    bool isAlive() const {return health > 0;}   //Checks if the character is alive

    virtual int getAttackValue() const {    //calculates total attack value + any attack bonuses
        int total = baseProps.baseAttack;
        for (auto &it : inventory) total += it.attackMod;
        return total;
    }
    virtual int getDefenceValue() const {       //calculates total defence value + any defence bonuses
        int total = baseProps.baseDefence;
        for( auto &it : inventory) total += it.defenceMod;
        return total;
    }

    virtual std::pair<int,int> getAttackChance() const {
        return {baseProps.attackChanceNum, baseProps.attackChanceDen};
    }
    virtual std:: pair<int,int> getDefenceChance() const {
        return {baseProps.defenceChanceNum, baseProps.defenceChanceDen};
    }

    //this function must be called when the defender has successfully defended the opponents attack
    // return the damage to apply to defender
    virtual int onSuccessfulDefence(int attackerAdjustedAttack){
        return 0;       //by default successful defence causes no damage unless item ability provides
    }

    //Apply the damage to the character but the health cannot go below 0.
    void takeDamage(int damage){
        if(damage <= 0){
            return;
        }
        health -= damage;
        if(health < 0){
            health = 0;
        }
    }

    //An item picked up must be added to the inventory
    void addItem(const Item &it){
        inventory.push_back(it);        // should apply the health/strength modifications
        health += it.healthMod;
        strength += it.strengthMod;
    }

    //This function rolls a probability dice
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

    virtual void printStats() const {
        std::cout << name << " (" << baseProps.name << ") A:" << getAttackValue() << " D:" << getDefenceValue() << " H:" << health << " S:" << strength << "\n";
    }
};

#endif // CHARACTER_H
