#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <vector>
using namespace std;

#include "Space.h"
#include "Player.h"

// Fixes vs. the original header:
//  - The original stored FIVE separate `vector<Space>` members (one per
//    subclass name) holding objects BY VALUE. That design couldn't work:
//    storing an EvenOddSpace/NumberSpace/etc. in a vector<Space> slices off
//    all the derived-class data, and there was no single indexed structure
//    representing "the 36 spaces of the board" that getSpace(position)
//    could look up in O(1).
//  - Replaced with one `vector<Space*> spaces`, sized to `size`, indexed
//    directly by board position, so getSpace(position) is a simple lookup
//    and polymorphism (display(), dynamic_cast to the real subtype) works.
//  - The original typed getters (getEvenOddSpace, getNumberSpace, ...) are
//    kept for interface compatibility; they now dynamic_cast the Space* at
//    that position to the requested subtype (returning nullptr on mismatch)
//    instead of searching a separate vector.
//  - Added a constructor, destructor (frees the owned Space*), and disabled
//    copying (Board owns raw pointers, so a shallow copy would double-free).
class Board {
    private:
        int size;
        vector<Space*> spaces;

    public:
        Board();
        Board(int size);
        ~Board();

        Board(const Board&) = delete;
        Board& operator=(const Board&) = delete;

        void initializeBoard();

        Space* getSpace(int position) const;
        Space* getEvenOddSpace(int position) const;
        Space* getNumberSpace(int position) const;
        Space* getShortCutSpace(int position) const;
        Space* getEndlessLoopSpace(int position) const;
        Space* getExitSpace(int position) const;

        void movePlayer(Player&, int steps);
        bool isValidPosition(int position) const;

        void setSize(int size);
        int getSize() const;

        // Prints the whole board to the terminal with ANSI color-coding by
        // space type, plus each player's token marking where they stand.
        void displayBoard(const Player &p1, const Player &p2) const;
};

#endif