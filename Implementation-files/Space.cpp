#include "Space.h"

Space::Space() : position(0), spaceType("Space") {}

Space::Space(int position, string spaceType) : position(position), spaceType(spaceType) {}

Space::~Space() {}

int Space::getPosition() const {
    return position;
}

string Space::getSpaceType() const {
    return spaceType;
}

void Space::display() const {
    cout << "[" << position << "] " << spaceType;
}
