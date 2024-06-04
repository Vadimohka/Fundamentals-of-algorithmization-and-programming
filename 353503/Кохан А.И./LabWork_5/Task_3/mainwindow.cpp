#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , bitset(new BitSet(8, 5))
{
    ui->setupUi(this);
    qDebug() << bitset->to_string();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_all_clicked()
{
    ui->textBrowser->setText(QString(bitset->all() ? "true" : "false"));
}

void MainWindow::on_pushButton_any_clicked()
{
    ui->textBrowser->setText(QString(bitset->any() ? "true" : "false"));
}

void MainWindow::on_pushButton_none_clicked()
{
    ui->textBrowser->setText(QString(bitset->none() ? "true" : "false"));
}

void MainWindow::on_pushButton_count_clicked()
{
    ui->textBrowser->setText(QString::number(bitset->count()));
}

void MainWindow::on_pushButton_getsize_clicked()
{
    ui->textBrowser->setText(QString::number(bitset->getSize()));
}

void MainWindow::on_pushButton_test_clicked()
{
    ui->lineEdit->setText(bitset->to_string());
}

void MainWindow::on_pushButton_reset_clicked()
{
    bitset->reset();
    ui->textBrowser->setText("");
    ui->lineEdit->setText(bitset->to_string());
}

void MainWindow::on_pushButton_set_clicked()
{
    bitset->set();
    ui->textBrowser->setText("");
    ui->lineEdit->setText(bitset->to_string());
}

void MainWindow::on_pushButton_flip_clicked()
{
    bitset->flip();
    ui->textBrowser->setText("");
    ui->lineEdit->setText(bitset->to_string());
}

void MainWindow::on_pushButton_ul_clicked()
{
    ui->textBrowser->setText(QString::number(bitset->to_ulong()));
}

void MainWindow::on_pushButton_ull_clicked()
{
    ui->textBrowser->setText(QString::number(bitset->to_ullong()));
}
