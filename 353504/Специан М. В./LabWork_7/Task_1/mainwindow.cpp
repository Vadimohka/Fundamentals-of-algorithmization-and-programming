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

void MainWindow::UpdateInfo()
{
    ui->listWidget->clear();
    auto vec = queue.toVector();
    for (auto& element : vec)
    {
        ui->listWidget->addItem(element);
    }
}


void MainWindow::on_pushButton_empty_clicked()
{
    QMessageBox::information(nullptr, tr("Empty"), queue.empty() ? "Queue is empty" : "Queue isn't empty", QMessageBox::Ok | QMessageBox::NoButton);
}


void MainWindow::on_pushButton_size_clicked()
{
    QMessageBox::information(nullptr, tr("Size"), "Queue size: " + QString::number(queue.size()), QMessageBox::Ok | QMessageBox::NoButton);
}


void MainWindow::on_pushButton_front_clicked()
{
    try {
        QMessageBox::information(nullptr, tr("Front"), "Front element: " + queue.front(), QMessageBox::Ok | QMessageBox::NoButton);
    } catch (const char* e)
    {
        QMessageBox::warning(nullptr, tr("Pop"), e, QMessageBox::Ok | QMessageBox::NoButton);
    }
}


void MainWindow::on_pushButton_back_clicked()
{
    try {
        QMessageBox::information(nullptr, tr("Back"), "Back element: " + queue.back(), QMessageBox::Ok | QMessageBox::NoButton);
    } catch (const char* e)
    {
        QMessageBox::warning(nullptr, tr("Back"), e, QMessageBox::Ok | QMessageBox::NoButton);
    }
}


void MainWindow::on_pushButton_pop_clicked()
{
    try {
        queue.pop();
        UpdateInfo();
    } catch (const char* e)
    {
        QMessageBox::warning(nullptr, tr("Pop"), e, QMessageBox::Ok | QMessageBox::NoButton);
    }
}


void MainWindow::on_pushButton_push_clicked()
{
    try {
        queue.push(QInputDialog::getText(nullptr, tr("User input"), "Enter element:"));
        UpdateInfo();
    } catch (const char* e)
    {
        QMessageBox::warning(nullptr, tr("Push"), e, QMessageBox::Ok | QMessageBox::NoButton);
    }
}


void MainWindow::on_pushButton_insertAt_clicked()
{
    try {
        queue.insertAt(QInputDialog::getText(nullptr, tr("User input"), "Enter element:"), QInputDialog::getInt(nullptr, tr("User input"), "Enter index:"));
        UpdateInfo();
    } catch (const char* e)
    {
        QMessageBox::warning(nullptr, tr("Insert"), e, QMessageBox::Ok | QMessageBox::NoButton);
    }
}


void MainWindow::on_pushButton_deleteAt_clicked()
{
    try {
        queue.deleteAt(QInputDialog::getInt(nullptr, tr("User input"), "Enter index:"));
        UpdateInfo();
    } catch (const char* e)
    {
        QMessageBox::warning(nullptr, tr("Delete"), e, QMessageBox::Ok | QMessageBox::NoButton);
    }
}

