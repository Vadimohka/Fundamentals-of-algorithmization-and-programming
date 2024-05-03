#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "binarynumbersystem.h"

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

void MainWindow::on_getAnswerButton_clicked()
{
    double value = ui -> doubleSpinBox -> value();
    ui -> lineEdit -> setText(BinaryNumberSystem::toBinary(value));
}

