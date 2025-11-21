/**
 * @file Game.cpp
 * @brief Implementation of Game class
 */

#include "Game.h"
#include "Human.h"
#include "Elf.h"
#include "Dwarf.h"
#include "Hobbit.h"
#include "Orc.h"
#include "ItemFactory.h"
#include <iostream>
#include <limits>

Game::Game() : gold(0), gameRunning(false) {
    combatSystem = std::make_shared<Combat>();
}

void Game::initializeGame(int boardWidth, int boardHeight, const std::string& playerRace, const std::string& playerName) {
    // Create game board
    board = std::make_shared<Board>(boardWidth, boardHeight);

    // Create player character
    player = createPlayerCharacter(playerRace, playerName);

    // Initialize board with items and enemies
    board->initializeBoard();

    gameRunning = true;
    gold = 0;
}

std::string Game::processCommand(const std::string& command) {
    if (!gameRunning) {
        return "Game is not running. Please start a new game.";
    }

    // Convert command to lowercase for case-insensitive comparison
    std::string lowerCommand = command;
    for (char& c : lowerCommand) {
        c = std::tolower(c);
    }

    // Process different commands
    if (lowerCommand == "north" || lowerCommand == "n") {
        return handleMove("north");
    } else if (lowerCommand == "south" || lowerCommand == "s") {
        return handleMove("south");
    } else if (lowerCommand == "east" || lowerCommand == "e") {
        return handleMove("east");
    } else if (lowerCommand == "west" || lowerCommand == "w") {
        return handleMove("west");
    } else if (lowerCommand == "pick up" || lowerCommand == "p") {
        return handlePickUp();
    } else if (lowerCommand == "drop" || lowerCommand == "d") {
        return handleDrop();
    } else if (lowerCommand == "attack" || lowerCommand == "a") {
        return handleAttack();
    } else if (lowerCommand == "look" || lowerCommand == "l") {
        return handleLook();
    } else if (lowerCommand == "inventory" || lowerCommand == "i") {
        return handleInventory();
    } else if (lowerCommand == "exit" || lowerCommand == "quit") {
        gameRunning = false;
        return "Game ended. Total gold collected: " + std::to_string(gold);
    } else {
        return "Unknown command. Available commands: north, south, east, west, pick up, drop, attack, look, inventory, exit";
    }
}

bool Game::isGameRunning() const {
    return gameRunning;
}

std::string Game::getGameStatus() const {
    std::string status = "Player: " + player->getName() + " (" + player->getRace() + ")\n";
    status += "Health: " + std::to_string(player->getHealth()) + "\n";
    status += "Gold: " + std::to_string(gold) + "\n";
    status += "Position: (" + std::to_string(board->getPlayerX()) + ", " + std::to_string(board->getPlayerY()) + ")\n";
    status += "Time: " + std::string(board->getIsDaytime() ? "Day" : "Night");

    return status;
}

std::string Game::handleMove(const std::string& direction) {
    bool moved = board->movePlayer(direction);

    if (moved) {
        return "Moved " + direction + ". " + board->getCurrentLocationDescription();
    } else {
        return "Cannot move " + direction + " - out of bounds.";
    }
}

std::string Game::handlePickUp() {
    std::shared_ptr<Square> currentSquare = board->getSquare(board->getPlayerX(), board->getPlayerY());

    if (!currentSquare->getItem()) {
        return "No item here to pick up.";
    }

    std::shared_ptr<Item> item = currentSquare->getItem();

    // Check if player can carry the item
    if (player->getInventory().addItem(item)) {
        currentSquare->removeItem();
        return "Picked up: " + item->getName();
    } else {
        return "Cannot pick up " + item->getName() + " - too heavy or category limit reached.";
    }
}

/**
 * @brief Handle drop command with user prompting
 * @return std::string Result message
 *
 * Pseudo-code:
 * 1. Check if current square already has an item
 * 2. If square has item, return error message
 * 3. Display player's inventory with numbered list
 * 4. Prompt user to select item by number
 * 5. Validate user input
 * 6. Get the selected item's name
 * 7. Remove item from inventory by name using existing method
 * 8. Place actual item on current square
 * 9. Return success message
 */
std::string Game::handleDrop() {
    std::shared_ptr<Square> currentSquare = board->getSquare(board->getPlayerX(), board->getPlayerY());

    // Check if square already has an item
    if (currentSquare->getItem()) {
        return "Cannot drop item here - square already contains an item.";
    }

    // Get player's inventory
    auto& inventory = player->getInventory();
    const auto& items = inventory.getItems();

    // Check if inventory is empty
    if (items.empty()) {
        return "Your inventory is empty - nothing to drop.";
    }

    // Display inventory with numbers
    std::cout << "\nYour inventory:\n";
    for (size_t i = 0; i < items.size(); ++i) {
        std::cout << "  " << (i + 1) << ". " << items[i]->getDescription() << "\n";
    }

    // Prompt user for item selection
    int choice;
    std::cout << "\nWhich item do you want to drop? (enter number, or 0 to cancel): ";
    std::cin >> choice;

    // Validate input
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return "Invalid input - please enter a number.";
    }
    std::cin.ignore(); // Clear newline

    // Check for cancel
    if (choice == 0) {
        return "Drop cancelled.";
    }

    // Validate choice range
    if (choice < 1 || choice > static_cast<int>(items.size())) {
        return "Invalid choice - please select a number from the list.";
    }

    // Get the selected item's name (adjust for 0-based index)
    int itemIndex = choice - 1;
    std::string itemName = items[itemIndex]->getName();

    // Remove item from inventory by name using existing method
    if (inventory.removeItem(itemName)) {
        // Recreate the item for the square
        std::shared_ptr<Item> droppedItem = recreateItemByName(itemName);
        if (droppedItem) {
            currentSquare->setItem(droppedItem);
            return "Dropped: " + itemName;
        } else {
            return "Failed to create item for dropping.";
        }
    } else {
        return "Failed to drop item from inventory.";
    }
}

/**
 * @brief Recreate an item by its name (helper function for drop)
 * @param itemName Name of the item to recreate
 * @return std::shared_ptr<Item> Recreated item or nullptr if not found
 *
 * Pseudo-code:
 * 1. Check item name against all known item types
 * 2. Use ItemFactory to create the appropriate item
 * 3. Return the created item
 */
std::shared_ptr<Item> Game::recreateItemByName(const std::string& itemName) {
    if (itemName == "Sword") {
        return ItemFactory::createSword();
    } else if (itemName == "Dagger") {
        return ItemFactory::createDagger();
    } else if (itemName == "Plate Armour") {
        return ItemFactory::createPlateArmour();
    } else if (itemName == "Leather Armour") {
        return ItemFactory::createLeatherArmour();
    } else if (itemName == "Large Shield") {
        return ItemFactory::createLargeShield();
    } else if (itemName == "Small Shield") {
        return ItemFactory::createSmallShield();
    } else if (itemName == "Ring of Life") {
        return ItemFactory::createRingOfLife();
    } else if (itemName == "Ring of Strength") {
        return ItemFactory::createRingOfStrength();
    }
    return nullptr;
}

std::string Game::handleAttack() {
    std::shared_ptr<Square> currentSquare = board->getSquare(board->getPlayerX(), board->getPlayerY());
    std::shared_ptr<Character> enemy = currentSquare->getEnemy();

    if (!enemy) {
        return "No enemy here to attack.";
    }

    std::string message = "COMBAT BEGINS!\n\n";

    // PHASE 1: Player attacks enemy (Rule: player attacks first)
    message += "YOUR ATTACK:\n";
    auto playerAttackResult = combatSystem->executeCombatRound(player, enemy, board->getIsDaytime());

    if (playerAttackResult.first) {
        // Player's attack was successful
        if (enemy->isDefeated()) {
            // Enemy defeated by player's attack - no counterattack
            message += "You defeated the " + enemy->getRace() + "!\n";
            message += "Gained " + std::to_string(playerAttackResult.second) + " gold.\n";
            gold += playerAttackResult.second;
            currentSquare->removeEnemy();
        } else {
            // Enemy survived player's attack
            message += "You hit the " + enemy->getRace() + "!\n";
            message += "Enemy health: " + std::to_string(enemy->getHealth()) + "\n\n";

            // PHASE 2: Enemy counterattacks (Rule: enemy counterattacks unless defeated)
            message += "ENEMY COUNTERATTACK:\n";
            auto enemyAttackResult = combatSystem->executeCombatRound(enemy, player, board->getIsDaytime());

            if (enemyAttackResult.first) {
                // Enemy's counterattack was successful
                message += "The " + enemy->getRace() + " hits you!\n";
                message += "Your health: " + std::to_string(player->getHealth()) + "\n";

                // Check if player was defeated by counterattack
                if (player->isDefeated()) {
                    message += "\nYOU HAVE BEEN DEFEATED! GAME OVER.\n";
                    gameRunning = false;
                }
            } else {
                // Enemy's counterattack missed
                message += "The " + enemy->getRace() + "'s attack missed!\n";
            }
        }
    } else {
        // Player's attack missed
        message += "Your attack missed!\n\n";

        // PHASE 2: Enemy counterattacks even if player missed (Rule: enemy always counterattacks unless defeated)
        message += "ENEMY COUNTERATTACK:\n";
        auto enemyAttackResult = combatSystem->executeCombatRound(enemy, player, board->getIsDaytime());

        if (enemyAttackResult.first) {
            // Enemy's counterattack was successful
            message += "The " + enemy->getRace() + " hits you!\n";
            message += "Your health: " + std::to_string(player->getHealth()) + "\n";

            // Check if player was defeated by counterattack
            if (player->isDefeated()) {
                message += "\nYOU HAVE BEEN DEFEATED! GAME OVER.\n";
                gameRunning = false;
            }
        } else {
            // Enemy's counterattack missed
            message += "The " + enemy->getRace() + "'s attack missed!\n";
        }
    }

    return message;
}

std::string Game::handleLook() {
    return board->getCurrentLocationDescription();
}

/**
 * @brief Handle inventory command - shows items and gold
 * @return std::string Inventory summary with gold
 *
 * Pseudo-code:
 * 1. Get inventory summary from player's inventory
 * 2. Add gold information to the summary
 * 3. Return combined inventory and gold display
 */
std::string Game::handleInventory() {
    std::string inventorySummary = player->getInventory().getInventorySummary();

    // Add gold information to the inventory display
    std::string goldInfo = "\nGold: " + std::to_string(gold);

    return inventorySummary + goldInfo;
}

std::shared_ptr<Character> Game::createPlayerCharacter(const std::string& race, const std::string& name) {
    if (race == "human") {
        return std::make_shared<Human>(name);
    } else if (race == "elf") {
        return std::make_shared<Elf>(name);
    } else if (race == "dwarf") {
        return std::make_shared<Dwarf>(name);
    } else if (race == "hobbit") {
        return std::make_shared<Hobbit>(name);
    } else if (race == "orc") {
        return std::make_shared<Orc>(name);
    } else {
        // Default to human if race not recognized
        return std::make_shared<Human>(name);
    }
}
