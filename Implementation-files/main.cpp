#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

#include "Game.h"

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));

    string name1, name2;
    cout << "Enter Player 1's name: ";
    getline(cin, name1);
    cout << "Enter Player 2's name: ";
    getline(cin, name2);

    if (name1.empty()) name1 = "Player 1";
    if (name2.empty()) name2 = "Player 2";

    Game game(name1, name2);
    game.start();

    while (!game.isGameOver()) {
        game.displayBoard();
        cout << "Press Enter to take the next turn...";
        string dummy;
        getline(cin, dummy);
        game.takeTurn();
    }

    game.displayBoard();
    cout << "\nThanks for playing Cool Kid Game!" << endl;
    return 0;
}
