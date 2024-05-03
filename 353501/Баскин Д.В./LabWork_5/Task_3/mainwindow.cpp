#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    set = new BitSet(186);
    ui->lineEdit->setText(set->to_string());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_all_clicked()
{
    ui->textBrowser->setText(QString(set->all() ? "true" : "false"));
}

void MainWindow::on_pushButton_any_clicked()
{
    ui->textBrowser->setText(QString(set->any() ? "true" : "false"));
}

void MainWindow::on_pushButton_none_clicked()
{
    ui->textBrowser->setText(QString(set->none() ? "true" : "false"));
}

void MainWindow::on_pushButton_count_clicked()
{
    ui->textBrowser->setText(QString::number(set->count()));
}

void MainWindow::on_pushButton_getsize_clicked()
{
    ui->textBrowser->setText(QString::number(set->getSize()));
}

void MainWindow::on_pushButton_test_clicked()
{
    ui->textBrowser->setText(QString::number(set->test(ui->spinBox->value())));
    ui->lineEdit->setText(set->to_string());
}

void MainWindow::on_pushButton_reset_clicked()
{
    if (ui->checkBox->isChecked())
    {
        set->reset(ui->spinBox->value());
    }
    else
    {
        set->reset();
    }
    ui->textBrowser->setText("");
    ui->lineEdit->setText(set->to_string());
}


void MainWindow::on_pushButton_set_clicked()
{
    if (ui->checkBox->isChecked())
    {
        set->set(ui->spinBox->value());
    }
    else
    {
        set->set();
    }
    ui->textBrowser->setText("");
    ui->lineEdit->setText(set->to_string());
}

void MainWindow::on_pushButton_flip_clicked()
{
    if (ui->checkBox->isChecked())
    {
        set->flip(ui->spinBox->value());
    }
    else
    {
        set->flip();
    }
    ui->textBrowser->setText("");
    ui->lineEdit->setText(set->to_string());
}

void MainWindow::on_pushButton_ul_clicked()
{
    ui->textBrowser->setText(QString::number(set->to_ulong()));
}

void MainWindow::on_pushButton_ull_clicked()
{
    ui->textBrowser->setText(QString::number(set->to_ullong()));
}
