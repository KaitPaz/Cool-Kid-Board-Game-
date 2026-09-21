#include "OperationDie.h"
#include <cstdlib>

OperationDie::OperationDie() : lastRoll('+') {}

char OperationDie::getLastRoll() const {
    return lastRoll;
}

char OperationDie::roll() {
    lastRoll = (rand() % 2 == 0) ? '+' : '-';
    return lastRoll;
}
