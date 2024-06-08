#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrintDialog>
#include <QMessageBox>>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->userInputFrame->hide();
    ui->printBut->hide();
    initWithCode();
    initWithPtr();
    initWithRef();
    initWithString();
}

MainWindow::~MainWindow()
{
    delete ui;
}

QString MainWindow::makeStringFromWatch(WristWatch watch)
{
    QString str = QString(watch.model)  + "|" + (watch.isWhaterProof ? "true" : "false") + "|"
                  + QString::number(watch.price) + "|" + QString::number(watch.hour) + "|"
                  + QString::number(watch.minutes[0]) + QString::number(watch.minutes[1]) + "|"
                  + watch.partOfDay[0] + watch.partOfDay[1];
    return str;
}

void MainWindow::initWithString()
{
    stringInitWatch = {'M',true,2384234.234,5,{2,0},{'P','M'}};
    QString str = makeStringFromWatch(stringInitWatch);
    ui->stringInitLine->setText(str);
}

void MainWindow::initWithCode()
{
    codeInitWatch.model = 'L';
    codeInitWatch.isWhaterProof = false;
    codeInitWatch.price = 2387.123;
    codeInitWatch.hour = 3;
    codeInitWatch.minutes[0] = 4;
    codeInitWatch.minutes[1] = 5;
    codeInitWatch.partOfDay[0] = 'A';
    codeInitWatch.partOfDay[1] = 'M';
    QString str = makeStringFromWatch(codeInitWatch);
    ui->codeInitLine->setText(str);
}

void MainWindow::initWithPtr()
{
    ptr->model = 'I';
    ptr->isWhaterProof = false;
    ptr->price = 214187.5423;
    ptr->hour = 4;
    ptr->minutes[0] = 3;
    ptr->minutes[1] = 7;
    ptr->partOfDay[0] = 'A';
    ptr->partOfDay[1] = 'M';
    QString str = makeStringFromWatch(ptrInitWatch);
    ui->pointerInitLine->setText(str);
}

void MainWindow::initWithRef()
{
    ref.model = 'G';
    ref.isWhaterProof = false;
    ref.price = 239667.78903;
    ref.hour = 8;
    ref.minutes[0] = 1;
    ref.minutes[1] = 3;
    ref.partOfDay[0] = 'P';
    ref.partOfDay[1] = 'M';
    QString str = makeStringFromWatch(refInitWatch);
    ui->referenceInitLine->setText(str);
}

void MainWindow::on_printBut_clicked()
{
    QPrinter printer;
    QPrintDialog printDialog(&printer, this);
    printDialog.setWindowTitle(tr("Print"));
    if (printDialog.exec() != QDialog::Accepted)
    {
        return;
    }

    QTextDocument doc;
    doc.setHtml(ui->userInitBrowser->toHtml());
    doc.print(&printer);
}


void MainWindow::on_userInitBut_clicked()
{
    ui->userInputFrame->show();
}


void MainWindow::on_acceptUserInput_clicked()
{
    userInitWatch.hour = ui->hoursframeinput->value();
    userInitWatch.minutes[0] = ui->minutesframeinput->value() / 10;
    userInitWatch.minutes[1] = ui->minutesframeinput->value() % 10;
    userInitWatch.isWhaterProof = ui->checkBox->isChecked();
    userInitWatch.price = ui->priceframeinput->value();
    QString a = ui->modelframeinput->text();
    userInitWatch.model = a[0];
    QString b = ui->dayPartFrame->text();
    userInitWatch.partOfDay[0] = b[0];
    userInitWatch.partOfDay[1] = b[1];
    if((userInitWatch.partOfDay[0] != 'A' && userInitWatch.partOfDay[1] != 'P') || userInitWatch.partOfDay[1] != 'M'){
        QMessageBox::information(nullptr, tr("Information"), tr("Wrong Input"));
        return;
    }
    if(ui->modelframeinput->text().isEmpty() || ui->dayPartFrame->text().isEmpty()){
        QMessageBox::information(nullptr, tr("Wrong Input"), "None of the fields should be empty", QMessageBox::Ok | QMessageBox::NoButton);
        return;
    }
    ui->userInputFrame->hide();
    QString str = makeStringFromWatch(userInitWatch);
    ui->userInitBrowser->setText(str);
    ui->printBut->show();
}

