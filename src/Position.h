/**
 * @file Position.h
 * @brief Simple position (row,col) container used by Board and Square.
 *
 * Doxygen header required by project instructions.
 */

#ifndef POSITION_H
#define POSITION_H

struct Position {
    int row;
    int col;

    Position() : row(0), col(0) {}
    Position(int r, int c) : row(r), col(c) {}
    bool operator==(const Position &o) const { return row == o.row && col == o.col; }
};

#endif // POSITION_H
