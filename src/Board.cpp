/**
 * @file Board.cpp
 * @brief Implementation of Board class
 */

#include "Board.h"
#include "Human.h"
#include "Hobbit.h"
#include "Dwarf.h"
#include "Orc.h"
#include "Elf.h"
#include <random>

Board::Board(int boardWidth, int boardHeight)
    : width(boardWidth), height(boardHeight), playerX(0), playerY(0),
    isDaytime(true), commandCount(0) {

    // Initialize the 2D grid with smart pointers
    squares.resize(height);
    for (int i = 0; i < height; ++i) {
        squares[i].resize(width);
        for (int j = 0; j < width; ++j) {
            // Create each square with std::make_shared as required
            squares[i][j] = std::make_shared<Square>();
        }
    }
}

void Board::initializeBoard() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> itemDist(0, 3); // 25% chance for item
    std::uniform_int_distribution<> enemyDist(0, 4); // 20% chance for enemy
    std::uniform_int_distribution<> raceDist(0, 4);  // Random race selection

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            if (i == playerY && j == playerX) continue;

            if (itemDist(gen) == 0) {
                std::shared_ptr<Item> randomItem = ItemFactory::createRandomItem();
                squares[i][j]->setItem(randomItem);
            }

            if (enemyDist(gen) == 0) {
                // Randomly select enemy race but all with same balanced stats
                int raceChoice = raceDist(gen);
                std::shared_ptr<Character> enemy;

                switch (raceChoice) {
                case 0:
                    enemy = std::make_shared<Human>("Evil Human");
                    break;
                case 1:
                    enemy = std::make_shared<Elf>("Bad Elf");
                    break;
                case 2:
                    enemy = std::make_shared<Dwarf>("Tiny Dwarf");
                    break;
                case 3:
                    enemy = std::make_shared<Hobbit>("Clone Hobbit");
                    break;
                case 4:
                    enemy = std::make_shared<Orc>("Orcy Orc");
                    break;
                default:
                    enemy = std::make_shared<Human>("Evil Human");
                }

                squares[i][j]->setEnemy(enemy);
            }
        }
    }
}

std::shared_ptr<Square> Board::getSquare(int x, int y) const {
    // Check bounds before accessing
    if (x < 0 || x >= width || y < 0 || y >= height) {
        return nullptr;
    }
    return squares[y][x];
}

int Board::getPlayerX() const {
    return playerX;
}

int Board::getPlayerY() const {
    return playerY;
}

bool Board::movePlayer(const std::string& direction) {
    int newX = playerX;
    int newY = playerY;

    // Calculate new position based on direction
    if (direction == "north") {
        newY--;
    } else if (direction == "south") {
        newY++;
    } else if (direction == "east") {
        newX++;
    } else if (direction == "west") {
        newX--;
    } else {
        return false; // Invalid direction
    }

    // Check if new position is within bounds
    if (newX < 0 || newX >= width || newY < 0 || newY >= height) {
        return false; // Movement out of bounds
    }

    // Update player position
    playerX = newX;
    playerY = newY;

    // Increment command count for day/night cycle
    incrementCommandCount();

    return true;
}

bool Board::getIsDaytime() const {
    return isDaytime;
}

void Board::incrementCommandCount() {
    commandCount++;

    // Toggle day/night every 5 commands
    if (commandCount % 5 == 0) {
        isDaytime = !isDaytime;
    }
}

std::string Board::getCurrentLocationDescription() const {
    std::shared_ptr<Square> currentSquare = getSquare(playerX, playerY);
    if (!currentSquare) {
        return "Invalid location";
    }

    std::string description = "You are at position (" + std::to_string(playerX) +
                              ", " + std::to_string(playerY) + "). ";
    description += currentSquare->getDescription();
    description += "\nTime: " + std::string(isDaytime ? "Day" : "Night");

    return description;
}

std::pair<int, int> Board::getDimensions() const {
    return std::make_pair(width, height);
}
