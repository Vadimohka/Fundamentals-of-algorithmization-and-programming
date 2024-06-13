#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEditA->setReadOnly(true);
    ui->lineEditB->setReadOnly(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButtonAddDigit_clicked()
{
    ui->lineEditA->setReadOnly(false);
    vector.push_back(ui->spinBoxCoord->value());
    vecA += QString::number(ui->spinBoxCoord->value()) + ", ";
    ui->lineEditA->setText(vecA);
    ui->lineEditA->setReadOnly(true);
}


void MainWindow::on_pushButtonCalc_clicked()
{
    vecA.chop(2);
    vecA += ")";
    ui->lineEditA->setReadOnly(false);
    ui->lineEditA->setText(vecA);
    ui->lineEditA->setReadOnly(true);
    int arr[3];
    for(int i = 0; i < vector.size(); i++){
        arr[i%3] = vector.at(i);
        if(i % 3 == 2){
            if(arr[0] > arr[1]){
                qSwap(arr[0], arr[1]);
            }
            if(arr[1] > arr[2]){
                qSwap(arr[1], arr[2]);
            }
            vecB += QString::number((arr[0] + arr[1])/2) + ", ";
        }
        else if(i == vector.size() - 1){
            if(i%3 == 1){
                vecB += QString::number((arr[0] + arr[1])/2) + ", ";
            }
            else{
                vecB += QString::number(arr[0]) + ", ";
            }
        }
    }
    vecB.chop(2);
    vecB += ")";
    ui->lineEditB->setReadOnly(false);
    ui->lineEditB->setText(vecB);
    ui->lineEditB->setReadOnly(true);
}

void MainWindow::on_pushButtonClear_clicked()
{

    ui->lineEditA->setReadOnly(false);
    ui->lineEditA->setText("");
    ui->lineEditA->setReadOnly(true);
    ui->lineEditB->setReadOnly(false);
    ui->lineEditB->setText("");
    ui->lineEditB->setReadOnly(true);
    vecA = "(";
    vecB = "(";
    vector.clear();
}

