#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    CustomStack stack;
    stack.isEmpty();
}

MainWindow::~MainWindow()
{
    delete ui;
}

