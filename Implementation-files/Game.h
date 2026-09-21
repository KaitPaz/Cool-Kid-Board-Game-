#ifndef GAME_H
#define GAME_H

#include <iostream>
using namespace std;


#include "Player.h"
#include "Board.h"
#include "NumberDie.h"
#include "OperationDie.h"

// Fixes vs. the original header:
//  - getGameBoard() now returns `const Board&` instead of `Board` by value.
//    Board owns raw Space* pointers and its copy constructor is deleted
//    (see Board.h), so returning by value can't compile; a const reference
//    also matches the spec's own description ("read only access to board
//    state") better than a copy would.
//  - "getOperatioDie" -> "getOperationDie" typo fix.
//  - added constructors.
class Game{
    protected:
        Board board;
        Player player1;
        Player player2;
        NumberDie numberDie1;
        NumberDie numberDie2;
        OperationDie operationDie;
        int currentPlayerIndex;
        bool gameOver;

    public:
        Game();
        Game(string name1, string name2);

        void start();
        void takeTurn();
        bool checkWinner();
        void switchPlayer();
        bool isGameOver() const;

        const Board& getGameBoard() const;
        void displayBoard() const;
        NumberDie getNumberDie1() const;
        NumberDie getNumberDie2() const;
        OperationDie getOperationDie() const;
        int getCurrentPlayerNum() const;
};

#endif