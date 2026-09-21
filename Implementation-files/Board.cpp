#include "Board.h"
#include "EvenOddSpace.h"
#include "NumberSpace.h"
#include "ShortcutSpace.h"
#include "EndlessLoopSpace.h"
#include "ExitSpace.h"

Board::Board() : size(0) {}

Board::Board(int boardSize) : size(boardSize) {
    spaces.assign(size, nullptr);
}

Board::~Board() {
    for (Space* s : spaces) {
        delete s;
    }
}

void Board::setSize(int newSize) {
    for (Space* s : spaces) {
        delete s;
    }
    size = newSize;
    spaces.assign(size, nullptr);
}

int Board::getSize() const {
    return size;
}

// Lays out all `size` spaces. Every position starts as a plain Space, then
// specific positions are overridden with the special space types. One loop
// (positions 20-25) is included, matching EndlessLoopSpace's loopSize=6.
void Board::initializeBoard() {
    for (Space* s : spaces) {
        delete s;
    }
    spaces.assign(size, nullptr);

    for (int i = 0; i < size; i++) {
        spaces[i] = new Space(i, "Plain");
    }

    auto place = [&](int pos, Space* s) {
        if (pos >= 0 && pos < size) {
            delete spaces[pos];
            spaces[pos] = s;
        } else {
            delete s;
        }
    };

    place(3, new NumberSpace(3, 2));
    place(6, new EvenOddSpace(6, "EVEN"));
    place(9, new ShortcutSpace(9, 14));
    place(12, new EvenOddSpace(12, "ODD"));
    place(15, new NumberSpace(15, 3));
    place(18, new ShortcutSpace(18, 4));

    // Loop occupying positions 20-25 (loopSize = 6): entrance at 20,
    // exit exactly at 25.
    place(20, new EndlessLoopSpace(20, 1, 25, 6));
    place(25, new ExitSpace(25, 1, 20));

    place(28, new NumberSpace(28, 4));
    place(31, new EvenOddSpace(31, "EVEN"));
    place(33, new ShortcutSpace(33, 35));
}

Space* Board::getSpace(int position) const {
    if (!isValidPosition(position)) {
        return nullptr;
    }
    return spaces[position];
}

Space* Board::getEvenOddSpace(int position) const {
    return dynamic_cast<EvenOddSpace*>(getSpace(position));
}

Space* Board::getNumberSpace(int position) const {
    return dynamic_cast<NumberSpace*>(getSpace(position));
}

Space* Board::getShortCutSpace(int position) const {
    return dynamic_cast<ShortcutSpace*>(getSpace(position));
}

Space* Board::getEndlessLoopSpace(int position) const {
    return dynamic_cast<EndlessLoopSpace*>(getSpace(position));
}

Space* Board::getExitSpace(int position) const {
    return dynamic_cast<ExitSpace*>(getSpace(position));
}

bool Board::isValidPosition(int position) const {
    return position >= 0 && position < size;
}

// Normal movement just adds steps (clamped to the board). While a player is
// trapped in a loop, movement wraps around the loop's positions instead —
// they only leave once they land exactly on the loop's ExitSpace.
void Board::movePlayer(Player &player, int steps) {
    int current = player.getPosition();

    if (player.isInLoop()) {
        int entrance = player.getLoopEntrancePosition();
        int loopSize = player.getLoopSize();
        int offset = ((current - entrance) + steps) % loopSize;
        if (offset < 0) {
            offset += loopSize;
        }
        player.moveTo(entrance + offset);
        return;
    }

    int newPos = current + steps;
    if (newPos >= size) {
        newPos = size - 1;
    }
    if (newPos < 0) {
        newPos = 0;
    }
    player.moveTo(newPos);
}

namespace {
    const string RESET    = "\033[0m";
    const string PLAIN     = "\033[37m";   // white
    const string NUMBER    = "\033[33m";   // yellow
    const string EVENODD   = "\033[36m";   // cyan
    const string SHORTCUT  = "\033[35m";   // magenta
    const string LOOP      = "\033[31m";   // red
    const string EXIT      = "\033[32m";   // green
    const string P1_MARK   = "\033[1;44m"; // bold, blue background
    const string P2_MARK   = "\033[1;41m"; // bold, red background
}

void Board::displayBoard(const Player &p1, const Player &p2) const {
    const int perRow = 6;

    cout << "\n";
    for (int i = 0; i < size; i++) {
        Space *s = spaces[i];
        string type = (s != nullptr) ? s->getSpaceType() : "Plain";

        string color;
        char code;
        if (type == "Number")           { color = NUMBER;   code = 'N'; }
        else if (type == "EvenOdd")     { color = EVENODD;  code = 'E'; }
        else if (type == "Shortcut")    { color = SHORTCUT; code = 'S'; }
        else if (type == "EndlessLoop") { color = LOOP;      code = 'L'; }
        else if (type == "Exit")        { color = EXIT;      code = 'X'; }
        else                             { color = PLAIN;     code = '.'; }

        cout << color << "[" << (i < 10 ? "0" : "") << i << code << "]" << RESET;

        bool p1Here = (p1.getPosition() == i);
        bool p2Here = (p2.getPosition() == i);
        if (p1Here) {
            cout << P1_MARK << p1.getToken().getSymbol() << RESET;
        } else {
            cout << " ";
        }
        if (p2Here) {
            cout << P2_MARK << p2.getToken().getSymbol() << RESET;
        } else {
            cout << " ";
        }

        cout << " ";
        if ((i + 1) % perRow == 0) {
            cout << "\n";
        }
    }
    cout << "\n\n";

    cout << "Legend: "
         << PLAIN    << ".=Plain "   << RESET
         << NUMBER   << "N=Number "  << RESET
         << EVENODD  << "E=EvenOdd " << RESET
         << SHORTCUT << "S=Shortcut " << RESET
         << LOOP     << "L=Loop "    << RESET
         << EXIT     << "X=Exit"     << RESET << "\n";

    cout << P1_MARK << p1.getToken().getSymbol() << RESET << " = " << p1.getName()
         << "    "
         << P2_MARK << p2.getToken().getSymbol() << RESET << " = " << p2.getName()
         << "\n";
}