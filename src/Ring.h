#ifndef RING_H
#define RING_H

#include "Item.h"

class Ring : public Item {
private:
    std::string name;
    int weight;
    int healthMod;
    int strengthMod;

public:
    Ring(std::string ringName, int ringWeight, int healthBonus, int strengthBonus);
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
