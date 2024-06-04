#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    validator = new QRegularExpressionValidator(QRegularExpression("[-]?[1-9]{18}"), this);
    ui->inputLineEdit->setValidator(validator);
    ui->reversePushButton->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_reversePushButton_clicked()
{
    ui->outputLabel->setText(
        QString::number(Reverse::ReverseNum(ui->inputLineEdit->text().toLongLong())));
}

void MainWindow::on_inputLineEdit_textChanged(const QString &arg1)
{
    Q_UNUSED(arg1);
    if (ui->inputLineEdit->text().isEmpty())
        ui->reversePushButton->setEnabled(false);
    else
        ui->reversePushButton->setEnabled(true);
}