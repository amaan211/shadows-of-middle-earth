#ifndef CHARACTER_H
#define CHARACTER_H

#include "Race.h"
#include <string>
#include <vector>
#include <memory>
#include <random>
#include <algorithm>
#include <iostream>

//Minimal Item struct for stat modifiers which will expand

struct Item{
    std::string name;
    int attackMod = 0;
    int defenceMod = 0;
    int healthMod = 0;
    int strengthMod = 0;
    int weight = 0;
};

class Character{
protected:
    std::string name;
    Race race;
    TimeOfDay tod;
    RaceProperties baseProps;

    int health;         //dynamically changing stats
    int strength;       //dynamically changing stats

    std::vector<Item> inventory;

    std::mt19937 rng;

public:
    Character(const std::string& n, Race r, TimeOfDay t = TimeOfDay::Day): name(n), race(r), tod(t){
        baseProps = getRaceProperties(r, t);
        health = baseProps.baseHealth;
        strength = baseProps.baseStrength;
        std::random_device rd;
        rng.seed(rd());
    }

    virtual ~Character() = default;
    std::string getName() const {return name;}
    Race getRace() const {return race;}
    int getHealth() const {return health;}
    bool isAlive() const {return health > 0;}

    virtual int getAttackValue() const {
        int total = baseProps.baseAttack;
        for (auto &it : inventory) total += it.attackMod;
        return total;
    }
    virtual int getDefenceValue() const {
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

    void takeDamage(int damage){
        if(damage <= 0){
            return;
        }
        health -= damage;
        if(health < 0){
            health = 0;
        }
    }
    void addItem(const Item &it){
        inventory.push_back(it);        // should apply the health/strength modifications
        health += it.healthMod;
        strength += it.strengthMod;
    }

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
