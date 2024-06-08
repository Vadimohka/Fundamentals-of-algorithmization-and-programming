#include "randomgenerate.h"

XORShiftPlusPlus::XORShiftPlusPlus(uint64_t seed1, uint64_t seed2, uint64_t seed3) {
    state1 = seed1;
    state2 = seed2;
    state3 = seed3;
}

uint64_t XORShiftPlusPlus::next() {
    uint64_t x = state1;
    uint64_t y = state2;
    uint64_t z = state3;

    state1 = y;
    state2 = z;

    x ^= x << 23;
    y ^= y >> 17;
    y ^= x;
    z ^= y;
    z ^= z << 26;

    state3 = z;

    return (x + y) ^ z;
}

uint64_t XORShiftPlusPlus::Rand()
{
    static uint64_t seed = 4;
    seed = (seed * 73129 + 95121) % UINT64_MAX;
    return seed;
}

int XORShiftPlusPlus::getRandomYPos(){
    uint32_t randomValue = this->next() % (maxValueY - minValueY + 1) + minValueY;
    return randomValue;
}

int XORShiftPlusPlus::getRandomXPos(){
    uint32_t randomValue = this->next() % (maxValueX - minValueX + 1) + minValueX;
    return randomValue;
}

int XORShiftPlusPlus::getRandomValue(int minValue, int maxValue){
    uint32_t randomValue = this->next() % (maxValue - minValue + 1) + minValue;
    return randomValue;
}
