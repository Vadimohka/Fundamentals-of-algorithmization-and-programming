#ifndef HANOITOWERSOLVER_H
#define HANOITOWERSOLVER_H

#include <QTableWidget>

class HanoiTowerSolver
{
public:
    HanoiTowerSolver();
    void Solve(QTableWidget*, int, int, int&, int);
};

#endif // HANOITOWERSOLVER_H
