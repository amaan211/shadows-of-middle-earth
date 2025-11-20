#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <memory>

class Item {
public:
    virtual ~Item() = default;
    virtual std::string getName() const = 0;
    virtual std::string getCategory() const = 0;
    virtual int getWeight() const = 0;
    virtual int getAttackMod() const = 0;
    virtual int getDefenceMod() const = 0;
    virtual int getHealthMod() const = 0;
    virtual int getStrengthMod() const = 0;
    virtual std::string getDescription() const = 0;
};

#endif
