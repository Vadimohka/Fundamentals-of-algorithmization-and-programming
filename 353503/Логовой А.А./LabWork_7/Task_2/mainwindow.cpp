#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<BinarySearchTree.h>
#include<DisplayBinarySearchTree.h>
#include<QTextEdit>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    DisplayBinarySearchTree<int> prikol;
    prikol.insert(12,12);
    prikol.insert(14,13);
    prikol.insert(2,23);
    prikol.insert(68,67);
    prikol.displayTree(prikol.getNode(), ui->textEdit);

}

MainWindow::~MainWindow()
{
    delete ui;
}
