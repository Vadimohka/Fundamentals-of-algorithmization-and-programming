#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Expression const *var1 = new Number(1);
    Expression const *var2 = new Number(2);
    Expression const *var3 = new BinaryOperation(new Number(1), '+', new Number(2));
    qDebug() << check_equals(var1, var2) << check_equals(var2, var3);
    delete var1;
    delete var2;
    delete var3;
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::check_equals(Expression const *left, Expression const *right)
{
    if (*(reinterpret_cast<const void *const *>(left))
        == *(reinterpret_cast<const void *const *>(right))) {
        return true;
    } else {
        return false;
    }
}
