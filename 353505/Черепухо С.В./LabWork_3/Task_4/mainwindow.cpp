#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::hanoi(int count, int from, int to, int temp)
{
    if (count) {
        hanoi(count - 1, from, temp, to);
        print(from, to);
        hanoi(count - 1, temp, to, from);
    }
}

void MainWindow::print(int from, int to)
{
    vect.push_back(QString::number(from) + " -> " + QString::number(to));
}

void MainWindow::on_pushButton_clicked()
{
    ui->textBrowser->clear();
    vect.clear();
    hanoi(ui->input->value(), 1, 3, 2);
    pos = 0;
}

void MainWindow::on_pushButton_next_clicked()
{
    if (pos != vect.size()) {
        ui->textBrowser->append(vect[pos]);
        pos++;
    }
}

void MainWindow::on_pushButton_all_clicked()
{
    ui->textBrowser->clear();
    for (const QString &cur : vect) {
        ui->textBrowser->append(cur);
    }
}
