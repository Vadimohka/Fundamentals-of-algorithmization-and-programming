#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "ConstUi.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , buffer(new char[strochenka1.size() + strochenka2.size() + 1])
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(INDEX_START_WINDOW);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_memcpyButton_clicked()
{
    str::memcpy(&strochenka2[9], &strochenka1[0], 5);
    ui->lineString->setText(strochenka1.c_str());
    ui->lineString_2->setText(strochenka2.c_str());
}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    strochenka1 = "Hello World!";
    strochenka2 = "World of Tanks!";
    delete[] buffer;
    buffer = new char[strochenka1.size() + strochenka2.size() + 1];

    ui->lineString->setText(strochenka1.c_str());
    ui->lineString_2->setText(strochenka2.c_str());
    ui->lineBuffer->setText(buffer);
    ui->stackedWidget->setCurrentIndex(index);
}

void MainWindow::on_MemmoveButton_clicked()
{
    str::memmove(&strochenka2[9], &strochenka2[0], 5);
    ui->lineString->setText(strochenka1.c_str());
    ui->lineString_2->setText(strochenka2.c_str());
}

void MainWindow::on_resetButton_clicked()
{
    strochenka1 = "Hello World!";
    strochenka2 = "World of Tanks!";
    delete[] buffer;
    buffer = new char[strochenka1.size() + strochenka2.size() + 1];

    ui->lineString->setText(strochenka1.c_str());
    ui->lineString_2->setText(strochenka2.c_str());
    ui->lineBuffer->setText(buffer);
}

void MainWindow::on_strcpyButton_clicked()
{
    str::strcpy(buffer, strochenka2.c_str());
    ui->lineBuffer->setText(buffer);
}

void MainWindow::on_strncpyButton_clicked()
{
    str::strncpy(buffer, strochenka1.c_str(), 9);
    ui->lineBuffer->setText(buffer);
}

void MainWindow::on_strcatButton_clicked()
{
    str::strcpy(buffer, strochenka2.c_str());
    str::strcat(buffer, strochenka1.c_str());
    ui->lineBuffer->setText(buffer);
}

void MainWindow::on_strncatButton_clicked()
{
    str::strcpy(buffer, strochenka2.c_str());
    str::strncat(buffer, strochenka1.c_str(), 5);
    ui->lineBuffer->setText(buffer);
}

void MainWindow::on_memcmpButton_clicked()
{
    ui->lineString->setText(
        QString::number(str::memcmp(strochenka1.c_str(), strochenka2.c_str(), 5)));
    ui->lineString_2->setText(
        QString::number(str::memcmp(strochenka2.c_str(), strochenka1.c_str(), 5)));
}

void MainWindow::on_strcmpButton_clicked()
{
    ui->lineString->setText(QString::number(str::strcmp(strochenka1.c_str(), strochenka2.c_str())));
    ui->lineString_2->setText(
        QString::number(str::strcmp(strochenka2.c_str(), strochenka1.c_str())));
}

void MainWindow::on_strncmpButton_clicked()
{
    ui->lineString->setText(
        QString::number(str::strncmp(strochenka1.c_str(), strochenka2.c_str(), 2)));
    ui->lineString_2->setText(
        QString::number(str::strncmp(strochenka2.c_str(), strochenka1.c_str(), 2)));
}

void MainWindow::on_strcollButton_clicked()
{
    ui->lineString->setText(QString::number(str::strcoll(strochenka1.c_str(), strochenka2.c_str())));
    ui->lineString_2->setText(
        QString::number(str::strcoll(strochenka2.c_str(), strochenka1.c_str())));
}

void MainWindow::on_strxfrmButton_clicked()
{
    ui->strxfrmNumber->display(static_cast<int>(str::strxfrm(buffer, strochenka1.c_str(), 5)));
    ui->lineBuffer->setText(buffer);
}

void MainWindow::on_strtokButton_clicked()
{
    str::strcpy(buffer, strochenka1.c_str());
    buffer = str::strtok(buffer, " ");
    ui->lineToken_2->setText(buffer);
    buffer = str::strtok(nullptr, " ");
    ui->lineToken->setText(buffer);
}

void MainWindow::on_memsetButton_clicked()
{
    str::memset(buffer, 90, 10); // буква Z по ASCII
    ui->lineBuffer->setText(buffer);
}
