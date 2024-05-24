#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->outLabel->setFont(QFont("arial", 20));

    setWindowTitle("String");
    setFixedSize(size());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_constructButton_clicked()
{
    ui->outLabel->setText(String(ui->str1LineEdit->text().toStdString().c_str()).begin());
}


void MainWindow::on_memcmpButton_clicked()
{
    int a = String::strcmp(ui->str1LineEdit->text().toUtf8().data(),
                            ui->str2LineEdit->text().toUtf8().data());
    ui->outLabel->setText(a > 0 ? "Первая больше" : (a == 0 ? "Строки равны" : "Вторая больше"));
}


void MainWindow::on_memmoveButton_clicked()
{
    ui->outLabel->setText((char *)String::memmove(ui->str1LineEdit->text().toUtf8().data(),
                        ui->str2LineEdit->text().toUtf8().data(), (size_t)ui->nSpinBox->value()));
}


void MainWindow::on_memcpyButton_clicked()
{
    ui->outLabel->setText((char *)String::memcpy(ui->str1LineEdit->text().toUtf8().data(),
                        ui->str2LineEdit->text().toUtf8().data(), (size_t)ui->nSpinBox->value()));
}


void MainWindow::on_strcpyButton_clicked()
{
    ui->outLabel->setText((char *)String::strcpy(ui->str1LineEdit->text().toUtf8().data(),
                                                  ui->str2LineEdit->text().toUtf8().data()));
}


void MainWindow::on_strncpyButton_clicked()
{
    ui->outLabel->setText((char *)String::strncpy(ui->str1LineEdit->text().toUtf8().data(),
                        ui->str2LineEdit->text().toUtf8().data(), (size_t)ui->nSpinBox->value()));
}


void MainWindow::on_strcatButton_clicked()
{
    ui->outLabel->setText((char *)String::strcat(ui->str1LineEdit->text().toUtf8().data(),
                        ui->str2LineEdit->text().toUtf8().data()));
}


void MainWindow::on_strncatButton_clicked()
{
    ui->outLabel->setText((char *)String::srncat(ui->str1LineEdit->text().toUtf8().data(),
                    ui->str2LineEdit->text().toUtf8().data(), (size_t)ui->nSpinBox->value()));
}


void MainWindow::on_strcmpButton_clicked()
{
    int a = String::strcmp(ui->str1LineEdit->text().toUtf8().data(),
                           ui->str2LineEdit->text().toUtf8().data());
    ui->outLabel->setText(a > 0 ? "Первая больше" : (a == 0 ? "Строки равны" : "Вторая больше"));
}


void MainWindow::on_strcollButton_clicked()
{
    int a = String::strcoll(ui->str1LineEdit->text().toUtf8().data(),
                           ui->str2LineEdit->text().toUtf8().data());
    ui->outLabel->setText(a > 0 ? "Первая больше" : (a == 0 ? "Строки равны" : "Вторая больше"));
}


void MainWindow::on_strncmpButton_clicked()
{
    int a = String::strncmp(ui->str1LineEdit->text().toUtf8().data(),
            ui->str2LineEdit->text().toUtf8().data(), ui->nSpinBox->value());
    ui->outLabel->setText(a > 0 ? "Первая больше" : (a == 0 ? "Строки равны" : "Вторая больше"));
}


void MainWindow::on_strxfrmButton_clicked()
{
    ui->outLabel->setText((char *)String::strxfrm(ui->str1LineEdit->text().toUtf8().data(),
                        ui->str2LineEdit->text().toUtf8().data(), (size_t)ui->nSpinBox->value()));
}


void MainWindow::on_strtokButton_clicked()
{
    ui->outLabel->setText((char *)String::strtok(ui->str1LineEdit->text().toUtf8().data(),
                        ui->str2LineEdit->text().toUtf8().data()));
}


void MainWindow::on_memsetButton_clicked()
{
    ui->outLabel->setText((char *)String::memset(ui->str1LineEdit->text().toUtf8().data(),
                    (int)ui->str2LineEdit->text().toUtf8().data()[0], (size_t)ui->nSpinBox->value()));
}


void MainWindow::on_strerrorButton_clicked()
{
    ui->outLabel->setText(String::strerror(ui->nSpinBox->value()));
}


void MainWindow::on_strlenButton_clicked()
{
    ui->outLabel->setText(QString::number(
        String(ui->str1LineEdit->text().toStdString().c_str()).size()));
}

