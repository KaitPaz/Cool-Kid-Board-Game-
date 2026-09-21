#ifndef SPACE_H
#define SPACE_H

#include <iostream>
#include <string>
using namespace std;

// Abstract base class for every space on the board.
// Fixes vs. the original header:
//  - added constructors so position/spaceType can actually be set
//  - added a virtual destructor (required for safe polymorphic deletion)
//  - made getPosition()/getSpaceType() public (subclasses & Board need them)
//  - made display() virtual so each subclass can override it
class Space {
    protected:
        int position;
        string spaceType;

    public:
        Space();
        Space(int position, string spaceType);
        virtual ~Space();

        int getPosition() const;
        string getSpaceType() const;

        virtual void display() const;
};

#endif
