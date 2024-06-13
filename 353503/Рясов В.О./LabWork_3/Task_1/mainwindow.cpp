#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include "translator.h"

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
    QString input = ui->lineEdit->text();
    double num = input.toDouble();
    ui->label->setText(Translator::Translate(num));
}

