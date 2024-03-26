#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(pop()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::pop()
{

}

void MainWindow::on_pushButton_clicked()
{

}

