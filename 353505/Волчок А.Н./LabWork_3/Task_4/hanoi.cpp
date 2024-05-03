#include "hanoi.h"

void hanoi::hanoi_solver(int n,char a,char b,char c,QTableWidget *table) {
    if (n == 0)
        return;

    if (n == 1) {
        int row = table->rowCount();
        table->insertRow(row);
        std::string str="Move disk ";
        str+=std::to_string(n);
        str+=" from ";
        str.push_back(a);
        str+=" to ";
        str.push_back(c);
        QString j=QString::fromStdString(str);
        QTableWidgetItem*kk;
        kk=new QTableWidgetItem(j);
        table->setItem(count,0,kk);
        kk->setFlags(kk->flags() ^ Qt::ItemIsEditable);
        count++;

        return;
    }

    hanoi_solver(n - 1, a, c, b,table);
    int row = table->rowCount();
    table->insertRow(row);
    std::string str="Move disk ";
    str+=std::to_string(n);
    str+=" from ";
    str.push_back(a);
    str+=" to ";
    str.push_back(c);
    QString j=QString::fromStdString(str);
    QTableWidgetItem*kk=new QTableWidgetItem(j);
    table->setItem(count,0,kk);
    kk->setFlags(kk->flags() ^ Qt::ItemIsEditable);
    count++;

    hanoi_solver(n - 1, b, a, c,table);
}
