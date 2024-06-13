#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->lineKey->setInputMask("000");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_AddButton_clicked()
{
    map.insert(ui->lineKey->text().toInt(), ui->lineValue->text());

    Display();
}

void MainWindow::Display()
{
    QString ToDisplay = map.inorderTraversal();

    ui->DISPLAY_Label->clear();
    ui->DISPLAY_Label->setText(ToDisplay);
}


void MainWindow::on_EraseButton_clicked()
{
    map.erase(ui->lineKey->text().toInt());

    Display();
}


void MainWindow::on_FindButton_clicked()
{
    QString val = *map.at(ui->lineKey->text().toInt());

    ui->AnswerLabel->clear();
    ui->AnswerLabel->setText(val);
}


void MainWindow::on_ClearButton_clicked()
{
    map.clear();

    Display();
}

