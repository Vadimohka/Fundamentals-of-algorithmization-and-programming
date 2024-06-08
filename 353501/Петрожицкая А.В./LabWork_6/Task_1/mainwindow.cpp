#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cstring>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    QString str2;
    QString str1;
    ui->setupUi(this);
    long long values[] = {600, 500, 900, 200, 700};
    airport1.terminals = 3;
    airport1.area = 5000.75;
    airport1.code = 'A';
    airport1.hasParking = true;
    strcpy(airport1.managementOfficeAddress, "ул. Центральная, 100");
    for (int i = 0; i < airport1.MAX_LONG_LONG_ARRAY_SIZE; i++){
        airport1.passengerCount[i] = values[i];
        str2 += QString::number(values[i]);
        str2 += " ";
    }
    str1 = airport1.hasParking == true ? "true" : "false";
    ui->lineEdit->setText(QString::number(airport1.terminals) + '|' + QString::number(airport1.area) + '|' + airport1.code + '|' + str1 + '|' + "ул. Центральная, 100" + '|' + str2);
    str2 = "";
    air3->terminals = 6;
    air3->area = 6800.75;
    air3->code = 'C';
    air3->hasParking = false;
    strcpy(air3->managementOfficeAddress, "ул. Центральная, 100");
    for (int i = 0; i < airport1.MAX_LONG_LONG_ARRAY_SIZE; i++){
        air3->passengerCount[i] = values[i];
        str2 += QString::number(values[i]);
        str2 += " ";
    }
    str1 = air3->hasParking == true ? "true" : "false";
    ui->lineEdit_3->setText(QString::number(air3->terminals) + '|' + QString::number(air3->area) + '|' + air3->code + '|' + str1 + '|' + "ул. Центральная, 100" + '|' + str2);
    str2 = "";
    air3->terminals = 2;
    air4.terminals = 3;
    air4.area = 3240.25;
    air4.code = 'B';
    air4.hasParking = false;
    strcpy(air4.managementOfficeAddress, "ул. Центральная, 100");
    for (int i = 0; i < airport1.MAX_LONG_LONG_ARRAY_SIZE; i++){
        air4.passengerCount[i] = values[i];
        str2 += QString::number(values[i]);
        str2 += " ";
    }
    str1 = air4.hasParking == true ? "true" : "false";
    ui->lineEdit_4->setText(QString::number(air4.terminals) + '|' + QString::number(air4.area) + '|' + air4.code + '|' + str1 + '|' + "ул. Центральная, 100" + '|' + str2);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    close();
}


void MainWindow::on_pushButton_2_clicked()
{
    airport2.terminals = ui->spinBox->value();
    airport2.area = ui->spinBox_2->value();
    QString textFromLineEdit = ui->lineEdit_5->text();
    airport2.code = textFromLineEdit[0].toLatin1();
    QString str, str1;
    if (isParking) airport2.hasParking = true;
    else airport2.hasParking = false;
    QString adres = ui -> lineEdit_6 -> text();
    strcpy(air3->managementOfficeAddress, adres.toLatin1());
    airport2.passengerCount[0] = ui -> spinBox_2 -> value();
    airport2.passengerCount[1] = ui -> spinBox_3 -> value();
    airport2.passengerCount[2] = ui -> spinBox_4 -> value();
    airport2.passengerCount[3] = ui -> spinBox_5 -> value();
    airport2.passengerCount[4] = ui -> spinBox_6 -> value();
    str =  QString::number(airport2.passengerCount[0]) + " " + QString::number(airport2.passengerCount[1]) + " " + QString::number(airport2.passengerCount[2]) + " " + QString::number(airport2.passengerCount[3]) + " " + QString::number(airport2.passengerCount[4]);
    str1 = airport2.hasParking == true ? "true" : "false";
    ui->lineEdit_2->setText(QString::number(airport2.terminals) + '|' + QString::number(airport2.area) + '|' + airport2.code + '|' + str1 + '|' + adres.toLatin1() + '|' + str);
    str = "";
}


void MainWindow::on_comboBox_activated(int index)
{
    if (index == 0){
        isParking = false;
    }
    else{
        isParking = true;
    }
}

