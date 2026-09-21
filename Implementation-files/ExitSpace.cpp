#include "ExitSpace.h"

ExitSpace::ExitSpace(int position, int loopID, int entrancePosition)
    : Space(position, "Exit"), loopID(loopID), entrancePosition(entrancePosition) {}

int ExitSpace::getLoopID() const {
    return loopID;
}

int ExitSpace::getEntracePosition() const {
    return entrancePosition;
}

// A player only escapes a loop by landing EXACTLY on the exit space that
// belongs to the loop they're currently trapped in.
void ExitSpace::activate(Player &player) {
    if (player.isInLoop() && player.getLoopID() == loopID) {
        cout << player.getName() << " lands exactly on the exit and escapes Loop #"
             << loopID << "!" << endl;
        player.exitLoop();
    }
}

void ExitSpace::display() const {
    cout << "[" << position << "] Exit for Loop #" << loopID;
}
