/**
 * @file Board.h
 * @brief Board manages a grid of Square objects (smart-pointer managed) and time (day/night).
 *
 * Interaction expectations (documented for other modules):
 * - getSquare(row,col) returns shared_ptr<Square> for Game/Combat/Inventory to inspect.
 * - initializeBoard accepts factory callables to create Item/Character instances.
 * - advanceTime() must be called by Game controller after each command; day/night toggles every 5 commands.
 *
 * NOTE: The Board does not implement combat or inventory logic; it only provides squares and time state.
 */

#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <memory>
#include <functional>
#include "Position.h"

class Square;
class Item;
class Character;

class Board {
public:
    // Factory signatures for initialization:
    // enemyFactory -> returns shared_ptr<Character> (may be nullptr to indicate no enemy)
    // itemFactory  -> returns unique_ptr<Item> (may be nullptr)
    using EnemyFactory = std::function<std::shared_ptr<Character>()>;
    using ItemFactory  = std::function<std::unique_ptr<Item>()>;

    Board(unsigned rows, unsigned cols);
    ~Board();

    // Build / initialize
    // P: factories will be called for each square based on probabilities
    void initializeBoard(EnemyFactory enemyFactory, ItemFactory itemFactory,
                         double enemyProb = 0.15, double itemProb = 0.15);

    // Access
    std::shared_ptr<Square> getSquare(int row, int col);
    bool isValidPosition(int row, int col) const;
    Position getStartPosition() const;

    // Movement
    // direction: 'N','S','E','W' (case insensitive)
    // Returns true if playerPos updated; false if invalid move
    bool movePlayer(Position &playerPos, char direction);

    // Time management (every command should call advanceTime)
    void advanceTime();
    bool isDaytime() const;
    unsigned getCommandCount() const;

private:
    unsigned rows;
    unsigned cols;
    std::vector<std::shared_ptr<Square>> squares; // row-major: index = row*cols + col

    Position startPosition;
    unsigned commandCount;
    bool daytime;

    int indexFromRC(int row, int col) const;
};

#endif // BOARD_H
