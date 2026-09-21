#ifndef OPERATIONDIE_H
#define OPERATIONDIE_H

#include <iostream>
using namespace std;

// Fixes vs. the original header:
//  - lastRoll changed from int to char, and getLastRoll() now returns char,
//    so it actually matches what roll() produces ('+' or '-'). The original
//    header declared roll() -> char but getLastRoll() -> int, which can't
//    represent the same value.
//  - added a constructor
class OperationDie {
    private:
        char lastRoll;

    public:
        OperationDie();

        char getLastRoll() const;
        char roll();   // returns '+' or '-'
};

#endif
