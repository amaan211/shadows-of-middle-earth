/**
 * @file Square.cpp
 * @brief Implementation of Square methods with pseudo-code comments for non-trivial logic.
 */

#include "Square.h"
#include <utility>

Square::Square(const Position &pos) : position(pos), itemPtr(nullptr), enemyPtr(nullptr) {}

Square::~Square() = default;

// hasEnemy()
// PSEUDO:
// return enemyPtr != nullptr
bool Square::hasEnemy() const {
    return (enemyPtr != nullptr);
}

// hasItem()
// PSEUDO:
// return itemPtr != nullptr
bool Square::hasItem() const {
    return (itemPtr != nullptr);
}

// setItem(item)
// PSEUDO:
// if (itemPtr != nullptr) return false
// else itemPtr = std::move(item); return true
bool Square::setItem(std::unique_ptr<Item> item) {
    if (itemPtr) return false;
    itemPtr = std::move(item);
    return true;
}

// takeItem()
// PSEUDO:
// if (itemPtr == nullptr) return nullptr
// tmp = std::move(itemPtr)
// itemPtr = nullptr
// return tmp
std::unique_ptr<Item> Square::takeItem() {
    if (!itemPtr) return nullptr;
    std::unique_ptr<Item> tmp = std::move(itemPtr);
    itemPtr = nullptr;
    return tmp;
}

// setEnemy(enemy)
// PSEUDO:
// enemyPtr = enemy (shared ownership)
void Square::setEnemy(std::shared_ptr<Character> enemy) {
    enemyPtr = enemy;
}

// takeEnemy()
// PSEUDO:
// tmp = enemyPtr
// enemyPtr.reset()
// return tmp
std::shared_ptr<Character> Square::takeEnemy() {
    std::shared_ptr<Character> tmp = enemyPtr;
    enemyPtr.reset();
    return tmp;
}

// getPosition()
// PSEUDO:
// return position
const Position& Square::getPosition() const {
    return position;
}
