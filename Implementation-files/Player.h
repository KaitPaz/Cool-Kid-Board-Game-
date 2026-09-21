#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
using namespace std;

#include "Token.h"
#include "NumberDie.h"
#include "OperationDie.h"

// Fixes vs. the original header:
//  - added constructors
//  - added getName/setName (spec requires them)
//  - added moveTo() (absolute move, used by ShortcutSpace/loop exit)
//  - added skipTurn tracking (EvenOddSpace penalty) and loop-tracking fields.
//    The spec puts these on a separate PlayerState class, but no
//    PlayerState.h was provided, so that state lives directly on Player here.
class Player {
    protected:
        string name;
        int position;
        Token token;

        bool skipTurn;

        bool inLoop;
        int loopID;
        int loopEntrance;
        int loopExit;
        int loopSize;

    public:
        Player();
        Player(string name, Token token);

        int rollNumberDie(NumberDie &die);
        char rollOperationDie(OperationDie &die);

        void move(int steps);
        void moveTo(int newPosition);

        int getPosition() const;
        void setPosition(int position);

        string getName() const;
        void setName(string name);

        Token getToken() const;

        void setSkipTurn(bool skip);
        bool shouldSkipTurn() const;

        void setInLoop(int loopID, int entrance, int exit, int size);
        void exitLoop();
        bool isInLoop() const;
        int getLoopID() const;
        int getLoopEntrancePosition() const;
        int getLoopExitPosition() const;
        int getLoopSize() const;
};

#endif
