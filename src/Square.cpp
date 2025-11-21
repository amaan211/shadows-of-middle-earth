/**
 * @file Square.cpp
 * @brief Implementation of Square class
 */

#include "Square.h"

Square::Square() : isEmpty(true) {
    // Initialize as empty square
}

bool Square::getIsEmpty() const {
    return isEmpty && !item && !enemy;
}

void Square::setItem(std::shared_ptr<Item> newItem) {
    item = newItem;
    isEmpty = false;
}

std::shared_ptr<Item> Square::getItem() const {
    return item;
}

void Square::removeItem() {
    item.reset();
    // Check if square becomes empty
    if (!enemy) {
        isEmpty = true;
    }
}

void Square::setEnemy(std::shared_ptr<Character> newEnemy) {
    enemy = newEnemy;
    isEmpty = false;
}

std::shared_ptr<Character> Square::getEnemy() const {
    return enemy;
}

void Square::removeEnemy() {
    enemy.reset();
    // Check if square becomes empty
    if (!item) {
        isEmpty = true;
    }
}

std::string Square::getDescription() const {
    std::string description = "This location contains: ";

    if (isEmpty) {
        description += "nothing";
    } else {
        if (item) {
            description += "a " + item->getName();
        }
        if (enemy) {
            if (item) description += " and ";
            description += "a " + enemy->getRace() + " enemy named " + enemy->getName();
        }
    }

    return description;
}
