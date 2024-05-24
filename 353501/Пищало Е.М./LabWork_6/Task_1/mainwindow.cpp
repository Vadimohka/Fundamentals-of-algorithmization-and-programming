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
    strInit = {2007, 20000.25, 'S', true, {'s', 'h', 'i', 'p'}, {12, 0, 0, 0}};

    QString str = QString::number(strInit.year) + "|" + QString::number(strInit.cost) + "|" + strInit.generation + "|" + (strInit.isAvailable ? "true" : "false") + "|" + QString(strInit.name) + "|";

    for (int i = 0; i < 4; ++i)
    {
        str += QString::number(strInit.passengersPerLevel[i]) + (i == 3 ? "" : ", ");
    }
    ui->textBrowser->setText(str);
}

void MainWindow::initWithCode()
{
    codeInit.generation = 'V';
    codeInit.cost = 5000000;
    codeInit.year = 2021;
    codeInit.isAvailable = true;
    char codeInitName[] = "Yacht";
    for (int i = 0; i < 7; ++i)
    {
        codeInit.name[i] = codeInitName[i];
    }

    int codeInitwheelsYear[] = {3,0,0,0};
    for (int i = 0; i < 4; ++i)
    {
        codeInit.passengersPerLevel[i] = codeInitwheelsYear[i];
    }

    QString str = QString::number(codeInit.year) + "|" + QString::number(codeInit.cost) + "|" + codeInit.generation + "|" + (codeInit.isAvailable ? "true" : "false") + "|" + QString(codeInit.name) + "|";
    for (int i = 0; i < 4; ++i)
    {
        str += QString::number(codeInit.passengersPerLevel[i]) + (i == 3 ? "" : ", ");
    }
    ui->textBrowser_2->setText(str);
}

void MainWindow::initWithPtr()
{
    ptr->generation = 'P';
    ptr->cost = 1000300.5;
    ptr->year = 1980;
    ptr->isAvailable = false;
    char ptrInitName[] = "Ptr ship";
    for (int i = 0; i < 8; ++i)
    {
        ptr->name[i] = ptrInitName[i];
    }
    int ptrInitwheelsYear[] = {100,78,123,120};
    for (int i = 0; i < 4; ++i)
    {
        ptr->passengersPerLevel[i] = ptrInitwheelsYear[i];
    }

    QString str = QString::number(ptr->year) + "|" + QString::number(ptr->cost) + "|" + ptr->generation + "|" + (ptr->isAvailable ? "true" : "false") + "|" + QString(ptr->name) + "|";
    for (int i = 0; i < 4; ++i)
    {
        str += QString::number(ptr->passengersPerLevel[i]) + (i == 3 ? "" : ", ");
    }
    ui->textBrowser_3->setText(str);
}

void MainWindow::initWithRef()
{
    ref.generation = 'R';
    ref.cost = 230040.2675;
    ref.year = 1970;
    ref.isAvailable = true;
    char refInitName[] = "Ref ship";
    for (int i = 0; i < 8; ++i)
    {
        ref.name[i] = refInitName[i];
    }
    int refInitwheelsYear[] = {123,123,123,123};
    for (int i = 0; i < 4; ++i)
    {
        ref.passengersPerLevel[i] = refInitwheelsYear[i];
    }

    QString str = QString::number(ref.year) + "|" + QString::number(ref.cost) + "|" + ref.generation + "|" + (ref.isAvailable ? "true" : "false") + "|" + QString(ref.name)+ "|";
    for (int i = 0; i < 4; ++i)
    {
        str += QString::number(ref.passengersPerLevel[i]) + (i == 3 ? "" : ", ");
    }
    ui->textBrowser_4->setText(str);
}

void MainWindow::initUserInput(Ship userInit)
{
    QString str = QString::number(userInit.year) + "|" + QString::number(userInit.cost) + "|" + userInit.generation + "|" + (userInit.isAvailable ? "true" : "false") + "|" + QString(userInit.name) + "|";
    for (int i = 0; i < 4; ++i)
    {
        str += QString::number(userInit.passengersPerLevel[i]) + (i == 3 ? "" : ", ");
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
