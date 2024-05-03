#ifndef HANOITOWER_H
#define HANOITOWER_H

#include <QString>

const uint MAX_FUNC_NUM = 9990;
const uint MIN_FUNC_NUM = 10;

class HanoiTower
{
    int maxRinningFunc_ = MAX_FUNC_NUM;
    bool isOverflowed_ = false;
    int runFuncCnt_ = 0;

public:
    QString& hanoi(int n, char baseTower, char aimTower, char extraTower, QString& way);

    int maxRinningFunc() const;
    void setMaxRinningFunc(int newMaxRinningFunc);
};


#endif // HANOITOWER_H
