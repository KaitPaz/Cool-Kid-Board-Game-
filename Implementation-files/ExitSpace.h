#ifndef EXITSPACE_H
#define EXITSPACE_H

#include <iostream>
using namespace std;

#include "Space.h"
#include "Player.h"

// Fixes vs. the original header:
//  - now actually inherits from Space (it included Space.h but never
//    inherited from it)
//  - added a constructor
//  - added activate() — the original header had no way for this space to
//    actually do anything when a player landed on it
//  - added a display() override
class ExitSpace : public Space {
    private:
        int loopID;
        int entrancePosition;

    public:
        ExitSpace(int position, int loopID, int entrancePosition);

        int getLoopID() const;
        int getEntracePosition() const;
        void activate(Player&);

        void display() const override;
};

#endif
