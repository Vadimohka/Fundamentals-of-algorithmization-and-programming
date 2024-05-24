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

void MainWindow::on_On_push_back_clicked()
{
    int a = ui->spinBox->value();
    deque.push_back(a);
    ui->label->setText(QString::fromStdString(deque.to_string()));
}


void MainWindow::on_On_push_front_clicked()
{
    int a = ui->spinBox->value();
    deque.push_front(a);
    ui->label->setText(QString::fromStdString(deque.to_string()));
}


void MainWindow::on_On_pop_back_clicked()
{
    deque.pop_back();
    ui->label->setText(QString::fromStdString(deque.to_string()));
}


void MainWindow::on_On_pop_front_clicked()
{
    deque.pop_front();
    ui->label->setText(QString::fromStdString(deque.to_string()));
}


void MainWindow::on_On_front_clicked()
{
    int val = deque.front();
    ui->label->setText(QString::number(val));
}


void MainWindow::on_On_back_clicked()
{
    int val = deque.back();
    ui->label->setText(QString::number(val));
}


void MainWindow::on_On_Print_clicked()
{
    ui->label->setText(QString::fromStdString(deque.to_string()));
}

