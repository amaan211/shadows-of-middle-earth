#ifndef ARMOUR_H
#define ARMOUR_H

#include "Item.h"

class Armour : public Item {
private:
    std::string name;
    int weight;
    int defenceMod;
    int attackMod;

public:
    Armour(std::string armourName, int armourWeight, int defenceBonus, int attackPenalty = 0);
    std::string getName() const override;
    std::string getCategory() const override;
    int getWeight() const override;
    int getAttackMod() const override;
    int getDefenceMod() const override;
    int getHealthMod() const override;
    int getStrengthMod() const override;
    std::string getDescription() const override;
};

#endif
