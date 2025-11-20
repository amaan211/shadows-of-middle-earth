#include "Shield.h"

Shield::Shield(std::string shieldName, int shieldWeight, int defenceBonus, int attackPenalty)
    : name(shieldName), weight(shieldWeight), defenceMod(defenceBonus), attackMod(attackPenalty) {}

std::string Shield::getName() const {
    return name;
}

std::string Shield::getCategory() const {
    return "Shield";
}

int Shield::getWeight() const {
    return weight;
}

int Shield::getAttackMod() const {
    return attackMod;
}

int Shield::getDefenceMod() const {
    return defenceMod;
}

int Shield::getHealthMod() const {
    return 0;
}

int Shield::getStrengthMod() const {
    return 0;
}

std::string Shield::getDescription() const {
    std::string desc = name + " [Shield] - Defence: +" + std::to_string(defenceMod);
    if (attackMod < 0) {
        desc += ", Attack: " + std::to_string(attackMod);
    }
    desc += ", Weight: " + std::to_string(weight);
    return desc;
}
