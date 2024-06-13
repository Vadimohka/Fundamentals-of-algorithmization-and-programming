#include "mainwindow.h"
#include "ui_mainwindow.h"

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

void MainWindow::on_On_front_clicked()
{
    if(!queue.empty())
    {
      try
       {
        qint64 value = queue.front();
        ui->plainTextEdit->clear();
        ui->plainTextEdit->setPlainText(QString::number(value));
       }
      catch (...)
      {
           QMessageBox::warning(nullptr, "Неверный Ввод", "Очередь пустая");
       }

    }
}

void MainWindow::on_On_back_clicked()
{
    if(!queue.empty())
    {
        try
        {
            qint64 value = queue.back();
            ui->plainTextEdit->clear();
            ui->plainTextEdit->setPlainText(QString::number(value));
        }
        catch (...)
        {
            QMessageBox::warning(nullptr, "Неверный Ввод", "Очередь пустая");
        }
    }
}


void MainWindow::on_On_Empty_clicked()
{
    try
    {
        bool isEmpty = queue.empty();
        ui->plainTextEdit->clear();
        ui->plainTextEdit->setPlainText(QString(isEmpty ? "Is Empty!" : "Очередь пустая"));
    }
    catch (...)
    {
        QMessageBox::warning(nullptr, "Неверный Ввод", "Очередь пустая");
    }
}


void MainWindow::on_On_Sort_clicked()
{
    if(!queue.empty())
    {
        try
        {
            ui->plainTextEdit->clear();
            queue.bubbleSort();
            ui->plainTextEdit->setPlainText(queue.print());
        }
        catch (...)
        {
            QMessageBox::warning(nullptr, "Неверный Ввод", "Очередь пустая");
        }
    }
}


void MainWindow::on_On_Print_clicked()
{
    try
    {
        ui->plainTextEdit->clear();
        ui->plainTextEdit->setPlainText(queue.print());
    }
    catch (...)
    {
        QMessageBox::warning(nullptr, "Неверный Ввод", "Очередь пустая");
    }
}


void MainWindow::on_On_clear_clicked()
{
    try
    {
        ui->plainTextEdit->clear();
        queue.clear();
    }
    catch (...)
    {
        QMessageBox::warning(nullptr, "Неверный Ввод", "Очередь пустая");
    }
}


void MainWindow::on_On_push_back_clicked()
{
    try
    {
        long long rand = QRandomGenerator::global()->bounded(100);
        queue.push_back(rand);
        ui->plainTextEdit->setPlainText(QString::number(rand));
    }
    catch (...)
    {
        QMessageBox::warning(nullptr, "Неверный Ввод", "Очередь пустая");
    }
}


void MainWindow::on_On_push_front_clicked()
{
    try
    {
        long long rand = QRandomGenerator::global()->bounded(100);
        queue.push_front(rand);
        ui->plainTextEdit->setPlainText(QString::number(rand));
    }
    catch (...)
    {
        QMessageBox::warning(nullptr, "Неверный Ввод", "Очередь пустая");
    }
}


void MainWindow::on_On_pop_back_clicked()
{
    if(!queue.empty())
    {
        try
        {
            qint64 value = queue.pop_back();
            ui->plainTextEdit->clear();
            ui->plainTextEdit->setPlainText(QString::number(value));
        }
        catch (...)
        {
            QMessageBox::warning(nullptr, "Неверный Ввод", "Очередь пустая");
        }
    }
}


void MainWindow::on_On_pop_front_clicked()
{
    if(!queue.empty())
    {
        try
        {
            qint64 value = queue.pop_front();
            ui->plainTextEdit->clear();
            ui->plainTextEdit->setPlainText(QString::number(value));
        }
        catch (...)
        {
            QMessageBox::warning(nullptr, "Неверный Ввод", "Очередь пустая");
        }
    }
}

