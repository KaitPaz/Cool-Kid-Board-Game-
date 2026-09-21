#include "EndlessLoopSpace.h"

EndlessLoopSpace::EndlessLoopSpace(int position, int loopID, int exitPosition, int loopSize)
    : Space(position, "EndlessLoop"),
      loopID(loopID), entracePosition(position),
      exitPosition(exitPosition), loopSize(loopSize) {}

int EndlessLoopSpace::getLoopID() const {
    return loopID;
}

int EndlessLoopSpace::getEntracePosition() const {
    return entracePosition;
}

int EndlessLoopSpace::getExitPosition() const {
    return exitPosition;
}

int EndlessLoopSpace::getLoopSize() const {
    return loopSize;
}

// Landing on the loop entrance traps the player: they'll keep circling
// (handled by Board::movePlayer) until they roll exactly what's needed to
// land on the matching ExitSpace.
void EndlessLoopSpace::activate(Player &player) {
    cout << player.getName() << " lands on Loop #" << loopID
         << "'s entrance and gets trapped!" << endl;
    player.setInLoop(loopID, entracePosition, exitPosition, loopSize);
}

void EndlessLoopSpace::display() const {
    cout << "[" << position << "] Endless Loop #" << loopID << " entrance";
}
