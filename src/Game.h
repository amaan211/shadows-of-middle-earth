/**
 * @file Game.h
 * @brief Main game controller class
 */

#ifndef GAME_H
#define GAME_H

#include <memory>
#include "Board.h"
#include "Character.h"
#include "Combat.h"

/**
 * @class Game
 * @brief Main game controller that ties all systems together
 *
 * Manages game state, processes commands, and coordinates between
 * character, combat, and board systems.
 */
class Game {
private:
    std::shared_ptr<Board> board;
    std::shared_ptr<Character> player;
    std::shared_ptr<Combat> combatSystem;
    int gold;
    bool gameRunning;

public:
    /**
     * @brief Constructor for Game
     */
    Game();

    /**
     * @brief Initialize a new game
     * @param boardWidth Width of game board
     * @param boardHeight Height of game board
     * @param playerRace Race of the player character
     * @param playerName Name of the player character
     */
    void initializeGame(int boardWidth, int boardHeight, const std::string& playerRace, const std::string& playerName);

    /**
     * @brief Process a game command
     * @param command The command string from player
     * @return std::string Result message
     */
    std::string processCommand(const std::string& command);

    /**
     * @brief Check if game is still running
     * @return bool True if game is active
     */
    bool isGameRunning() const;

    /**
     * @brief Get current game status summary
     * @return std::string Formatted status
     */
    std::string getGameStatus() const;

private:
    /**
     * @brief Handle player movement command
     * @param direction Movement direction
     * @return std::string Result message
     */
    std::string handleMove(const std::string& direction);

    /**
     * @brief Handle pick up item command
     * @return std::string Result message
     */
    std::string handlePickUp();

    /**
     * @brief Handle drop item command with user prompting
     * @return std::string Result message
     */
    std::string handleDrop();

    /**
     * @brief Handle attack command
     * @return std::string Result message
     */
    std::string handleAttack();

    /**
     * @brief Handle look command
     * @return std::string Result message
     */
    std::string handleLook();

    /**
     * @brief Handle inventory command
     * @return std::string Result message
     */
    std::string handleInventory();

    /**
     * @brief Create player character based on race
     * @param race Race name
     * @param name Character name
     * @return std::shared_ptr<Character> Player character
     */
    std::shared_ptr<Character> createPlayerCharacter(const std::string& race, const std::string& name);

    /**
     * @brief Recreate an item by its name for dropping
     * @param itemName Name of the item to recreate
     * @return std::shared_ptr<Item> Recreated item
     */
    std::shared_ptr<Item> recreateItemByName(const std::string& itemName);
};

#endif // GAME_H
