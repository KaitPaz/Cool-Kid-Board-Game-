#include "EvenOddSpace.h"

EvenOddSpace::EvenOddSpace(int position, string condition)
    : Space(position, "EvenOdd"), condition(condition) {}

bool EvenOddSpace::checkCondition(int roll) {
    if (condition == "EVEN") {
        return roll % 2 == 0;
    }
    return roll % 2 != 0;
}

string EvenOddSpace::getCondition() const {
    return condition;
}

// Player is stuck here until they roll a number matching this space's
// condition. A successful roll moves them forward by that amount; a failed
// roll costs them their next turn.
void EvenOddSpace::activate(Player &player, NumberDie &die) {
    int roll = player.rollNumberDie(die);
    cout << player.getName() << " lands on an Even/Odd space (needs "
         << condition << ") and rolls a " << roll << ". ";

    if (checkCondition(roll)) {
        cout << "That matches! Moving forward " << roll << " spaces." << endl;
        player.move(roll);
    } else {
        cout << "No match — " << player.getName() << " is stuck and skips their next turn." << endl;
        player.setSkipTurn(true);
    }
}

void EvenOddSpace::display() const {
    cout << "[" << position << "] Even/Odd (" << condition << ")";
}
