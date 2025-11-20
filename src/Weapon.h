/**
 * @file Weapon.h
 * @brief Weapon item class implementation
 */

#ifndef WEAPON_H
#define WEAPON_H

#include "Item.h"

class Weapon : public Item {
private:
    std::string name;
    int weight;
    int attackMod;

public:
    std::string getName() const;
    std::string getCategory() const;
    int getWeight() const;
    int getAttackMod() const;
    int getDefenceMod() const;
    int getHealthMod() const;
    int getStrengthMod() const;
    std::string getDescription() const;

    void setAttack(int newAttack);
};

#endif // WEAPON_H
