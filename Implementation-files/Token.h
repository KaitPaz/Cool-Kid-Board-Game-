#ifndef TOKEN_H
#define TOKEN_H

#include <iostream>
#include <string>
using namespace std;

// Fixes vs. the original header:
//  - added a `color` member (spec's Token has a symbol AND a color)
//  - added constructors
//  - added getSymbol/setSymbol/getColor/setColor (spec requires them; the
//    original header only had the `symbol` field and display())
class Token {
    protected:
        char symbol;
        string color;

    public:
        Token();
        Token(char symbol, string color);

        void setSymbol(char symbol);
        char getSymbol() const;

        void setColor(string color);
        string getColor() const;

        void display() const;
};

#endif
