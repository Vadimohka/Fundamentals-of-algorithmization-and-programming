#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , _ui(new Ui::MainWindow), _akerman(new AkermanFunction())
{
    _ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete _ui;
    delete _akerman;
}

/* Установка первого аргумента (m) */
void MainWindow::on_spinBox_valueChanged(int arg1)
{
    _akerman->setFirstArg(arg1);
}

/* Установка второго аргумента (n) */
void MainWindow::on_spinBox_2_valueChanged(int arg1)
{
    _akerman->setSecondArg(arg1);
}


void MainWindow::on_pushButton_clicked()
{
    if (_akerman->getFirstArg() < FIRST_ARG_LIMIT and _akerman->getSecondArg() < SECOND_ARG_LIMIT){
    int answer = _akerman->startCalculation();
    _ui->label_4->setText(QString::number(answer));
    }
    else {
        _ui->label_4->setText("Stak overflow");
    }
}

