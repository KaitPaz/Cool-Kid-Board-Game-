#ifndef EVENODDSPACE_H
#define EVENODDSPACE_H

#include "Player.h"
#include "NumberDie.h"
#include "Space.h"

#include <iostream>
using namespace std;

// Fixes vs. the original header:
//  - now actually inherits from Space (it didn't before, so it couldn't be
//    stored/used polymorphically through a Space* / Space&)
//  - added a constructor
//  - added a display() override
class EvenOddSpace : public Space {
    private:
        string condition;   // "EVEN" or "ODD"

    public:
        EvenOddSpace(int position, string condition);

        bool checkCondition(int roll);
        string getCondition() const;
        void activate(Player&, NumberDie&);

        void display() const override;
};

#endif
