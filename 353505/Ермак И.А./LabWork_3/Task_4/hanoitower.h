#ifndef HANOITOWER_H
#define HANOITOWER_H

#include <QTableWidget>

class HanoiTower
{
public:
    HanoiTower();
    void Solve(QTableWidget*, int, int, int&, int);
};

#endif // HANOITOWER_H
