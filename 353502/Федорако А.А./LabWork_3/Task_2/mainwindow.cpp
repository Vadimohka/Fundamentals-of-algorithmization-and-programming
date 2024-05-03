#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->spinBox->setRange(0, 3);
    ui->spinBox_2->setRange(0, 12);

}

MainWindow::~MainWindow()
{
    delete ui;

}


void MainWindow::on_pushButton_clicked()
{
    int numberFirst = ui->spinBox->value();
    int numberSecond = ui->spinBox_2->value();
    ui->label_2->setText(QString::number(solution->functionAckerman(numberFirst, numberSecond)));

}

