/**
 * @file Board.h
 * @brief Game board management with smart pointers
 */

#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <memory>
#include "Square.h"
#include "ItemFactory.h"
#include "Character.h"

/**
 * @class Board
 * @brief Manages the game board using smart pointers
 *
 * Creates and manages a 2D grid of squares using std::shared_ptr.
 * Handles player movement, board initialization, and square interactions.
 */
class Board {
private:
    std::vector<std::vector<std::shared_ptr<Square>>> squares;
    int width;
    int height;
    int playerX;
    int playerY;
    bool isDaytime;
    int commandCount;

public:
    /**
     * @brief Constructor for Board
     * @param boardWidth Width of the game board
     * @param boardHeight Height of the game board
     */
    Board(int boardWidth, int boardHeight);

    /**
     * @brief Initialize the board with random items and enemies
     */
    void initializeBoard();

    /**
     * @brief Get the square at specified coordinates
     * @param x X coordinate
     * @param y Y coordinate
     * @return std::shared_ptr<Square> Pointer to square
     */
    std::shared_ptr<Square> getSquare(int x, int y) const;

    /**
     * @brief Get player's current X position
     * @return int X coordinate
     */
    int getPlayerX() const;

    /**
     * @brief Get player's current Y position
     * @return int Y coordinate
     */
    int getPlayerY() const;

    /**
     * @brief Move player in specified direction
     * @param direction Movement direction (north, south, east, west)
     * @return bool True if movement was successful
     */
    bool movePlayer(const std::string& direction);

    /**
     * @brief Get current time of day
     * @return bool True if daytime, false if nighttime
     */
    bool getIsDaytime() const;

    /**
     * @brief Increment command count and update day/night cycle
     */
    void incrementCommandCount();

    /**
     * @brief Get description of player's current location
     * @return std::string Formatted location description
     */
    std::string getCurrentLocationDescription() const;

    /**
     * @brief Get board dimensions
     * @return std::pair<int, int> (width, height)
     */
    std::pair<int, int> getDimensions() const;
};

#endif // BOARD_H
