#include "Game.h"
#include "EvenOddSpace.h"
#include "NumberSpace.h"
#include "ShortcutSpace.h"
#include "EndlessLoopSpace.h"
#include "ExitSpace.h"

static const int BOARD_SIZE = 36;

Game::Game()
    : board(BOARD_SIZE),
      player1("Player 1", Token('X', "Red")),
      player2("Player 2", Token('O', "Blue")),
      numberDie1(1, 6), numberDie2(1, 6), operationDie(),
      currentPlayerIndex(0), gameOver(false) {}

Game::Game(string name1, string name2)
    : board(BOARD_SIZE),
      player1(name1, Token('X', "Red")),
      player2(name2, Token('O', "Blue")),
      numberDie1(1, 6), numberDie2(1, 6), operationDie(),
      currentPlayerIndex(0), gameOver(false) {}

void Game::start() {
    board.initializeBoard();
    player1.setPosition(0);
    player2.setPosition(0);
    currentPlayerIndex = 0;
    gameOver = false;

    cout << "===== Welcome to Cool Kid Game! =====" << endl;
    cout << player1.getName() << " vs " << player2.getName() << endl;
    cout << "First to reach position " << (board.getSize() - 1) << " wins!" << endl;
}

void Game::takeTurn() {
    if (gameOver) {
        return;
    }

    Player &current = (currentPlayerIndex == 0) ? player1 : player2;

    cout << "\n--- " << current.getName() << "'s turn (position "
         << current.getPosition() << ") ---" << endl;

    if (current.shouldSkipTurn()) {
        cout << current.getName() << " must skip this turn." << endl;
        current.setSkipTurn(false);
        switchPlayer();
        return;
    }

    int roll1 = current.rollNumberDie(numberDie1);
    int roll2 = current.rollNumberDie(numberDie2);
    int steps = roll1 + roll2;
    cout << current.getName() << " rolls " << roll1 << " and " << roll2
         << " (total " << steps << ")." << endl;

    board.movePlayer(current, steps);
    cout << current.getName() << " moves to position " << current.getPosition() << "." << endl;

    Space *landed = board.getSpace(current.getPosition());
    if (landed != nullptr) {
        landed->display();
        cout << endl;

        if (EvenOddSpace *eo = dynamic_cast<EvenOddSpace*>(landed)) {
            eo->activate(current, numberDie1);
        } else if (NumberSpace *ns = dynamic_cast<NumberSpace*>(landed)) {
            ns->activate(current, operationDie);
        } else if (ShortcutSpace *ss = dynamic_cast<ShortcutSpace*>(landed)) {
            ss->activate(current);
        } else if (EndlessLoopSpace *el = dynamic_cast<EndlessLoopSpace*>(landed)) {
            el->activate(current);
        } else if (ExitSpace *ex = dynamic_cast<ExitSpace*>(landed)) {
            ex->activate(current);
        }
    }

    checkWinner();

    if (!gameOver) {
        switchPlayer();
    }
}

bool Game::checkWinner() {
    int lastPosition = board.getSize() - 1;
    if (player1.getPosition() >= lastPosition) {
        cout << "\n*** " << player1.getName() << " reaches the end and wins! ***" << endl;
        gameOver = true;
    } else if (player2.getPosition() >= lastPosition) {
        cout << "\n*** " << player2.getName() << " reaches the end and wins! ***" << endl;
        gameOver = true;
    }
    return gameOver;
}

void Game::switchPlayer() {
    currentPlayerIndex = (currentPlayerIndex + 1) % 2;
}

bool Game::isGameOver() const {
    return gameOver;
}

const Board& Game::getGameBoard() const {
    return board;
}

void Game::displayBoard() const {
    board.displayBoard(player1, player2);
}

NumberDie Game::getNumberDie1() const {
    return numberDie1;
}

NumberDie Game::getNumberDie2() const {
    return numberDie2;
}

OperationDie Game::getOperationDie() const {
    return operationDie;
}

int Game::getCurrentPlayerNum() const {
    return currentPlayerIndex;
}