#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    hanoi_towers = new hanoi();
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::start(int n, char _start, char _temp, char _finish)
{
    if (n == 1) {
        moveDisk(n, _start, _finish);
    } else {
        start(n - 1, _start, _finish, _temp);
        moveDisk(n, _start, _finish);
        start(n - 1, _temp, _start, _finish);
    }
}


void MainWindow::moveDisk(int number,char _start,char _finish)
{
    ui->table->setRowCount(row);
    QTableWidgetItem *p = new QTableWidgetItem(QString(_start));
    ui->table->setItem(row - 1, 0, p);
    p = new QTableWidgetItem(QString("goes to"));
    ui->table->setItem(row - 1, 1, p);
    p = new QTableWidgetItem(QString(_finish));
    ui->table->setItem(row - 1, 2, p);
    row++;
}

void MainWindow::on_startButton_clicked() {

    start(hanoi_towers->n, 'A', 'B', 'C');

}


void MainWindow::on_spinBox_valueChanged(int arg1)
{
    hanoi_towers->changeNumberOfRings(arg1);
}

