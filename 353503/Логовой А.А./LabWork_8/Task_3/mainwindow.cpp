#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    tree.insert(123,"Mikhail");
    tree.insert(12, "Alexander");
    tree.insert(54, "Vadim");
    tree.printTree();
}

MainWindow::~MainWindow()
{
    delete ui;
}
