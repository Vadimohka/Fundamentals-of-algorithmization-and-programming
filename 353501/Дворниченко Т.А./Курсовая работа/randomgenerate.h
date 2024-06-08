#pragma once

#include <cstdint>

class XORShiftPlusPlus {
private:
    uint64_t state1, state2, state3;

public:
    const int maxValueX = 940;
    const int minValueX = 270;
    const int maxValueY = 620;
    const int minValueY = 340;

    XORShiftPlusPlus(uint64_t seed1, uint64_t seed2, uint64_t seed3);

    uint64_t next();
    static uint64_t Rand();

    int getRandomYPos();
    int getRandomXPos();
    int getRandomValue(int minValue, int maxValue);
};
