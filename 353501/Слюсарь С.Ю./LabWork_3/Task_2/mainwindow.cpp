#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit->setValidator(new QRegularExpressionValidator(QRegularExpression("[0-3]"),this));
    ui->lineEdit_2->setValidator(new QRegularExpressionValidator(QRegularExpression("[0-9]|1[0-2]"),this));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Solve_clicked()
{
    if (ui->lineEdit->text().isEmpty() || ui->lineEdit_2->text().isEmpty())
    {
        ui->label->setText("Неверный ввод");
    }
    else
    {
        int n = ui->lineEdit->text().toInt();
        int m = ui->lineEdit_2->text().toInt();
        ui->label->setText("Результат: " + QString::number(ack->func(n, m)));
    }
}
