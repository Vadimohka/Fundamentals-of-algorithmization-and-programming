#include "func.h"
#include "mainwindow.h"

void func::recurs(int n, QString first, QString aux, QString last) {
    if (n == 1) {
        displayMove("Move disk 1 from " + first + " to " + last);
        return;
    }

    recurs(n - 1, first, last, aux);
    displayMove("Move disk " + QString::number(n) + " from " + first + " to " + last);
    recurs(n - 1, aux, first, last);
}
