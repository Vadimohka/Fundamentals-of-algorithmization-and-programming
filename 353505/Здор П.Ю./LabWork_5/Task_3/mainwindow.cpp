#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    bs = new bitset(15,10);
    ui->lineEdit->setText(bs->to_string());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    if(bs->all())
    {
        ui->label->setText("true");
    }
     ui->label->setText("false");
    ui->lineEdit->setText(bs->to_string());
}


void MainWindow::on_pushButton_2_clicked()
{
    if(bs->any())
    {
        ui->label->setText("true");
    }
    ui->label->setText("false");
    ui->lineEdit->setText(bs->to_string());
}


void MainWindow::on_pushButton_3_clicked()
{
    ui->label->setText(QString(QString::number(bs->getSize())));
    ui->lineEdit->setText(bs->to_string());
}


void MainWindow::on_pushButton_4_clicked()
{
    bs->flip(1);
    ui->label->setText("");
    ui->lineEdit->setText(bs->to_string());
}


void MainWindow::on_pushButton_5_clicked()
{
    if(bs->none())
    {
        ui->label->setText("true");
    }
    ui->label->setText("false");
    ui->lineEdit->setText(bs->to_string());
}


void MainWindow::on_pushButton_6_clicked()
{

    ui->label->setText("");
    ui->lineEdit->setText(bs->to_string()+"1");
}


void MainWindow::on_pushButton_7_clicked()
{
    bs->set(1);
    ui->label->setText("");
    ui->lineEdit->setText(bs->to_string());
}


void MainWindow::on_pushButton_8_clicked()
{
    ui->label->setText("ans: " + (QString::number(bs->getSize())));
    ui->lineEdit->setText(bs->to_string());
}


void MainWindow::on_pushButton_9_clicked()
{
    ui->label->setText("ans: " + QString::number(bs->test(1)));
    ui->lineEdit->setText(bs->to_string());
}


void MainWindow::on_pushButton_10_clicked()
{
    ui->lineEdit->setText(bs->to_string());
}


void MainWindow::on_pushButton_11_clicked()
{
    ui->lineEdit->setText(QString::number(bs->to_ullong()));
}


void MainWindow::on_pushButton_12_clicked()
{
     ui->lineEdit->setText(QString::number(bs->to_ulong()));
}

