#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    MyVector<int> tmp = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    print("Изначальный вектор (vector)", vector);

    tmp.swap(vector);
    print("tmp.swap(vector)", vector);

    vector.push_back(10);
    print("vector.push_back(10)", vector);

    vector.pop_back();
    print("vector.pop_back()", vector);

    vector.erase(0, 5);
    print("vector.erase(0, 5)", vector);

    vector.erase(0);
    print("vector.erase(0)", vector);

    vector.emplace(vector.begin(), 1);
    print("vector.emplace(vector.begin(), 1)", vector);

    vector.insert(vector.end(), 3, 6);
    print("vector.insert(vector.end(), 3, 6)", vector);

    vector.resize(1);
    print("vector.resize(1)", vector);

    vector.assign(10, 9);
    print("vector.assign(10, 9)", vector);

    vector.emplace_back(52);
    print("vector.emplace_back(52)", vector);

    vector.clear();
    print("vector.clear()", vector);

    tmp.push_back(18);
    tmp.push_back(99567);
    tmp.push_back(64);
    print("tmp.push_back(18) и тд", tmp);

    vector.assign(tmp.begin(), tmp.end());
    print("vector.assign(tmp.begin(), tmp.end())", vector);

    vector.clear();
    print("vector.clear()", vector);

    vector.push_back(vector.size());
    print("vector.push_back(vector.size())", vector);

    vector.push_back(vector.capacity());
    print("vector.push_back(vector.capacity())", vector);

    for (Iterator it(vector.begin()); it != vector.end(); it++) {
        qDebug() << *it;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::print(QString str, MyVector<int> vect)
{
    rows++;
    ui->tableWidget->setRowCount(rows);
    ui->tableWidget->setItem(rows - 1, 0, new QTableWidgetItem(str));
    QString tmp;
    for (int i : vect) {
        tmp.append(QString::number(i));
        tmp.append(", ");
    }
    tmp.remove(tmp.size() - 2, 2);
    ui->tableWidget->setItem(rows - 1, 1, new QTableWidgetItem(tmp));
    ui->tableWidget->resizeColumnsToContents();
}
