#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QMessageBox>

using namespace std;

MainWindow::MainWindow() : ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    on_pushButton_clicked();
    updateVec();

    connect(ui->pushButton_at, &QPushButton::clicked, this, &MainWindow::on_pushButton_at_clicked);
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::on_pushButton_clicked);
    connect(ui->pushButton_capacity, &QPushButton::clicked, this, &MainWindow::on_pushButton_capacity_clicked);
    connect(ui->pushButton_clear, &QPushButton::clicked, this, &MainWindow::on_pushButton_clear_clicked);
    connect(ui->pushButton_empty, &QPushButton::clicked, this, &MainWindow::on_pushButton_empty_clicked);
    connect(ui->pushButton_maxSize, &QPushButton::clicked, this, &MainWindow::on_pushButton_maxSize_clicked);
    connect(ui->pushButton_popBack, &QPushButton::clicked, this, &MainWindow::on_pushButton_popBack_clicked);
    connect(ui->pushButton_size, &QPushButton::clicked, this, &MainWindow::on_pushButton_size_clicked);
    connect(ui->pushButton_data, &QPushButton::clicked, this, &MainWindow::on_pushButton_data_clicked);
    connect(ui->pushButton_pushBack, &QPushButton::clicked, this, &MainWindow::on_pushButton_pushBack_clicked);
    connect(ui->pushButton_resize, &QPushButton::clicked, this, &MainWindow::on_pushButton_resize_clicked);
    connect(ui->pushButton_reserve, &QPushButton::clicked, this, &MainWindow::on_pushButton_reserve_clicked);
    connect(ui->pushButton_erase, &QPushButton::clicked, this, &MainWindow::on_pushButton_erase_clicked);
    connect(ui->pushButton_begin, &QPushButton::clicked, this, &MainWindow::on_pushButton_begin_clicked);
    connect(ui->pushButton_end, &QPushButton::clicked, this, &MainWindow::on_pushButton_end_clicked);
}

void MainWindow::on_pushButton_clicked()
{
    pair.clear();
    pair.resize(1);
    ui->tableWidget_left->setRowCount(0);
    ui->tableWidget_right->setRowCount(0);
    ui->tableWidget_left->setColumnCount(2);
    ui->tableWidget_right->setColumnCount(2);

    int size = rand() % 20 + 10;

    for (int i = 0; i < size; ++i)
    {
        pair[0].first.push_back(rand() % 100);
        pair[0].second.push_back({rand() % 100, (double)(rand() % 500) / 5});
    }
    for (int i = 0; i < size; ++i)
    {
        ui->tableWidget_left->insertRow(i);
        ui->tableWidget_left->setItem(i, 0, new QTableWidgetItem(QString::number(pair[0].first[i])));
        ui->tableWidget_right->insertRow(i);
        ui->tableWidget_right->setItem(i, 0, new QTableWidgetItem(QString::number(pair[0].second[i].first)));
        ui->tableWidget_right->setItem(i, 1, new QTableWidgetItem(QString::number(pair[0].second[i].second)));
    }
    vec.clear();
    for(int i = 0; i < 10; i ++){
        vec.push_back(rand() % 15);
    }
    updateVec();
}

void MainWindow::updateVec()
{
    QString str = "";
    for (auto i: vec)
    {
        str += QString::number(i) + " | ";
    }
    ui->textBrowser->setText("| " + str);
}

void MainWindow::on_pushButton_at_clicked()
{
    int str = ui->lineEdit->text().toInt();
    if (str == 0)
    {
        if (ui->lineEdit->text() != "0")
        {
            QMessageBox::warning(this, "At", "Error, check your input field");
            return;
        }
    }
    if (str >= 0 && str < vec.Size())
    {
        QMessageBox::information(this, "At", "Result: " + QString::number(vec.at(str)));
    }
    else
    {
        QMessageBox::warning(this, "At", "Error, check your input field");
    }
}

void MainWindow::on_pushButton_capacity_clicked()
{
    QMessageBox::information(this, "Capacity", "Result " + QString::number(vec.Capacity()));
}

void MainWindow::on_pushButton_clear_clicked()
{
    vec.clear();
    QMessageBox::information(this, "Clear", "Array was cleared");
    updateVec();
}

void MainWindow::on_pushButton_empty_clicked()
{
    QMessageBox::information(this, "Empty Check", vec.empty() ? "Result: Empty" : "Result: Not Empty");
}

void MainWindow::on_pushButton_maxSize_clicked()
{
    QMessageBox::information(this, "Max Size", "Result: " + QString::number(vec.max_size()));
}

void MainWindow::on_pushButton_popBack_clicked()
{
    if (vec.Size() > 0)
    {
        vec.pop_back();
        QMessageBox::information(this, "Pop Back", "Erased last element");
    }
    else
    {
        QMessageBox::information(this, "Pop Back", "Array is null, nothing to pop");
    }
    updateVec();
}

void MainWindow::on_pushButton_size_clicked()
{
    QMessageBox::information(this, "Size", QString::number(vec.Size()));
}

void MainWindow::on_pushButton_data_clicked()
{
    QString ptrStr = QString("0x%1").arg(reinterpret_cast<quintptr>(vec.data()), QT_POINTER_SIZE * 2, 16, QChar('0'));
    QMessageBox::information(this, "Data", "Result: " + ptrStr);
}

void MainWindow::on_pushButton_begin_clicked()
{
    QString ptrStr = QString("0x%1").arg(reinterpret_cast<quintptr>(vec.begin().getIteratorAddress()), QT_POINTER_SIZE * 2, 16, QChar('0'));
    QMessageBox::information(this, "Data", "Result: " + ptrStr);
}

void MainWindow::on_pushButton_end_clicked()
{
    QString ptrStr = QString("0x%1").arg(reinterpret_cast<quintptr>(vec.end().getIteratorAddress()), QT_POINTER_SIZE * 2, 16, QChar('0'));
    QMessageBox::information(this, "Data", "Result: " + ptrStr);
}

void MainWindow::on_pushButton_pushBack_clicked()
{
    QString str = ui->lineEdit->text();
    int i = str.toInt();
    if (i == 0)
    {
        if (ui->lineEdit->text() != "0")
        {
            QMessageBox::warning(this, "At", "Error, check your input field");
            return;
        }
    }
    vec.push_back(i);
    QMessageBox::information(this, "PushBack", "Executed succesfully");
    updateVec();
}

void MainWindow::on_pushButton_resize_clicked()
{
    QString str = ui->lineEdit->text();
    int i = str.toInt();
    if (i == 0)
    {
        if (ui->lineEdit->text() != '0')
        {
            QMessageBox::warning(this, "Resize", "Error, check your input field");
            return;
        }
    }

    if (i >= 0)
    {
        vec.resize(i);
        QMessageBox::information(this, "Resize", "Executed succesfully");
    }
    else
    {
        QMessageBox::information(this, "Resize", "Executed succesfully");
    }
    updateVec();
}

void MainWindow::on_pushButton_reserve_clicked()
{
    QString str = ui->lineEdit->text();
    int i = str.toInt();
    if (i == 0)
    {
        if (ui->lineEdit->text() != '0')
        {
            QMessageBox::warning(this, "Reserve", "Error, check your input field");
            return;
        }
    }
    vec.reserve(i);
    QMessageBox::information(this, "Reserve", "Executed succesfully");
}

void MainWindow::on_pushButton_erase_clicked()
{
    QString str = ui->lineEdit->text();
    int i = str.toInt();
    if (i == 0)
    {
        if (ui->lineEdit->text() != '0')
        {
            QMessageBox::warning(this, "Erase", "Error, check your input field");
            return;
        }
    }

    if (i >= 0 && i < vec.Size())
    {
        vec.erase(vec.begin() + i);
        QMessageBox::information(this, "Erase", "Executed succesfully");
    }
    else
    {
        QMessageBox::warning(this, "Erase", "Error, check your input field");
    }
    updateVec();
}