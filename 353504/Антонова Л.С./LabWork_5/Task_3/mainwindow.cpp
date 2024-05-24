#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    bitset = new Bitset<15>();
    ui->lineEdit->setText(bitset->toString());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_all_clicked()
{
    ui->label_ans->setText("all: " + QString(bitset->all() ? "true" : "false"));
    ui->lineEdit->setText(bitset->toString());
}


void MainWindow::on_pushButton_any_clicked()
{
    ui->label_ans->setText("any: " + QString(bitset->any() ? "true" : "false"));
    ui->lineEdit->setText(bitset->toString());
}


void MainWindow::on_pushButton_count_clicked()
{
    ui->label_ans->setText("count: " + QString(QString::number(bitset->count())));
    ui->lineEdit->setText(bitset->toString());
}


void MainWindow::on_pushButton_none_clicked()
{
    ui->label_ans->setText("none: " + QString(bitset->none() ? "true" : "false"));
    ui->lineEdit->setText(bitset->toString());
}


void MainWindow::on_pushButton_reset_clicked()
{
    bitset->reset();
    ui->lineEdit->setText(bitset->toString());
}


void MainWindow::on_pushButton_set_clicked()
{
    bitset->set();
    ui->lineEdit->setText(bitset->toString());
}


void MainWindow::on_pushButton_getSize_clicked()
{
    ui->label_ans->setText("size: " + (QString::number(bitset->getsize())));
    ui->lineEdit->setText(bitset->toString());
}


void MainWindow::on_pushButton_ullong_clicked()
{
    ui->label_ans->setText("ullog: " + (QString::number(bitset->to_ullong())));
    ui->lineEdit->setText(bitset->toString());
}


void MainWindow::on_pushButton_ulong_clicked()
{
    ui->label_ans->setText("ulog: " + QString::number(bitset->to_ulong()));
    ui->lineEdit->setText(bitset->toString());
}


void MainWindow::on_pushButton_flip_clicked()
{
    bitset->flip();
    ui->lineEdit->setText(bitset->toString());
}


void MainWindow::on_pushButton_flipArg_clicked()
{
    bitset->flip(ui->spinBox_flip->value());
    ui->lineEdit->setText(bitset->toString());
}


void MainWindow::on_pushButton_setArg_clicked()
{
    bitset->set(ui->spinBox_set->value());
    ui->lineEdit->setText(bitset->toString());
}


void MainWindow::on_pushButton_resetArg_clicked()
{
    bitset->reset(ui->spinBox_reset->value());
    ui->lineEdit->setText(bitset->toString());
}


void MainWindow::on_pushButton_testArg_clicked()
{
    ui->label_ans->setText("test: " + QString::number(bitset->test(ui->spinBox_test->value())));
    ui->lineEdit->setText(bitset->toString());
}
