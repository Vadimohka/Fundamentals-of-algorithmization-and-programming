#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mybitset = new MyBitSet(15);
    ui->lineEdit->setText(mybitset->to_string());
}

MainWindow::~MainWindow()
{
    delete ui;
    delete mybitset;
}

void MainWindow::on_bnt_set_clicked()
{
    mybitset->set();
    ui->lineEdit->setText(mybitset->to_string());
}


void MainWindow::on_bnt_size_clicked()
{
    int temp = mybitset->size();
    QMessageBox::information(nullptr, "Размер                   ", QString::number(temp));
    ui->lineEdit->setText(mybitset->to_string());
}


void MainWindow::on_bnt_ulong_clicked()
{
    int temp = mybitset->to_ulong();
    QMessageBox::information(nullptr, "Результат                   ", QString::number(temp));
    ui->lineEdit->setText(mybitset->to_string());
}


void MainWindow::on_bnt_ullong_clicked()
{
    int temp = mybitset->to_ullong();
    QMessageBox::information(nullptr, "Результат                   ", QString::number(temp));
    ui->lineEdit->setText(mybitset->to_string());
}


void MainWindow::on_bnt_none_clicked()
{
    bool isTrue = mybitset->none();
    QMessageBox::information(nullptr, "Результат                   ", QString(isTrue ? "Правда" : "Ложь"));
    ui->lineEdit->setText(mybitset->to_string());
}


void MainWindow::on_bnt_reset_clicked()
{
    mybitset->reset();
    ui->lineEdit->setText(mybitset->to_string());
}


void MainWindow::on_bnt_flip_clicked()
{
    mybitset->flip();
    ui->lineEdit->setText(mybitset->to_string());
}


void MainWindow::on_bnt_count_clicked()
{
    int temp = mybitset->count();
    QMessageBox::information(nullptr, "Результат                   ", QString::number(temp));
    ui->lineEdit->setText(mybitset->to_string());
}


void MainWindow::on_bnt_all_clicked()
{
    bool isTrue = mybitset->all();
    QMessageBox::information(nullptr, "Результат                   ", QString(isTrue ? "Правда" : "Ложь"));
    ui->lineEdit->setText(mybitset->to_string());
}


void MainWindow::on_bnt_any_clicked()
{
    bool isTrue = mybitset->any();
    QMessageBox::information(nullptr, "Результат                   ", QString(isTrue ? "Правда" : "Ложь"));
    ui->lineEdit->setText(mybitset->to_string());
}


void MainWindow::on_bnt_int_flip_clicked()
{
    int temp = ui->spb_flip->value();
    mybitset->flip(temp);
    ui->lineEdit->setText(mybitset->to_string());
}


void MainWindow::on_bnt_int_reset_clicked()
{
    int temp = ui->spb_reset->value();
    mybitset->reset(temp);
    ui->lineEdit->setText(mybitset->to_string());
}


void MainWindow::on_bnt_int_test_clicked()
{
    int temp = ui->spb_test->value();
    QMessageBox::information(nullptr, "Результат                   ", QString::number(mybitset->test(temp)));
    ui->lineEdit->setText(mybitset->to_string());
}


void MainWindow::on_bnt_int_set_clicked()
{
    int temp = ui->spb_set->value();
    mybitset->set(temp);
    ui->lineEdit->setText(mybitset->to_string());
}
