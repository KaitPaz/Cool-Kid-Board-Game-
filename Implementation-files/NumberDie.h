#ifndef NUMBERDIE_H
#define NUMBERDIE_H

#include <iostream>
using namespace std;

// Fixes vs. the original header:
//  - "minVlaue" -> "minValue" typo
//  - added constructors (default 1-6 die, and a ranged constructor per spec)
class NumberDie {
    private:
        int lastRoll;
        int minValue;
        int maxValue;

    public:
        NumberDie();
        NumberDie(int minValue, int maxValue);

        int getLastRoll() const;
        int roll();

        void setMinValue(int minValue);
        void setMaxValue(int maxValue);
        int getMinValue() const;
        int getMaxValue() const;
};

#endif
