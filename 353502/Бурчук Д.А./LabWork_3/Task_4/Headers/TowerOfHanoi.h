#ifndef LAB3TASK1_TOWEROFHANOI_H
#define LAB3TASK1_TOWEROFHANOI_H
#define HEIGHT 600.0
#define WIDTH 500.0
#define MIN_COUNT_OF_RINGS 3u
#define MAX_COUNT_OF_RINGS 10u

#include "QWidget"

#include "Ring.h"

class TowerOfHanoi {
    uint _numberOfRings;

    std::vector<int> _sticks;

public:
    std::vector<Ring> _rings;

    explicit TowerOfHanoi();

    void setStick(int from, int to);

    void setStickStart(int first, int second, int third);

    uint numberOfRings();

    int stick(int to);

    void drawStick(QPainter *painter);

    void setNumberOfRings(uint numberOfRings);

    void makeRings();
};

#endif//LAB3TASK1_TOWEROFHANOI_H
