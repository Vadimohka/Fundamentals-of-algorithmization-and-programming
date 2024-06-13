#include<hanoi.h>
#include <QString>
#include <ui_mainwindow.h>
#include <QString>

QString movesHelper(int n, int column1, int column2, int column3) {
    QString result;
    if (n == 1) {
        result.append("Move disk " + QString::number(n) +
                      " from tower " + QString::number(column1) +
                      " to tower " + QString::number(column2) + "\n");
    } else {
        result.append(movesHelper(n - 1, column1, column3, column2));
        result.append("Move disk " + QString::number(n) +
                      " from tower " + QString::number(column1) +
                      " to tower " + QString::number(column2) + "\n");
        result.append(movesHelper(n - 1, column3, column2, column1));
    }
    return result;
}

QString moves(int disks){
    return movesHelper(disks, 1, 2, 3);
}
