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

void MainWindow::on_transformButton_clicked()
{
    number = ui->lineEdit->text();
    znachenie = number.toDouble();
    wholePart = znachenie;
    fraction = znachenie - wholePart;
    number = "";
    ///number = translateWhole(wholePart);
    translateWhole(wholePart);
    number.append(",");
    translateFraction(2 * fraction);
    /*for (int i = 0; i < perevod.size(); ++i) {
        number.push_back(QString::number(perevod[i]));
    }*/
    ui->otvetLabel->setText(number);
}

void MainWindow::translateWhole(int whole)
{
    if (whole == 0)
        return;
    number = (QString::number(whole % 2)) + number;
    translateWhole(whole / 2);
    return;
}

void MainWindow::translateFraction(double fraction)
{
    if (fraction >= 1) {
        number += "1";
        return;
    }
    number += "0";
    translateFraction(fraction * 2);
    return;
}
