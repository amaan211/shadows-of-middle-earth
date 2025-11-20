#include "Shield.h"

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
    return -5;
}

int Shield::getDefenceMod() const {
    return defenceMod;
}

int Shield::getHealthMod() const {
    return 5;
}

int Shield::getStrengthMod() const {
    return 0;
}

std::string Shield::getDescription() const {
    return name + " [Shield] - Defence: " + std::to_string(defenceMod);
}
