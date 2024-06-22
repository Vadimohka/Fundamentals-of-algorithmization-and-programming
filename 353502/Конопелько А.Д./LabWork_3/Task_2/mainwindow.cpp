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

int MainWindow::funcA(int m, int n)
{
    if(m == 0)
        return (n + 1);
    if(n == 0)
        return funcA(m - 1, 1);
    int transA = funcA(m, n - 1);
    return funcA(m - 1, transA);
}

void MainWindow::on_pushButton_clicked()
{
    m = ui->spinBox->value();
    n = ui->spinBox_2->value();
    ui->lineEdit_3->setText(QString::number(funcA(m, n)));
}

