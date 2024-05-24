#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->textEdit->setReadOnly(true);
    // ui->textEdit->setStyleSheet()
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::OutputData(int num) {

    ui->textEdit->setPlainText(QString::number(num));
}

int MainWindow::SizeNum(int num) {

    if (num == 0) return 0;
    else {
        return 1 + SizeNum(num / 10);
    }
}

int MainWindow::ReverseNum(int num, int size) {

    if (num == 0) {
        return 0;
    }
    else {
        return pow(10, size - 1) * (num % 10) + ReverseNum(num / 10, size - 1);
    }
}

bool MainWindow::InputValidation(QString num) {

        int size = num.size();
        bool dot = false;
        for (int i = 0; i < size; ++i) {
            if (num.at(i) == '.' && dot) {
                return false;
            }
            else {
                dot = true;
                continue;
            }
            if (!(num.at(i) >= '0' && num.at(i) <= '9')) {
                return false;
            }
        }
        if (num.toInt() > 1000000) {
            return false;
        }

        return true;

}

void MainWindow::on_pushButton_clicked()
{
    int num = ui->spinBox->value();

    OutputData(ReverseNum(num, SizeNum(num)));
}

