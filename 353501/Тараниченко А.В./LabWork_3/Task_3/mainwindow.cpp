#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QRegularExpressionValidator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit->setValidator(new QRegularExpressionValidator(QRegularExpression("^[-+]?[1-9]{1,16}"),this));
}

MainWindow::~MainWindow()
{
    delete ui;
}

long long MainWindow::func(long long n, long long k = 0){
    if (n == 0) return k;
    return func(n / 10, k * 10 + n % 10);
}

void MainWindow::on_pushButton_clicked()
{
    if (ui->lineEdit->text() != "")
        ui->label->setText(QString::number(func(ui->lineEdit->text().toLongLong(), 0)));
    else
        ui->label->setText("Введите число");
}
