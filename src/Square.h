/**
 * @file Square.h
 * @brief Represents one location on the board.
 *
 * Each Square is dynamically created and is intended to be managed by smart pointers.
 * A Square may hold at most one item (unique_ptr owned by board or caller after take)
 * and at most one enemy (shared_ptr so combat module may also hold reference).
 */

#ifndef SQUARE_H
#define SQUARE_H

#include <memory>
#include "Position.h"

// Forward declarations to avoid requiring full implementations here
class Item;
class Character;

class Square {
public:
    Square(const Position &pos);
    ~Square();

    // Query
    bool hasEnemy() const;
    bool hasItem() const;

    // Item ownership: board owns item until takeItem() transfers unique_ptr to caller
    bool setItem(std::unique_ptr<Item> item);           // returns false if already has item
    std::unique_ptr<Item> takeItem();                   // transfers ownership to caller

    // Enemy ownership: shared_ptr so board and combat may share
    void setEnemy(std::shared_ptr<Character> enemy);
    std::shared_ptr<Character> takeEnemy();             // removes and returns shared_ptr

    const Position& getPosition() const;

private:
    Position position;
    std::unique_ptr<Item> itemPtr;                      // unique ownership
    std::shared_ptr<Character> enemyPtr;                // shared ownership
};

#endif // SQUARE_H
