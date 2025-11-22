#ifndef RACE_H
#define RACE_H

#include <string>

enum class TimeOfDay {Day,Night};

struct RaceProperties{
    std::string name;
    int baseAttack;
    int attackChanceNum;
    int attackChanceDen;
    int baseDefence;
    int defenceChanceNum;
    int defenceChanceDen;
    int baseHealth;
    int baseStrength;
};

enum class Race{Human, Elf, Dwarf, Hobbit, Orc};

//Function to get properties for a race, but orc will depend varying by Day and Night.
inline RaceProperties getRaceProperties(Race r, TimeOfDay tod = TimeOfDay::Day){
    switch(r){
    case Race::Human:
        return {"Human", 30, 2, 3, 20, 1, 2, 60, 100};
    case Race::Elf:
        return {"Elf", 40, 1, 1, 10, 1, 4, 40, 70};
    case Race::Dwarf:
        return {"Dwarf",330, 2, 3, 20, 2, 3, 50, 130};
    case Race::Hobbit:
        return {"Hobbit", 25, 1, 3, 20, 2, 3, 70, 85};
    case Race::Orc: {
        if(tod == TimeOfDay::Day){
            return {"Orc", 25, 1, 4, 10, 1, 4, 50, 130};
        }else{
            return {"Orc", 45, 1, 1, 25, 1, 2, 50, 130};
        }
    }
        return {"Unkown", 0, 1, 1, 0, 1, 1, 0, 0};

    }
}

#endif // RACE_H
