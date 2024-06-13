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

void MainWindow::initWithStr()
{
    strInit = {1999, 20000.25, 'S', true, {'C', 'a', 'r'}, {1910, 1911, 1911, 1910}};
    QString str = QString::number(strInit.year) + "|" + QString::number(strInit.cost) + "|" + strInit.model + "|" + (strInit.isPassengerCar ? "true" : "false") + "|" + QString(strInit.name) + "|";

    for (int i = 0; i < 4; ++i)
    {
        str += QString::number(strInit.wheelsYear[i]) + (i == 3 ? "" : ", ");
    }
    ui->textBrowser->setText(str);
}

void MainWindow::initWithCode()
{
    codeInit.model = 'W';
    codeInit.cost = 50000;
    codeInit.year = 1913;
    codeInit.isPassengerCar = true;
    char codeInitName[] = "CodeCar";
    for (int i = 0; i < 7; ++i)
    {
        codeInit.name[i] = codeInitName[i];
    }
    int codeInitwheelsYear[] = {1914,1914,1914,1914};
    for (int i = 0; i < 4; ++i)
    {
        codeInit.wheelsYear[i] = codeInitwheelsYear[i];
    }

    QString str = QString::number(codeInit.year) + "|" + QString::number(codeInit.cost) + "|" + codeInit.model + "|" + (codeInit.isPassengerCar ? "true" : "false") + "|" + QString(codeInit.name) + "|";
    for (int i = 0; i < 4; ++i)
    {
        str += QString::number(codeInit.wheelsYear[i]) + (i == 3 ? "" : ", ");
    }
    ui->textBrowser_2->setText(str);
}

void MainWindow::initWithPtr()
{
    ptr->model = 'P';
    ptr->cost = 100.5;
    ptr->year = 1924;
    ptr->isPassengerCar = false;
    char ptrInitName[] = "Ptr Car";
    for (int i = 0; i < 8; ++i)
    {
        ptr->name[i] = ptrInitName[i];
    }
    int ptrInitwheelsYear[] = {1924,1925,1925,1925};
    for (int i = 0; i < 4; ++i)
    {
        ptr->wheelsYear[i] = ptrInitwheelsYear[i];
    }

    QString str = QString::number(ptr->year) + "|" + QString::number(ptr->cost) + "|" + ptr->model + "|" + (ptr->isPassengerCar ? "true" : "false") + "|" + QString(ptr->name) + "|";
    for (int i = 0; i < 4; ++i)
    {;
        str += QString::number(ptr->wheelsYear[i]) + (i == 3 ? "" : ", ");
    }
    ui->textBrowser_3->setText(str);
}

void MainWindow::initWithRef()
{
    ref.model = 'R';
    ref.cost = 230040.2675;
    ref.year = 1920;
    ref.isPassengerCar = true;
    char refInitName[] = "Ref Car";
    for (int i = 0; i < 8; ++i)
    {
        ref.name[i] = refInitName[i];
    }
    int refInitwheelsYear[] = {1922,1923,1922,1920};
    for (int i = 0; i < 4; ++i)
    {
        ref.wheelsYear[i] = refInitwheelsYear[i];
    }

    QString str = QString::number(ref.year) + "|" + QString::number(ref.cost) + "|" + ref.model + "|" + (ref.isPassengerCar ? "true" : "false") + "|" + QString(ref.name)+ "|";
    for (int i = 0; i < 4; ++i)
    {
        str += QString::number(ref.wheelsYear[i]) + (i == 3 ? "" : ", ");
    }
    ui->textBrowser_4->setText(str);
}

void MainWindow::initUserInput(Auto userInit)
{
    QString str = QString::number(userInit.year) + "|" + QString::number(userInit.cost) + "|" + userInit.model + "|" + (userInit.isPassengerCar ? "true" : "false") + "|" + QString(userInit.name) + "|";
    for (int i = 0; i < 4; ++i)
    {
        str += QString::number(userInit.wheelsYear[i]) + (i == 3 ? "" : ", ");
    }
    ui->textBrowser_5->setText(str);
}

void MainWindow::on_pushButton_clicked()
{
    input->setWindowModality(Qt::ApplicationModal);
    input->show();
}


void MainWindow::on_pushButton_print_clicked()
{
    QPrinter printer;
    QPrintDialog printDialog(&printer, this);
    printDialog.setWindowTitle(tr("Print"));
    if (printDialog.exec() != QDialog::Accepted)
    {
        return;
    }

    QTextDocument doc;
    doc.setHtml(ui->textBrowser_5->toHtml());
    doc.print(&printer);
}

