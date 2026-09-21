#include "Player.h"

Player::Player()
    : name("Player"), position(0), token(),
      skipTurn(false),
      inLoop(false), loopID(-1), loopEntrance(-1), loopExit(-1), loopSize(0) {}

Player::Player(string name, Token token)
    : name(name), position(0), token(token),
      skipTurn(false),
      inLoop(false), loopID(-1), loopEntrance(-1), loopExit(-1), loopSize(0) {}

int Player::rollNumberDie(NumberDie &die) {
    return die.roll();
}

char Player::rollOperationDie(OperationDie &die) {
    return die.roll();
}

void Player::move(int steps) {
    position += steps;
}

void Player::moveTo(int newPosition) {
    position = newPosition;
}

int Player::getPosition() const {
    return position;
}

void Player::setPosition(int newPosition) {
    position = newPosition;
}

string Player::getName() const {
    return name;
}

void Player::setName(string newName) {
    name = newName;
}

Token Player::getToken() const {
    return token;
}

void Player::setSkipTurn(bool skip) {
    skipTurn = skip;
}

bool Player::shouldSkipTurn() const {
    return skipTurn;
}

void Player::setInLoop(int newLoopID, int entrance, int exit, int size) {
    inLoop = true;
    loopID = newLoopID;
    loopEntrance = entrance;
    loopExit = exit;
    loopSize = size;
}

void Player::exitLoop() {
    inLoop = false;
    loopID = -1;
    loopEntrance = -1;
    loopExit = -1;
    loopSize = 0;
}

bool Player::isInLoop() const {
    return inLoop;
}

int Player::getLoopID() const {
    return loopID;
}

int Player::getLoopEntrancePosition() const {
    return loopEntrance;
}

int Player::getLoopExitPosition() const {
    return loopExit;
}

int Player::getLoopSize() const {
    return loopSize;
}
