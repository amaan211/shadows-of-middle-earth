#ifndef RING_H
#define RING_H

#include "Item.h"

class Ring : public Item {
private:
    std::string name;
    int healthMod;

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
