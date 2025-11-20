#ifndef ARMOUR_H
#define ARMOUR_H

#include "Item.h"

class Armour : public Item {
private:
    std::string name;
    int defenceMod;

public:
    std::string getName() const;
    std::string getCategory() const;
    int getWeight() const;
    int getAttackMod() const;
    int getDefenceMod() const;
    int getHealthMod() const;
    int getStrengthMod() const;
    std::string getDescription() const;
};

#endif
