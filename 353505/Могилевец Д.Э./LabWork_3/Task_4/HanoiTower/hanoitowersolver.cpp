#include "hanoitowersolver.h"

HanoiTowerSolver::HanoiTowerSolver() {}

void HanoiTowerSolver::Solve(QTableWidget *table, int numOf1Ster, int numOf2Ster, int& numOfMove, int amOfRings)
{
    if (amOfRings == 0) return;
    if (amOfRings == 1) {
        table->setItem(numOfMove, 0, new QTableWidgetItem(QString((char)(numOf1Ster + 'A'))));
        table->setItem(numOfMove, 1, new QTableWidgetItem(QString((char)(numOf2Ster + 'A'))));
        numOfMove += 1;
        return;
    }
    Solve(table, numOf1Ster, 3 - numOf1Ster - numOf2Ster, numOfMove, amOfRings - 1);
    table->setItem(numOfMove, 0, new QTableWidgetItem(QString((char)(numOf1Ster + 'A'))));
    table->setItem(numOfMove, 1, new QTableWidgetItem(QString((char)(numOf2Ster + 'A'))));
    numOfMove += 1;
    Solve(table, 3 - numOf1Ster - numOf2Ster, numOf2Ster, numOfMove, amOfRings - 1);
}
