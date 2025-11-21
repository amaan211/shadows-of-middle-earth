/**
 * @file main.cpp
 * @brief Main entry point for Fantasy Game
 * @version 1.0
 * @date 2025
 */

#include "Game.h"
#include <iostream>
#include <string>
#include <limits>

/**
 * @brief Main function - entry point of the application
 * @return Exit status (0 for success, 1 for error)
 */
int main() {
    try {
        Game game;

        // Display game title and welcome message
        std::cout << "=== Shadows of Middle Earth ===\n";
        std::cout << "Welcome to the Fantasy Game!\n\n";

        // Fixed large board size - no user input needed
        const int BOARD_WIDTH = 15;
        const int BOARD_HEIGHT = 15;

        int characterChoice;

        // Character selection menu
        std::cout << "=== Choose Your Race ===\n";
        std::cout << "1. Human - Balanced warrior (Attack: 30, Defence: 20, Health: 60, Strength: 100)\n";
        std::cout << "2. Elf - Master archer (Attack: 40, Defence: 10, Health: 40, Strength: 70)\n";
        std::cout << "3. Dwarf - Tough defender (Attack: 30, Defence: 20, Health: 50, Strength: 130)\n";
        std::cout << "4. Hobbit - Lucky survivor (Attack: 25, Defence: 20, Health: 70, Strength: 85)\n";
        std::cout << "5. Orc - Night predator (Attack: 25/45, Defence: 10/25, Health: 50, Strength: 130)\n\n";

        // Get character choice with input validation
        while (true) {
            std::cout << "Enter your choice (1-5): ";
            std::cin >> characterChoice;

            if (std::cin.fail() || characterChoice < 1 || characterChoice > 5) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid choice! Please enter a number between 1 and 5.\n";
            } else {
                std::cin.ignore();
                break;
            }
        }

        // Map numeric choice to race string
        std::string playerRace;
        std::string playerName;
        switch (characterChoice) {
        case 1: playerRace = "human"; playerName = "Human Hero"; break;
        case 2: playerRace = "elf"; playerName = "Elf Archer"; break;
        case 3: playerRace = "dwarf"; playerName = "Dwarf Warrior"; break;
        case 4: playerRace = "hobbit"; playerName = "Hobbit Adventurer"; break;
        case 5: playerRace = "orc"; playerName = "Orc Champion"; break;
        default: playerRace = "human"; playerName = "Adventurer";
        }

        // Initialize the game
        game.initializeGame(BOARD_WIDTH, BOARD_HEIGHT, playerRace, playerName);

        std::cout << "\nGame started! You are " << playerName << ".\n";
        std::cout << "Board size: " << BOARD_WIDTH << "x" << BOARD_HEIGHT << "\n";
        std::cout << "Type 'help' for available commands.\n\n";

        // Main game loop
        std::string playerCommand;
        while (game.isGameRunning()) {
            std::cout << "> ";
            std::getline(std::cin, playerCommand);

            if (playerCommand.empty()) continue;

            if (playerCommand == "help") {
                std::cout << "\n=== Available Commands ===\n";
                std::cout << "Movement: north, south, east, west (or n, s, e, w)\n";
                std::cout << "Items: pick up (or p), drop [item name]\n";
                std::cout << "Combat: attack (or a)\n";
                std::cout << "Information: look (or l), inventory (or i)\n";
                std::cout << "Game: exit, quit\n";
                std::cout << "==========================\n\n";
                continue;
            }

            std::string commandResult = game.processCommand(playerCommand);
            std::cout << commandResult << "\n\n";

            if (!game.isGameRunning()) break;

            std::cout << "=== Current Status ===\n";
            std::cout << game.getGameStatus() << "\n\n";
        }

        std::cout << "Thank you for playing!\n";

    } catch (const std::exception& error) {
        std::cerr << "Unexpected error occurred: " << error.what() << std::endl;
        return 1;
    }

    return 0;
}
