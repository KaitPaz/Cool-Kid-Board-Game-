#include "NumberSpace.h"

NumberSpace::NumberSpace(int position, int number)
    : Space(position, "Number"), number(number) {}

int NumberSpace::getNumber() const {
    return number;
}

// Rolls the operation die to decide whether this space's number is added to
// or subtracted from the player's position.
void NumberSpace::activate(Player &player, OperationDie &die) {
    char op = player.rollOperationDie(die);
    cout << player.getName() << " lands on a Number space (" << number
         << ") and rolls '" << op << "'. ";

    if (op == '+') {
        cout << "Moving forward " << number << " spaces." << endl;
        player.move(number);
    } else {
        cout << "Moving back " << number << " spaces." << endl;
        player.move(-number);
    }
}

void NumberSpace::display() const {
    cout << "[" << position << "] Number (" << number << ")";
}
