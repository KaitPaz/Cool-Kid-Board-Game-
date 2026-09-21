#ifndef NUMBERSPACE_H
#define NUMBERSPACE_H

#include <iostream>
using namespace std;

#include "Player.h"
#include "OperationDie.h"
#include "Space.h"

// Fixes vs. the original header:
//  - now actually inherits from Space (it included Space.h but never
//    inherited from it)
//  - added a constructor
//  - added a display() override
class NumberSpace : public Space {
    private:
        int number;

    public:
        NumberSpace(int position, int number);

        int getNumber() const;
        void activate(Player&, OperationDie&);

        void display() const override;
};

#endif
