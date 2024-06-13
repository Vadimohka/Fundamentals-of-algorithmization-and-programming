#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    qDebug() << "new rofls";
    connect(ui->clear, &QPushButton::clicked, this, &MainWindow::clear);
    connect(ui->push_back, &QPushButton::clicked, this, &MainWindow::pushBack);
    connect(ui->push_front, &QPushButton::clicked, this, &MainWindow::pushFront);
    connect(ui->pop_back, &QPushButton::clicked, this, &MainWindow::popBack);
    connect(ui->pop_front, &QPushButton::clicked, this, &MainWindow::popFront);
    connect(ui->get_value, &QPushButton::clicked, this, &MainWindow::getElement);
    connect(ui->is_empty, &QPushButton::clicked, this, &MainWindow::isEmpty);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::clear()
{
    deque.clear();
    ui->textEdit_2->clear();
    ui->textEdit->clear();
}

void MainWindow::isEmpty()
{
    ui->textEdit_2->clear();

    (deque.isEmpty() == true ) ? ui->textEdit_2->setText("Yes") : ui->textEdit_2->setText("No");

}

void MainWindow::pushBack()
{
    int element = ui->spinBox->value();
    deque.push_back(element);
    ui->textEdit->clear();
    ui->textEdit->setText(deque.toString());
}

void MainWindow::pushFront()
{
    int element = ui->spinBox->value();
    deque.push_front(element);
    ui->textEdit->clear();
    ui->textEdit->setText(deque.toString());
}

void MainWindow::popBack()
{
    try{
    deque.pop_back();
    ui->textEdit->setText(deque.toString());
    }
    catch(...){
        QMessageBox::critical(nullptr, "Erorr", "You ot of range");
    }
}

void MainWindow::popFront()
{
    try{
    deque.pop_front();
    ui->textEdit->setText(deque.toString());
    }
    catch(...){
        QMessageBox::critical(nullptr, "Erorr", "You ot of range");
    }
}

void MainWindow::getElement()
{
    int element = ui->spinBox->value();
    try{
        int key = deque.at(element);
        ui->textEdit_2->clear();
        ui->textEdit_2->setText("On index: " + QString::number(element) + "  Contain:  " + QString::number(key));
    }
    catch(...){
        QMessageBox::critical(nullptr, "Erorr","You are out of range");
    }
}
