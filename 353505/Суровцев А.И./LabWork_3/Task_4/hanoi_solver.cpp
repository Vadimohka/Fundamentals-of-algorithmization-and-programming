#include "hanoi_solver.h"

Hanoi_solver::Hanoi_solver() {}

void Hanoi_solver::solve(int num, QString source, QString dest, QString helper, QTableWidget *tableWidget)
{
    if (num == 1) {
        int row = tableWidget->rowCount();
        tableWidget->insertRow(row);
        QTableWidgetItem *item1 = new QTableWidgetItem(source);
        QTableWidgetItem *item2 = new QTableWidgetItem(dest);
        tableWidget->setItem(row, 0, item1);
        tableWidget->setItem(row, 1, item2);
        return;
    }

    solve(num - 1, source, helper, dest, tableWidget);

    int row = tableWidget->rowCount();
    tableWidget->insertRow(row);
    QTableWidgetItem *item1 = new QTableWidgetItem(source);
    QTableWidgetItem *item2 = new QTableWidgetItem(dest);
    tableWidget->setItem(row, 0, item1);
    tableWidget->setItem(row, 1, item2);
    solve(num - 1, helper, dest, source, tableWidget);
}
