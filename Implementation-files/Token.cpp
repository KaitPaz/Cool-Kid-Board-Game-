#include "Token.h"

Token::Token() : symbol('?'), color("none") {}

Token::Token(char symbol, string color) : symbol(symbol), color(color) {}

void Token::setSymbol(char newSymbol) {
    symbol = newSymbol;
}

char Token::getSymbol() const {
    return symbol;
}

void Token::setColor(string newColor) {
    color = newColor;
}

string Token::getColor() const {
    return color;
}

void Token::display() const {
    cout << color << " token '" << symbol << "'";
}
