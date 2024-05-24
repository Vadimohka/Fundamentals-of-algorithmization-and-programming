#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "hanoiclass.h"
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui -> setupUi(this);
    hanoi_towers = new HanoiClass();
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::start(int n, char from, char temp, char to)
{
    if (n == 1) {
        moveDisk(n, from, to);
    } else {
        start(n - 1, from, to, temp);
        moveDisk(n, from, to);
        start(n - 1, temp, from, to);
    }
}


void MainWindow::moveDisk(int number,char from,char to)
{
    ui -> table -> setRowCount(row);
    QTableWidgetItem *p = new QTableWidgetItem(QString(from));
    ui -> table -> setItem(row - 1, 0, p);
    p = new QTableWidgetItem(QString("goes to"));
    ui -> table -> setItem(row - 1, 1, p);
    p = new QTableWidgetItem(QString(to));
    ui -> table -> setItem(row - 1, 2, p);
    row++;
}

void MainWindow::on_startButton_clicked() {

    start(hanoi_towers -> n, 'A', 'B', 'C');

}


void MainWindow::on_spinBox_valueChanged(int arg1)
{
    hanoi_towers -> changeNumberOfRings(arg1);
}
