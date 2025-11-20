#include "Ring.h"

std::string Ring::getName() const {
    return name;
}

std::string Ring::getCategory() const {
    return "Ring";
}

int Ring::getWeight() const {
    return 1;
}

int Ring::getAttackMod() const {
    return 0;
}

int Ring::getDefenceMod() const {
    return 0;
}

int Ring::getHealthMod() const {
    return healthMod;
}

int Ring::getStrengthMod() const {
    return 0;
}

std::string Ring::getDescription() const {
    return name + " [Ring] - Health: +" + std::to_string(healthMod);
}
