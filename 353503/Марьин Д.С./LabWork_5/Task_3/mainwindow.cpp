#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLineEdit>

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

void MainWindow::setStat()
{
    ui->sizeLbl->clear();
    ui->sizeLbl->setNum(int(bit.size()));
    ui->anyLbl->clear();
    ui->anyLbl->setText(bit.any() ? "true" : "false");
    ui->allLbl->clear();
    ui->allLbl->setText(bit.all() ? "true" : "false");
    ui->noneLbl->clear();
    ui->noneLbl->setText(bit.none() ? "true" : "false");
    ui->toullongLbl->clear();
    size_t n = bit.to_ullong();
    ui->toullongLbl->setText(QString::number(n));
    ui->countLbl->clear();
    ui->countLbl->setText(QString::number(bit.count()));
}

void MainWindow::on_flipBtn_clicked()
{
    bit.flip();
    setStat();
}


void MainWindow::on_setBtn_clicked()
{
    int index = ui->indexSbox->value();
    bit.set(index,1);
     setStat();
}


void MainWindow::on_resetBtn_clicked()
{
    bit.reset();
     setStat();
}


void MainWindow::on_testBtn_clicked()
{
    bit.test(ui->indexSbox->value());
     setStat();
}

