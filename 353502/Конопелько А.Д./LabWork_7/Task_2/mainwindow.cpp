#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    tree = new AVL_Tree();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_del_clicked()
{

}


void MainWindow::on_pushButton_find_clicked(){}




void MainWindow::on_pushButton_add_clicked()
{
    t
}


void MainWindow::on_pushButton_InOrder_clicked()
{

}


void MainWindow::on_pushButton_PreOrder_clicked()
{

}


void MainWindow::on_pushButton_PostOrder_clicked()
{

}


void MainWindow::on_pushButton_leftBranch_clicked()
{

}


void MainWindow::on_pushButton_balanse_clicked()
{

}

