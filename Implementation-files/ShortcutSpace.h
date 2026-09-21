#ifndef SHORTCUTSPACE_H
#define SHORTCUTSPACE_H

#include <iostream>
using namespace std;

#include "Space.h"
#include "Player.h"

// Fixes vs. the original header:
//  - now actually inherits from Space
//  - removed the duplicate "#include Space.h" (harmless with the include
//    guard, but tidied up)
//  - added a constructor
//  - added a display() override
class ShortcutSpace : public Space {
    private:
        int targetPosition;

    public:
        ShortcutSpace(int position, int targetPosition);

        int getTargetPosition() const;
        void activate(Player&);

        void display() const override;
};

#endif
