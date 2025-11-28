/**
 * @file CharacterSpecials.cpp
 * @brief Implements race specific modifiers for characters with unique defence abilities
 */
#include "Character.h"

/**
 * @class ElfCharacter
 * @brief Elf gains +1 health on every successful defence
 */
//Human -> Successful defence never causes damage -> which is default
//ELf -> Successful defence always increases health by 1
class ElfCharacter : public Character{
public:
    /**
     * @brief ElfCharacter - constructor
     * @param n Elf's name
     * @param t current time in game (Day/Night)
     */
    ElfCharacter(const std::string &n, TimeOfDay t = TimeOfDay::Day): Character(n, Race::Elf, t) {}
    /**
     * @brief Successful defence give Elf +1 health
     * @return Always 0 damage taken
     */
    int onSuccessfulDefence(int attackerAdjustedAttack) override {
        health += 1;
        return 0;
    }
};

/**
 * @class DwarfCharacter
 * @brief Dwarfs take 0 damage on successful defence
 */
class DwarfCharacter : public Character {
public:
    /**
     * @brief Cosntructor for DwarfCharacter
     */
    DwarfCharacter(const std::string &n, TimeOfDay t = TimeOfDay::Day): Character(n, Race::Dwarf, t){}
    //There will be no changes
};

/**
 * @class HobbitCharacter
 * @brief Hobbit still takes 0-5 random damage on successful damage
 */
//Hobbit -> Successful defence causes 0-5 damage regardless of attack value
class HobbitCharacter : public Character{
public:
    /**
     * @brief Constructor for HobbitCharacter
     */
    HobbitCharacter(const std::string &n, TimeOfDay t = TimeOfDay::Day) : Character(n, Race::Hobbit, t){}
    /**
     * @brief onSuccessfulDefence - Hobbit takes 0-5 random damage even on success
     * @return Random damage value between 0 and 5
     */
    int onSuccessfulDefence(int attackerAdjustedAttack) override{
        std::uniform_int_distribution<int>dist(0,5);
        return dist(rng);
    }
};

/**
 * @class OrcCharacter
 * @brief Orcs have different defence effects during the day and night
 * -Day:- Takes 1/4 of adjusted damage
 * -Night:- Gains +1 health on successful defence
 */
class OrcCharacter : public Character{
public:
    /**
     * @brief Constructor for OrcCharacter
     */
    OrcCharacter(const std::string &n, TimeOfDay t) : Character(n, Race::Orc, t){}
    /**
     * @brief onSuccessfulDefence - Implements day/night defence behaviour
     * @return Damage taken aftrer applying race rules
     */
    int onSuccessfulDefence(int attackerAdjustedAttack) override {
        if (tod == TimeOfDay::Day){     //During the Day
            int myDef = getDefenceValue();
            int adjusted = attackerAdjustedAttack - myDef;
            if(adjusted <= 0){
                return 0;       //if attack is too weak then the orc takes no damage
            }
            return std::max(0, adjusted/4);
        }else{                          //During the night
            health += 1;
            return 0;
        }
    }
};
