#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <binaryview.h>

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

void MainWindow::on_pushButton_clicked()
{
    double number = ui->doubleSpinBox->value();

    ui->lineEdit->setText(BinaryView::toBinary(number));
}
