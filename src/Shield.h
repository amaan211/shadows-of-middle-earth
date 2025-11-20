#ifndef SHIELD_H
#define SHIELD_H

#include "Item.h"

class Shield : public Item {
private:
    std::string name;
    int weight;
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
