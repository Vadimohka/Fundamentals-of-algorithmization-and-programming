#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->numberInDecimalLineEdit->setValidator(new QDoubleValidator(this));
}

void MainWindow::on_convertToBynaryPushButton_clicked()
{
    QString binaryNum = Convert::ConvertDoubleToBinary(ui->numberInDecimalLineEdit->text());
    ui->signLabel->setText(binaryNum.at(0));
    ui->exponentLabel->setText(binaryNum.mid(1, 11));
    ui->fractionLabel->setText(binaryNum.mid(12));
}

MainWindow::~MainWindow()
{
    delete ui;
}
