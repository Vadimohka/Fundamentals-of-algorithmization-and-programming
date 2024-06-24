#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "userinputdialog.h"
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrintDialog>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    initWithStr();
    initWithCode();
    initWithPtr();
    initWithRef();

    input = new UserInputDialog();
    connect(input, &UserInputDialog::inputInit, this, &MainWindow::initUserInput);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initWithStr(){
    strInit = {2010, 20000.25, 'V', true, {'C', 'a', 'r'}, {2, 2, 1, 3}};
    QString str = QString::number(strInit.year) + " | " + QString::number(strInit.mileage) + " | " + strInit.model + " | " + (strInit.isPassengerCar ? "is passenger car" : "is not passenger car") + " | " + QString(strInit.name) + " | ";

    for (int i = 0; i < 4; ++i)
    {
        str += QString::number(strInit.tirePressures[i]) + (i == 3 ? "" : ", ");
    }
    ui->textBrowser->setText(str);
}

void MainWindow::initWithCode()
{
    codeInit.model = 'W';
    codeInit.mileage = 50000.34;
    codeInit.year = 2007;
    codeInit.isPassengerCar = true;
    char codeInitName[] = "My Car";
    for (int i = 0; i < 7; ++i)
    {
        codeInit.name[i] = codeInitName[i];
    }
    int codeInitwheelsYear[] = {1,1,2,2};
    for (int i = 0; i < 4; ++i)
    {
        codeInit.tirePressures[i] = codeInitwheelsYear[i];
    }

    QString str = QString::number(codeInit.year) + " | " + QString::number(codeInit.mileage) + "km | " + codeInit.model + " | " + (codeInit.isPassengerCar ? "is passenger car" : "is not passenger car") + " | " + QString(codeInit.name) + " | ";
    for (int i = 0; i < 4; ++i)
    {
        str += QString::number(codeInit.tirePressures[i]) + (i == 3 ? "" : ", ");
    }
    ui->textBrowser_2->setText(str);
}

void MainWindow::initWithPtr()
{
    ptr->model = 'P';
    ptr->mileage = 100300.53;
    ptr->year = 2021;
    ptr->isPassengerCar = false;
    char ptrInitName[] = "Ptr Car";
    for (int i = 0; i < 8; ++i)
    {
        ptr->name[i] = ptrInitName[i];
    }
    int ptrInitwheelsYear[] = {2,2,2,2};
    for (int i = 0; i < 4; ++i)
    {
        ptr->tirePressures[i] = ptrInitwheelsYear[i];
    }

    QString str = QString::number(ptr->year) + " | " + QString::number(ptr->mileage) + "km | " + ptr->model + " | " + (ptr->isPassengerCar ? "is passenger car" : "is not passenger car") + " | " + QString(ptr->name) + " | ";
    for (int i = 0; i < 4; ++i)
    {
        str += QString::number(ptr->tirePressures[i]) + (i == 3 ? "" : ", ");
    }
    ui->textBrowser_3->setText(str);
}

void MainWindow::initWithRef()
{
    ref.model = 'R';
    ref.mileage = 230040.2675;
    ref.year = 2016;
    ref.isPassengerCar = true;
    char refInitName[] = "Ref Car";
    for (int i = 0; i < 8; ++i)
    {
        ref.name[i] = refInitName[i];
    }
    int refInitwheelsYear[] = {3,3,1,2};
    for (int i = 0; i < 4; ++i)
    {
        ref.tirePressures[i] = refInitwheelsYear[i];
    }

    QString str = QString::number(ref.year) + " | " + QString::number(ref.mileage) + "km | " + ref.model + " | " + (ref.isPassengerCar ? "is passenger car" : "is not passenger car") + " | " + QString(ref.name)+ " | ";
    for (int i = 0; i < 4; ++i)
    {
        str += QString::number(ref.tirePressures[i]) + (i == 3 ? "" : ", ");
    }
    ui->textBrowser_4->setText(str);
}

void MainWindow::initUserInput(Car userInit)
{
    QString str = QString::number(userInit.year) + " | " + QString::number(userInit.mileage) + "km | " + userInit.model + " | " + (userInit.isPassengerCar ? "is passenger car" : "is not passenger car") + " | " + QString(userInit.name) + " | ";
    for (int i = 0; i < 4; ++i)
    {
        str += QString::number(userInit.tirePressures[i]) + (i == 3 ? "" : ", ");
    }
    ui->textBrowser_5->setText(str);
}

void MainWindow::on_pushButton_clicked()
{
    input->setWindowModality(Qt::ApplicationModal);
    input->show();
}

