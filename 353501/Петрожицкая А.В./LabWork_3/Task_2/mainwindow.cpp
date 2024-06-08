#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   // ui->setFixedSize(600, 350);
}

MainWindow::~MainWindow()
{
    delete ui;
}

long long MainWindow::funcAkkerman(long long m, long long n){
    if(m == 0){
        return (n + 1);
    }
    else if(m > 0 && n == 0){
        return MainWindow::funcAkkerman(m - 1, 1);
    }
    else if(m > 0 && n > 0){
        return MainWindow::funcAkkerman(m - 1, MainWindow::funcAkkerman(m,n - 1));
    }
}

void MainWindow::on_pushButton_clicked()
{
    ui->label_5->setText(QString::number(MainWindow::funcAkkerman(ui->spinBox->value(), ui->spinBox_2->value())));
}

