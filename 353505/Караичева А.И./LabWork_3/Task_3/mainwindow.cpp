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

void MainWindow::on_pushButton_result_clicked()
{
    long long n = ui->spinBox_number->value();
    long long a = 0;
    if (n % 10 == 0) {
        ui->label_answer->setText("Incorrect Input");
    } else {
    ui->label_answer->setText(QString::number(reverse_number.rev(n, a)));
    }
}

