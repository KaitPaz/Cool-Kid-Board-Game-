#include "ShortcutSpace.h"

ShortcutSpace::ShortcutSpace(int position, int targetPosition)
    : Space(position, "Shortcut"), targetPosition(targetPosition) {}

int ShortcutSpace::getTargetPosition() const {
    return targetPosition;
}

void ShortcutSpace::activate(Player &player) {
    cout << player.getName() << " lands on a Shortcut space and jumps to position "
         << targetPosition << "!" << endl;
    player.moveTo(targetPosition);
}

void ShortcutSpace::display() const {
    cout << "[" << position << "] Shortcut (-> " << targetPosition << ")";
}
