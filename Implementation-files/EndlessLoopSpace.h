#ifndef ENDLESSLOOPSPACE_H
#define ENDLESSLOOPSPACE_H

#include <iostream>
using namespace std;

#include "Space.h"
#include "Player.h"

// Fixes vs. the original header:
//  - now actually inherits from Space
//  - added a constructor
//  - added a display() override
// This space represents the loop's ENTRANCE. Landing here (or being inside
// the loop already) puts the player into a looping movement state that
// Board/Game use until the player lands exactly on the matching ExitSpace.
class EndlessLoopSpace : public Space {
    private:
        int loopID;
        int entracePosition;
        int exitPosition;
        int loopSize;

    public:
        EndlessLoopSpace(int position, int loopID, int exitPosition, int loopSize);

        int getLoopID() const;
        int getEntracePosition() const;
        int getExitPosition() const;
        int getLoopSize() const;
        void activate(Player&);

        void display() const override;
};

#endif
