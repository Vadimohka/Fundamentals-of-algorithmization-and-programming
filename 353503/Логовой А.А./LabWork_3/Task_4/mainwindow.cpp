#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
    validator(new QRegularExpressionValidator(this))
{
    ui->setupUi(this);
    QRegularExpression regExp("[0-9][0-9]");
    validator->setRegularExpression(regExp);
    ui->lineEdit->setValidator(validator);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    if(ui->lineEdit->text().isEmpty()){
        QMessageBox::critical(nullptr, "Error", "You calculate empty line.");
    }

    else{

        QString num_str = ui->lineEdit->text();
        int num = num_str.toInt();

        ui->lineEdit->clear();
        ui->textBrowser->append(moves(num));
    }
}

