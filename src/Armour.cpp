#include "Armour.h"

std::string Armour::getName() const {
    return name;
}

std::string Armour::getCategory() const {
    return "Armour";
}

int Armour::getWeight() const {
    return 0;
}

int Armour::getAttackMod() const {
    return 0;
}

int Armour::getDefenceMod() const {
    return defenceMod;
}

int Armour::getHealthMod() const {
    return 10;
}

int Armour::getStrengthMod() const {
    return 0;
}

std::string Armour::getDescription() const {
    return name + " [Armour]";
}
