#include "mainwindow.h"
#include "ui_mainwindow.h"

mainwindow::mainwindow(QWidget *parent) :
        QWidget(parent), ui(new Ui::mainwindow) {
    ui->setupUi(this);

    SetStart();
}

mainwindow::~mainwindow() {
    delete ui;
}

void mainwindow::SetStart() {
    v.clear();
    Vector<int> v11 = {5, 5 ,4};
    Vector<int> v12(2, 4);
    Vector<int> v13(5);

    Vector<Pair<int, double>> v21 = {{1, 1.1}, {2, 2.2}, {3, 3.3}};

    Pair p = Pair<int, double>::make_pair(15, 4);
    Vector<Pair<int, double>> v22(2, p);

    Vector<Pair<int, double>> v23(2);
    v23.push_back({7, 7.7});
    v23.push_back({70, 70.7});
    v23.push_back({700, 700.7});

    v.push_back({v11, v21});
    v.emplace_back(v12, v22);
    v.emplace(v.cbegin() + 1, v13, v23);

    for(int i = 0; i < v.size(); i ++)
    {
        auto f = v[i].first;
        QString add;
        for(auto x : f)
        {
            add += QString::number(x) + ' ';
        }
        int row = ui->firsttableWidget->rowCount();
        ui->firsttableWidget->insertRow(row);
        QTableWidgetItem *item = new QTableWidgetItem;
        item->setText(add);
        ui->firsttableWidget->setItem(i, 0, item);

        add.clear();
        auto s = v[i].second;
        for(auto x : s)
        {
            add += "{ " + QString::number(x.first) + ", " + QString::number(x.second) + " } ";
        }
        QTableWidgetItem *item1 = new QTableWidgetItem;
        item1->setText(add);
        ui->secondtableWidget->insertRow(row);
        ui->secondtableWidget->setItem(i, 0, item1);
        qDebug() << add;
    }
}
