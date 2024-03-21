#ifndef HANOI_SOLVER_H
#define HANOI_SOLVER_H

#include <QString>
#include <QStack>
#include <QGraphicsScene>
#include <QTableWidget>
#include "disk.h"

class Hanoi_solver
{
public:
    Hanoi_solver();
    void solve(int num, QString source, QString dest, QString helper, QTableWidget *tableWidget);
};

#endif // HANOI_SOLVER_H
