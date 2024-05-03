#include "mainwindow.h"
#include "./ui_mainwindow.h"

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

bool MainWindow::expression_type_equal(const Expression *left, const Expression *right)
{
    return (left->my_type_id() == right->my_type_id());
}

