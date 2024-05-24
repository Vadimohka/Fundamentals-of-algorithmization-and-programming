#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->calculate, &QPushButton::clicked, this, &MainWindow::calculateAckermann);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::calculateAckermann()
{
    int m = ui->enter_m->value();
    int n = ui->enter_n->value();
    int result = ackermann(m, n);
    ui->answer->setText(QString::number(result));
}

int MainWindow::ackermann(int m, int n)
{
    if (m == 0)
        return n + 1;
    else if (m > 0 && n == 0)
        return ackermann(m - 1, 1);
    else
        return ackermann(m - 1, ackermann(m, n - 1));
}
