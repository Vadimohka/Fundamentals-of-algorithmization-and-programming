#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "binaryoperation.h"
#include "number.h"
#include "iostream"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Number a(4);
    BinaryOperation answer(new Number(3),'+',new BinaryOperation(new Number(4), '*', new Number(3)));

    double ans = answer.evaluate();

    std::cout << ans << '\n';
}

MainWindow::~MainWindow()
{
    delete ui;
}

