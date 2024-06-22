#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

bool MainWindow::areExprClassEqual(const Expression *left, const Expression *right)
{
    return (left->typeClass() == right->typeClass());
}

MainWindow::~MainWindow()
{
    delete ui;
}

