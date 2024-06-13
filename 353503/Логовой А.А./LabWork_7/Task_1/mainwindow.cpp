#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QRandomGenerator>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    for(int i{}; i < 30; ++i){
        int random_number = QRandomGenerator::global()->bounded(1, 100);
        queue.push_back(random_number);
    }
    queue.swapMinMax();
    ui->textEdit->setText(queue.print());
    connect(ui->pop_back, &QPushButton::clicked, this, &MainWindow::popBack);
    connect(ui->pop_front, &QPushButton::clicked, this, &MainWindow::popFront);
    connect(ui->push_front, &QPushButton::clicked, this, &MainWindow::addFrontElement);
    connect(ui->push_back, &QPushButton::clicked, this, &MainWindow::addBackElement);
    connect(ui->pop_back, &QPushButton::clicked, this, &MainWindow::popBack);
    connect(ui->clear, &QPushButton::clicked, this, &MainWindow::clear);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addFrontElement()
{
    int element  = ui->spinBox->value();
    queue.push_front(element);
    ui->textEdit->clear();
    ui->textEdit->setText(queue.print());
}

void MainWindow::addBackElement()
{
    int element  = ui->spinBox->value();
    queue.push_back(element);
    ui->textEdit->clear();
    ui->textEdit->setText(queue.print());
}

void MainWindow::popBack()
{
    try{
        ui->textEdit->clear();
        queue.pop_back();
        ui->textEdit->setText(queue.print());
    }
    catch(...){
        QMessageBox::critical(nullptr, "Erorr" , "Queue is empty");
    }
}

void MainWindow::popFront()
{
    try{
    ui->textEdit->clear();
    queue.pop_front();
    ui->textEdit->setText(queue.print());
    }
    catch(...){
        QMessageBox::critical(nullptr, "Erorr" , "Queue is empty");
    }
}

void MainWindow::clear()
{
    ui->textEdit->clear();
    queue.clear();
    queue.print();
}
