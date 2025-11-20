/**
 * @file Board.cpp
 * @brief Implementation of Board methods with pseudo-code comments for non-trivial logic.
 *
 * Note: initializeBoard uses provided factory callables to create Items/Enemies.
 */

#include "Board.h"
#include "Square.h"
#include <random>
#include <cctype>

Board::Board(unsigned r, unsigned c)
    : rows(r), cols(c), squares(), startPosition(0,0),
    commandCount(0), daytime(true)
{
    // PSEUDO:
    // allocate squares vector with rows*cols shared_ptr<Square> created via make_shared
    squares.reserve(rows * cols);
    for (unsigned i = 0; i < rows; ++i) {
        for (unsigned j = 0; j < cols; ++j) {
            squares.push_back(std::make_shared<Square>(Position(static_cast<int>(i), static_cast<int>(j))));
        }
    }
    // default start position (0,0); initializeBoard can adjust or ensure this is empty
    startPosition = Position(0, 0);
    commandCount = 0;
    daytime = true;
}

Board::~Board() = default;

// indexFromRC(row,col)
// PSEUDO:
// return row*cols + col
int Board::indexFromRC(int row, int col) const {
    return row * static_cast<int>(cols) + col;
}

// isValidPosition(row,col)
// PSEUDO:
// return (row >=0 && row < rows && col >=0 && col < cols)
bool Board::isValidPosition(int row, int col) const {
    if (row < 0 || col < 0) return false;
    if (static_cast<unsigned>(row) >= rows) return false;
    if (static_cast<unsigned>(col) >= cols) return false;
    return true;
}

// getSquare(row,col)
// PSEUDO:
// if !isValidPosition throw or return nullptr
// index = indexFromRC
// return squares[index]
std::shared_ptr<Square> Board::getSquare(int row, int col) {
    if (!isValidPosition(row, col)) return nullptr;
    int idx = indexFromRC(row, col);
    return squares[static_cast<size_t>(idx)];
}

// initializeBoard(enemyFactory,itemFactory,enemyProb,itemProb)
// PSEUDO:
// Use mt19937 random engine
// for each square:
//   sample uniform real [0,1)
//   if sample < enemyProb:
//     create enemy via enemyFactory() and setEnemy on square
//   else if sample < enemyProb + itemProb:
//     create item via itemFactory() and setItem on square
// ensure startPosition square is empty (if not, clear it)
void Board::initializeBoard(EnemyFactory enemyFactory, ItemFactory itemFactory,
                            double enemyProb, double itemProb)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dist(0.0, 1.0);

    for (unsigned r = 0; r < rows; ++r) {
        for (unsigned c = 0; c < cols; ++c) {
            auto sq = getSquare(static_cast<int>(r), static_cast<int>(c));
            double sample = dist(gen);
            if (sample < enemyProb) {
                if (enemyFactory) sq->setEnemy(enemyFactory());
            } else if (sample < enemyProb + itemProb) {
                if (itemFactory) sq->setItem(itemFactory());
            } else {
                // leave empty
            }
        }
    }

    // Ensure starting square is empty (startPosition default 0,0)
    auto startSq = getSquare(startPosition.row, startPosition.col);
    if (startSq->hasEnemy()) startSq->takeEnemy();
    if (startSq->hasItem()) startSq->takeItem();
}

// getStartPosition()
// PSEUDO:
// return startPosition
Position Board::getStartPosition() const {
    return startPosition;
}

// movePlayer(playerPos,direction)
// PSEUDO:
// interpret direction (N,S,E,W)
// compute targetRow/targetCol
// if !isValidPosition return false
// playerPos = Position(targetRow,targetCol)
// return true
bool Board::movePlayer(Position &playerPos, char direction) {
    char d = static_cast<char>(std::toupper(static_cast<unsigned char>(direction)));
    int targetRow = playerPos.row;
    int targetCol = playerPos.col;

    if (d == 'N') targetRow -= 1;
    else if (d == 'S') targetRow += 1;
    else if (d == 'E') targetCol += 1;
    else if (d == 'W') targetCol -= 1;
    else return false; // invalid direction

    if (!isValidPosition(targetRow, targetCol)) return false;

    playerPos.row = targetRow;
    playerPos.col = targetCol;
    return true;
}

// advanceTime()
// PSEUDO:
// commandCount++
// if (commandCount % 5 == 0) toggle daytime
void Board::advanceTime() {
    ++commandCount;
    if ((commandCount % 5) == 0) {
        daytime = !daytime;
    }
}

// isDaytime()
// PSEUDO:
// return daytime
bool Board::isDaytime() const {
    return daytime;
}

unsigned Board::getCommandCount() const {
    return commandCount;
}
