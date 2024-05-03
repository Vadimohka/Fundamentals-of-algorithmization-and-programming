#include "mainwindow.h"
#include "ui_mainwindow.h"

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

long long MainWindow::fun(long long a, long long b){
    if (a == 0) return b;
    return fun(a / 10, b * 10 + a % 10);
}

void MainWindow::on_pushButton_clicked()
{
    if (ui -> lineEdit -> text() != "") ui -> label_3 -> setText(QString::number(fun(ui -> lineEdit -> text().toLongLong(), 0)));
}

