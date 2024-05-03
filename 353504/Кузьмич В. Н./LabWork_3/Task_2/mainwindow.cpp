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

unsigned long long MainWindow::A(int m, int n){
if (m == 0) return n + 1;
else if (n == 0) return A(m - 1, 1);
else return A(m - 1, A(m, n - 1));
}

void MainWindow::on_pushButton_clicked()
{
    int m = ui -> spinBox_2 -> value(), n = ui -> spinBox -> value();
    ui -> label_4 -> setText(QString::number(A(m, n)));
}

