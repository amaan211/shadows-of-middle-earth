/**
 * @file Square.h
 * @brief Square class representing each board location
 */

#ifndef SQUARE_H
#define SQUARE_H

#include <memory>
#include "Item.h"
#include "Character.h"

/**
 * @class Square
 * @brief Represents a single location on the game board
 *
 * Each square can contain an item, an enemy, or be empty.
 * Managed by smart pointers as required by project specification.
 */
class Square {
private:
    std::shared_ptr<Item> item;
    std::shared_ptr<Character> enemy;
    bool isEmpty;

public:
    /**
     * @brief Constructor for Square
     */
    Square();

    /**
     * @brief Check if square is empty
     * @return bool True if square has no item or enemy
     */
    bool getIsEmpty() const;

    /**
     * @brief Set item on this square
     * @param newItem Shared pointer to the item
     */
    void setItem(std::shared_ptr<Item> newItem);

    /**
     * @brief Get item from this square
     * @return std::shared_ptr<Item> Pointer to item or nullptr
     */
    std::shared_ptr<Item> getItem() const;

    /**
     * @brief Remove item from this square
     */
    void removeItem();

    /**
     * @brief Set enemy on this square
     * @param newEnemy Shared pointer to the enemy character
     */
    void setEnemy(std::shared_ptr<Character> newEnemy);

    /**
     * @brief Get enemy from this square
     * @return std::shared_ptr<Character> Pointer to enemy or nullptr
     */
    std::shared_ptr<Character> getEnemy() const;

    /**
     * @brief Remove enemy from this square
     */
    void removeEnemy();

    /**
     * @brief Get description of square contents
     * @return std::string Formatted description
     */
    std::string getDescription() const;
};

#endif // SQUARE_H
