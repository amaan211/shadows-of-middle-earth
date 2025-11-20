#include "Armour.h"

Armour::Armour(std::string armourName, int armourWeight, int defenceBonus, int attackPenalty)
    : name(armourName), weight(armourWeight), defenceMod(defenceBonus), attackMod(attackPenalty) {}

std::string Armour::getName() const {
    return name;
}

std::string Armour::getCategory() const {
    return "Armour";
}

int Armour::getWeight() const {
    return weight;
}

int Armour::getAttackMod() const {
    return attackMod;
}

int Armour::getDefenceMod() const {
    return defenceMod;
}

int Armour::getHealthMod() const {
    return 0;
}

int Armour::getStrengthMod() const {
    return 0;
}

std::string Armour::getDescription() const {
    std::string desc = name + " [Armour] - Defence: +" + std::to_string(defenceMod);
    if (attackMod < 0) {
        desc += ", Attack: " + std::to_string(attackMod);
    }
    desc += ", Weight: " + std::to_string(weight);
    return desc;
}
