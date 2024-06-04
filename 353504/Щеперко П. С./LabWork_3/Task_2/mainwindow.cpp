#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->mArgumentLineEdit->setValidator(new QRegularExpressionValidator(QRegularExpression("[0-3]"), this));
    ui->nArgumentLineEdit->setValidator(new QRegularExpressionValidator(QRegularExpression("([0-1]?[0])|[0-9]"), this));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_computeAccermanFuncPushButton_clicked()
{
    ui->resultLabel->setText(QString::number(Accerman::AccermanFunc(ui->mArgumentLineEdit->text().toUShort(), ui->nArgumentLineEdit->text().toUShort())));
}

