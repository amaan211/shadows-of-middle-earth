#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <memory>
#include <iostream>

class Item {
public:
    virtual std::string getName() const;
    virtual std::string getCategory() const;
    virtual int getWeight() const;
    virtual int getAttackMod() const;
    virtual int getDefenceMod() const;
    virtual int getHealthMod() const;
    virtual int getStrengthMod() const;
    virtual std::string getDescription() const;

    void printInfo() {
        std::cout << "Item info" << std::endl;
    }
};

#endif
