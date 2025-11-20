#include "Ring.h"

Ring::Ring(std::string ringName, int ringWeight, int healthBonus, int strengthBonus)
    : name(ringName), weight(ringWeight), healthMod(healthBonus), strengthMod(strengthBonus) {}

std::string Ring::getName() const {
    return name;
}

std::string Ring::getCategory() const {
    return "Ring";
}

int Ring::getWeight() const {
    return weight;
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
    return strengthMod;
}

std::string Ring::getDescription() const {
    std::string desc = name + " [Ring]";
    if (healthMod != 0) {
        desc += " Health: " + std::string(healthMod > 0 ? "+" : "") + std::to_string(healthMod);
    }
    if (strengthMod != 0) {
        desc += " Strength: " + std::string(strengthMod > 0 ? "+" : "") + std::to_string(strengthMod);
    }
    desc += ", Weight: " + std::to_string(weight);
    return desc;
}
