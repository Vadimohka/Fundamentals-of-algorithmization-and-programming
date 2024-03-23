#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qvalidator.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit->setValidator(new QRegExpValidator(QRegExp("[1-9]*")));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    unsigned long long value = ui->lineEdit->text().toULongLong();
    unsigned long long output = Reverser::Reverse(value);
    ui->label_2->setText(QString::number(output));
}

