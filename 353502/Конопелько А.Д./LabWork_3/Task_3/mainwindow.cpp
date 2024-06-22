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


void MainWindow::func(int n)
{
    if(n == 0)
        return;
    ans *= 10;
    ans += n % 10;
    func(n / 10);
}


void MainWindow::on_spinBox_editingFinished()
{
    ans = 0;
    int n = ui->spinBox->value();
    if(n % 10 == 0){
        ui -> lineEdit -> setText("Zero at the end!");
    }
    else{
        func(n);
        ui->lineEdit->setText(QString::number(ans));
    }
}


