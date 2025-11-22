// THis file is to implement specialized classes to override onSuccessfulDefence()

#include "Character.h"

//Human -> Successful defence never causes damage -> which is default
//ELf -> Successful defence always increases health by 1
class ElfCharacter : public Character{
public:
    ElfCharacter(const std::string &n, TimeOfDay t = TimeOfDay::Day): Character(n, Race::Elf, t) {}
    int onSuccessfulDefence(int attackerAdjustedAttack) override {
        health += 1;
        return 0;
    }
};

//Dwarfs -> Successful defence never causes damage -> default
class DwarfCharacter : public Character {
public:
    DwarfCharacter(const std::string &n, TimeOfDay t = TimeOfDay::Day): Character(n, Race::Dwarf, t){}
    //There will be no changes
};

//Hobbit -> Successful defence causes 0-5 damage regardless of attack value
class HobbitCharacter : public Character{
public:
    HobbitCharacter(const std::string &n, TimeOfDay t = TimeOfDay::Day) : Character(n, Race::Hobbit, t){}
    int onSuccessfulDefence(int attackerAdjustedAttack) override{
        std::uniform_int_distribution<int>dist(0,5);
        return dist(rng);
    }
};

//Orc -> During the Day successful defence causes 1/4 of adjusted damage
//    -> During the night successful defence increases health by 1
class OrcCharacter : public Character{
public:
    OrcCharacter(const std::string &n, TimeOfDay t) : Character(n, Race::Orc, t){}
    int onSuccessfulDefence(int attackerAdjustedAttack) override {
        if (tod == TimeOfDay::Day){     //During the Day
            int myDef = getDefenceValue();
            int adjusted = attackerAdjustedAttack - myDef;
            if(adjusted <= 0){
                return 0;
            }
            return std::max(0, adjusted/4);
        }else{                          //During the +Night
            health += 1;
            return 0;
        }
    }
};
