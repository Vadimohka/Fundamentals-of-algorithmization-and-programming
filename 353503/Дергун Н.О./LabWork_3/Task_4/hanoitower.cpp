#include "hanoitower.h"

int HanoiTower::maxRinningFunc() const
{
    return maxRinningFunc_;
}

void HanoiTower::setMaxRinningFunc(int newMaxRinningFunc)
{
    if (newMaxRinningFunc > MIN_FUNC_NUM && newMaxRinningFunc < MAX_FUNC_NUM) { maxRinningFunc_ = newMaxRinningFunc; };
}

QString& HanoiTower::hanoi(int n, char baseTower, char aimTower, char extraTower, QString& way)
{

    if (n == 1)
    {
        way += "1-th from " + QString(baseTower) + " to " + QString(aimTower) + QString('\n');
        return way;
    }

    if (runFuncCnt_ > maxRinningFunc_) { isOverflowed_ = true; }
    if (isOverflowed_)
    {
        way.prepend('-');
        return way;
    }

    ++runFuncCnt_;
    hanoi(n - 1, baseTower, extraTower, aimTower, way);
    way += QString::number(n) + "-th from " + QString(baseTower) + " to " + QString(aimTower) + QString('\n');
    hanoi(n - 1, extraTower, aimTower, baseTower, way);
    --runFuncCnt_;
    if (runFuncCnt_ == 0) { isOverflowed_ = false; }

    return way;
}
