#include "NumberDie.h"
#include <cstdlib>

NumberDie::NumberDie() : lastRoll(0), minValue(1), maxValue(6) {}

NumberDie::NumberDie(int minValue, int maxValue)
    : lastRoll(0), minValue(minValue), maxValue(maxValue) {}

int NumberDie::getLastRoll() const {
    return lastRoll;
}

int NumberDie::roll() {
    int range = maxValue - minValue + 1;
    lastRoll = minValue + (rand() % range);
    return lastRoll;
}

void NumberDie::setMinValue(int minVal) {
    minValue = minVal;
}

void NumberDie::setMaxValue(int maxVal) {
    maxValue = maxVal;
}

int NumberDie::getMinValue() const {
    return minValue;
}

int NumberDie::getMaxValue() const {
    return maxValue;
}
