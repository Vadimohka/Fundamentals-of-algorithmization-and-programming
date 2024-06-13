#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    ,ui(new Ui::MainWindow),
    validator(new QRegularExpressionValidator(this))
{
    ui->setupUi(this);
    QRegularExpression regExp("[0-4]");
    validator->setRegularExpression(regExp);
    ui->lineEdit->setValidator(validator);
    ui->lineEdit_2->setValidator(validator);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_calculate_clicked()
{
    if(ui->lineEdit->text().isEmpty() || ui->lineEdit_2->text().isEmpty()){
        QMessageBox::critical(nullptr, "Error", "Empty fields");
    }
    else{
        QString num1_str = ui->lineEdit->text();
        int num1 = num1_str.toInt();

        QString num2_str = ui->lineEdit_2->text();
        int num2 = num2_str.toInt();

        ui->lineEdit->clear();
        ui->lineEdit_2->clear();

        int res = Ackerman(num1 ,num2);

        QString res_str = QString::number(res);

        ui->textBrowser->setText(res_str);
    }
}

