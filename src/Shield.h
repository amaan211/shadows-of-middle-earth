#ifndef SHIELD_H
#define SHIELD_H

#include "Item.h"

class Shield : public Item {
private:
    std::string name;
    int weight;
    int defenceMod;
    int attackMod;

public:
    Shield(std::string shieldName, int shieldWeight, int defenceBonus, int attackPenalty = 0);
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
