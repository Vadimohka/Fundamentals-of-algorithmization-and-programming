#include "mainwindow.h"
#include "ui_mainwindow.h"

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

void MainWindow::on_Button1_clicked()
{
    if(ui->lineEdit->text().isEmpty()){
        QMessageBox::critical(nullptr, "Error", "Empty string");
    }
    else{
        QString num_bin = "";
        QString sign_num = "";
        QString numb_str = ui->lineEdit->text();

        double num = numb_str.toDouble();
        signNum(num, sign_num);
        int intPart = int(num);
        double fracPart = num - intPart;

        intSecond(intPart, num_bin);
        num_bin += '.';

        fracSecond(fracPart, num_bin);
        sign_num += num_bin;
        ui->textBrowser->append(sign_num);
    }
    ui->lineEdit->clear();
}

