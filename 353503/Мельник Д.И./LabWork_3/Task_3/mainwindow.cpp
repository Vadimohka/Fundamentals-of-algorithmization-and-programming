#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), reverse(new Reverse())
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete reverse;
}

void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    bool isNumber = false;
    int value = arg1.toInt(&isNumber);

    if (isNumber){
        int answer = reverse->reverseNumber(value);
        ui->label->setText(QString::number(answer));
    }
    else{
        ui->label->setText("Введите целочисленное значение");
    }

    if (arg1.isEmpty()){
        ui->label->setText("");
    }
}

