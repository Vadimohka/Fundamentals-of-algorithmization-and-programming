#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->add_btn, &QPushButton::clicked, this, &MainWindow::addElement);
    connect(ui->delete_btn, &QPushButton::clicked, this, &MainWindow::deleteElement);
    connect(ui->contain_btn, &QPushButton::clicked, this, &MainWindow::containElement);
    connect(ui->clear_btn, &QPushButton::clicked, this, &MainWindow::clear);

    hash.createNewHashTable();
    hash.print(ui->textEdit);
    hash.deleteOddIndex();
    hash.print(ui->textEdit);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addElement()
{
    int key = ui->spinBox->value();
    int value = ui->spinBox_2->value();


    hash.insert(key,value);
    hash.print(ui->textEdit);
}

void MainWindow::deleteElement()
{
    int key = ui->spinBox->value();
    int value = ui->spinBox_2->value();


    hash.remove(key,value);
    hash.print(ui->textEdit);
}

void MainWindow::containElement()
{
    int key = ui->spinBox->value();
    int value = ui->spinBox_2->value();


    bool was = hash.contains(key,value);
    if(was){
        QMessageBox::about(nullptr, "Congratulations we have this element", " Key : " + QString::number(key) + "Value : " + QString::number(value));
    }
    else
    {
        QMessageBox::critical(nullptr, "Didn't find this", " Key : " + QString::number(key) + "Value : " + QString::number(value));
    }
}

void MainWindow::clear()
{

    hash.clear();
    ui->textEdit->clear();
}
