#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
    validator(new QIntValidator(this))
{
    ui->setupUi(this);
    ui->lineEdit->setValidator(validator);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_clicked(){

    if(ui->lineEdit->text().isEmpty()){
        QMessageBox::critical(nullptr, "Error" , "You enter empty line.");
    }

    else{
        QString num_str = ui->lineEdit->text();
        int num = num_str.toInt();
        num = reverse(num, 0);
        ui->lineEdit->clear();
        ui->textBrowser->setText(QString::number(num));
    }
}

