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

unsigned long long MainWindow::func(int m, int n){
    if (m == 0)
        return n + 1;
    else if (n == 0)
        return func(m - 1, 1);
    else
        return func(m - 1, func(m, n - 1));
}

void MainWindow::on_pushButton_clicked()
{
    QCoreApplication::processEvents();
    unsigned long long ans = func(ui->spinBox->value(), ui->spinBox_2->value());
    ui->ans->setText(QString::number(ans));
}
