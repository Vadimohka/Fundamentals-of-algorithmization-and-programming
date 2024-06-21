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

void MainWindow::on_pushButton_clicked()
{
    task1win = new Task1Window();
    task1win->show();
}

void MainWindow::on_pushButton_2_clicked()
{
    task2win = new Task2Window();
    task2win->show();
}
