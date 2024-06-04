#include "mainwindow.h"
#include "./ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    s = *(new SomeString("a"));
    ui->label->setText(s.c_str());
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
     ui->label->setText((char *)SomeString::SomeMemcpy(ui->label->text().toUtf8().data(),  ui->label_2->text().toUtf8().data(), 10));
}




void MainWindow::on_pushButton_3_clicked()
{
    ui->label->setText((char *)SomeString::SomeStrcpy(ui->label->text().toUtf8().data(),  ui->label_2->text().toUtf8().data()));
}


void MainWindow::on_pushButton_4_clicked()
{
    ui->label->setText((char *)SomeString::SomeStrncpy(ui->label->text().toUtf8().data(),  ui->label_2->text().toUtf8().data(), 10));
}


void MainWindow::on_pushButton_5_clicked()
{
     ui->label->setText((char *)SomeString::SomeStrcat(ui->label->text().toUtf8().data(),  ui->label_2->text().toUtf8().data()));
}


void MainWindow::on_pushButton_6_clicked()
{
    ui->label->setText((char *)SomeString::SomeStrncat(ui->label->text().toUtf8().data(),  ui->label_2->text().toUtf8().data(), 10));
}


void MainWindow::on_pushButton_7_clicked()
{
    ui->label->setText(QString::number((SomeString::SomeMemcmp(ui->label->text().toUtf8().data(),  ui->label_2->text().toUtf8().data(), 10))));
}


void MainWindow::on_pushButton_8_clicked()
{
     ui->label->setText(QString::number((SomeString::SomeStrcmp(ui->label->text().toUtf8().data(),  ui->label_2->text().toUtf8().data()))));
}


void MainWindow::on_pushButton_9_clicked()
{
    ui->label->setText(QString::number((SomeString::SomeStrcoll(ui->label->text().toUtf8().data(),  ui->label_2->text().toUtf8().data()))));
}


void MainWindow::on_pushButton_10_clicked()
{
 ui->label->setText(QString::number((SomeString::SomeStrncmp(ui->label->text().toUtf8().data(),  ui->label_2->text().toUtf8().data(), 10))));
}


void MainWindow::on_pushButton_11_clicked()
{
    ui->label->setText(QString::number((SomeString::SomeStrxfrm(ui->label->text().toUtf8().data(),  ui->label_2->text().toUtf8().data(), 10))));
}



void MainWindow::on_pushButton_13_clicked()
{
    ui->label->setText((char*)SomeString::SomeMemset(ui->label->text().toUtf8().data(),  ui->label_2->text().front().toLatin1(), 10));
}



void MainWindow::on_pushButton_14_clicked()
{
 ui->label->setText(QString::number((SomeString::SomeStrlen(ui->label->text().toUtf8().data()))));
}

