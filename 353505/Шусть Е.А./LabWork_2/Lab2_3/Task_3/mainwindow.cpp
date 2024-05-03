#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    check();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::check()
{
    try {
        Expression *sube = new BinaryOperation(new Number(4.5), '*', new Number(5));
        Expression *expr = new BinaryOperation(new Number(3), '+', sube);
        qDebug() << expr->evaluate();
        delete expr;
    } catch (...) {
        qDebug() << "Ошибочка";
    }
}
