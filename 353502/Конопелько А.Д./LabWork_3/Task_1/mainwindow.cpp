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

void MainWindow::on_pushButton_clicked()
{
    sAnsInt = "";
    sAnsDbl = "";
    numb = ui -> doubleSpinBox->value();
    QString strAdd = "";
    if(numb < 0)
        strAdd = "-";
    numb = abs(numb);
    accuracy = ui -> spinBox -> value();
    ui -> lineEdit_2 -> setText(strAdd + funcAns(numb, accuracy));
}

QString MainWindow::funcAns(double num, int acc)
{
    int intPrt = (int)num;
    double dblPrt = num - intPrt;
    findIntPart(intPrt, sAnsInt);
    findDblPart(dblPrt, acc, sAnsDbl);
    std::reverse(sAnsInt.begin(), sAnsInt.end());
    if(abs(dblPrt) <= 1e-6 || acc == 0){
        return (sAnsInt);
    }
    return(sAnsInt + "," + sAnsDbl);
}

void MainWindow::findIntPart(int num, QString& sAnsInt)
{
    if(num / 2 == 0){
        sAnsInt.push_back((num % 2) + '0');
        return;
    }
    else{
        sAnsInt.push_back((num % 2) + '0');
        findIntPart(num / 2, sAnsInt);
    }
}

void MainWindow::findDblPart(double num, const int& acc, QString& sAnsDbl)
{
    if(sAnsDbl.size() >= acc){
        return;
    }
    else{
        sAnsDbl.push_back(((int)(num * 2)) + '0');
        findDblPart(num * 2 - (int)(num * 2), acc, sAnsDbl);
    }
}

