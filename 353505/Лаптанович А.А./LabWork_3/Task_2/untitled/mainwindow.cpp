#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->lable_ans->setStyleSheet("background-color: white;"
                                 "color : black;");

    connect(ui->resButton, &QPushButton::clicked, this, &MainWindow::click);

}

MainWindow::~MainWindow()
{
    delete ui;
}

long double MainWindow::A(long double m, long double n){
    if (m == 0){
        return n+1;
    }
    else if (m > 0 && n == 0){
        return A(m-1, 1);
    }
    else if (m > 0 && n > 0){
        return A(m-1, A(m, n-1));
    }
}

void MainWindow::click(){
    double ans = A(ui->spinBox_1->value(), ui->spinBox_2->value());
    ui->lable_ans->setText(QString::number(ans));
}
