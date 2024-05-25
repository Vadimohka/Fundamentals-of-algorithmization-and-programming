#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"
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
    strInit = {1990, 20000.25, 'A', true, {'T', 'i', 'm'}, {2000, 2005, 2007, 2010}};
    QString str = QString::number(strInit.BirthdayYear) + "|" + QString::number(strInit.wage) + "|" + strInit.teamletter + "|" + (strInit.isCoolGuy ? "true" : "false") + "|" + QString(strInit.name) + "|";

    for (int i = 0; i < 4; ++i)
    {
        str += QString::number(strInit.tournametsYear[i]) + (i == 3 ? "" : ", ");
    }
    ui->textBrowser->setText(str);
}

void MainWindow::initWithCode()
{
    codeInit.teamletter = 'B';
    codeInit.wage = 50000;
    codeInit.BirthdayYear = 1999;
    codeInit.isCoolGuy = true;
    char codeInitName[] = "Alex";
    for (int i = 0; i < 7; ++i)
    {
        codeInit.name[i] = codeInitName[i];
    }
    int codeInittournamentsYear[] = {2010,2020,2022,2024};
    for (int i = 0; i < 4; ++i)
    {
        codeInit.tournametsYear[i] = codeInittournamentsYear[i];
    }

    QString str = QString::number(codeInit.BirthdayYear) + "|" + QString::number(codeInit.wage) + "|" + codeInit.teamletter + "|" + (codeInit.isCoolGuy ? "true" : "false") + "|" + QString(codeInit.name) + "|";
    for (int i = 0; i < 4; ++i)
    {
        str += QString::number(codeInit.tournametsYear[i]) + (i == 3 ? "" : ", ");
    }
    ui->textBrowser_2->setText(str);
}

void MainWindow::initWithPtr()
{
    ptr->teamletter = 'C';
    ptr->wage = 1000300.5;
    ptr->BirthdayYear = 1979;
    ptr->isCoolGuy = false;
    char ptrInitName[] = "Jorji";
    for (int i = 0; i < 8; ++i)
    {
        ptr->name[i] = ptrInitName[i];
    }
    int ptrInittournamentsYear[] = {1989,1999,2015,2017};
    for (int i = 0; i < 4; ++i)
    {
        ptr->tournametsYear[i] = ptrInittournamentsYear[i];
    }

    QString str = QString::number(ptr->BirthdayYear) + "|" + QString::number(ptr->wage) + "|" + ptr->teamletter + "|" + (ptr->isCoolGuy ? "true" : "false") + "|" + QString(ptr->name) + "|";
    for (int i = 0; i < 4; ++i)
    {
        str += QString::number(ptr->tournametsYear[i]) + (i == 3 ? "" : ", ");
    }

    ui->textBrowser_3->setText(str);
}

void MainWindow::initWithRef()
{
    ref.teamletter = 'D';
    ref.wage = 230040.2675;
    ref.BirthdayYear = 2000;
    ref.isCoolGuy = true;
    char refInitName[] = "Vadim";
    for (int i = 0; i < 8; ++i)
    {
        ref.name[i] = refInitName[i];
    }
    int refInittournamentsYear[] = {2014,2019,2021,2023};
    for (int i = 0; i < 4; ++i)
    {
        ref.tournametsYear[i] = refInittournamentsYear[i];
    }

    QString str = QString::number(ref.BirthdayYear) + "|" + QString::number(ref.wage) + "|" + ref.teamletter + "|" + (ref.isCoolGuy ? "true" : "false") + "|" + QString(ref.name)+ "|";
    for (int i = 0; i < 4; ++i)
    {
        str += QString::number(ref.tournametsYear[i]) + (i == 3 ? "" : ", ");
    }
    ui->textBrowser_4->setText(str);
}

void MainWindow::initUserInput(Sportik userInit)
{
    QString str = QString::number(userInit.BirthdayYear) + "|" + QString::number(userInit.wage) + "|" + userInit.teamletter + "|" + (userInit.isCoolGuy ? "true" : "false") + "|" + QString(userInit.name) + "|";
    for (int i = 0; i < 4; ++i)
    {
        str += QString::number(userInit.tournametsYear[i]) + (i == 3 ? "" : ", ");
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
    QPrinter printer(QPrinter::HighResolution);
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
