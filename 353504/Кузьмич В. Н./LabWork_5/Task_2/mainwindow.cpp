#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>

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

void MainWindow::on_pushButton_2_clicked()
{
    ui->lineEdit_result->setText((char*)myString::myMemcpy(ui->lineEdit_str1->text().toUtf8().data(),  ui->lineEdit_str2->text().toUtf8().data(), (size_t)ui->spinBox->value()));
}


void MainWindow::on_pushButton_3_clicked()
{
    ui->lineEdit_result->setText((char*)myString::myMemmove(ui->lineEdit_str1->text().toUtf8().data(),  ui->lineEdit_str2->text().toUtf8().data(), (size_t)ui->spinBox->value()));
}


void MainWindow::on_pushButton_7_clicked()
{
    ui->lineEdit_result->setText((char*)myString::myStrcpy(ui->lineEdit_str1->text().toUtf8().data(),  ui->lineEdit_str2->text().toUtf8().data()));
}


void MainWindow::on_pushButton_12_clicked()
{
    ui->lineEdit_result->setText((char*)myString::myStrncpy(ui->lineEdit_str1->text().toUtf8().data(),  ui->lineEdit_str2->text().toUtf8().data(), (size_t)ui->spinBox->value()));
}


void MainWindow::on_pushButton_4_clicked()
{
    ui->lineEdit_result->setText((char*)myString::myStrcat(ui->lineEdit_str1->text().toUtf8().data(),  ui->lineEdit_str2->text().toUtf8().data()));
}


void MainWindow::on_pushButton_10_clicked()
{
    ui->lineEdit_result->setText((char*)myString::myStrncat(ui->lineEdit_str1->text().toUtf8().data(),  ui->lineEdit_str2->text().toUtf8().data(), (size_t)ui->spinBox->value()));
}


void MainWindow::on_pushButton_clicked()
{
    ui->lineEdit_result->setText(QString::number((myString::myMemcmp(ui->lineEdit_str1->text().toUtf8().data(),  ui->lineEdit_str2->text().toUtf8().data(), (size_t)ui->spinBox->value()))));
}


void MainWindow::on_pushButton_5_clicked()
{
    ui->lineEdit_result->setText(QString::number((myString::myStrcmp(ui->lineEdit_str1->text().toUtf8().data(),  ui->lineEdit_str2->text().toUtf8().data()))));
}


void MainWindow::on_pushButton_6_clicked()
{
    ui->lineEdit_result->setText(QString::number((myString::myStrcoll(ui->lineEdit_str1->text().toUtf8().data(),  ui->lineEdit_str2->text().toUtf8().data()))));
}


void MainWindow::on_pushButton_11_clicked()
{
    ui->lineEdit_result->setText(QString::number((myString::myStrncmp(ui->lineEdit_str1->text().toUtf8().data(),  ui->lineEdit_str2->text().toUtf8().data(), (size_t)ui->spinBox->value()))));
}


void MainWindow::on_pushButton_14_clicked()
{
    ui->lineEdit_result->setText(QString::number((myString::myStrxfrm(ui->lineEdit_str1->text().toUtf8().data(),  ui->lineEdit_str2->text().toUtf8().data(), (size_t)ui->spinBox->value()))));
}


void MainWindow::on_pushButton_13_clicked()
{
    ui->lineEdit_result->setText((char*)((myString::myStrtok(ui->lineEdit_str1->text().toUtf8().data(),  ui->lineEdit_str2->text().toUtf8().data()))));
}


void MainWindow::on_pushButton_9_clicked()
{
    ui->lineEdit_result->setText((char*)myString::myMemset(ui->lineEdit_str1->text().toUtf8().data(),  ui->lineEdit_str2->text().front().toLatin1(), (size_t)ui->spinBox->value()));
}


void MainWindow::on_pushButton_8_clicked()
{
    ui->lineEdit_result->setText(QString::number((myString::myStrlen(ui->lineEdit_str1->text().toUtf8().data()))));
}
