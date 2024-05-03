#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->Input->clear();
    ui->Input->setRange(INPUT_MIN, INPUT_MAX);
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::isZero(int num)
{
    if (num == 0) {
        return false;
    }
    if (num % TEN == 0) {
        return true;
    }
    return isZero(num / TEN);
}

int MainWindow::reverse(int num)
{
    int res = 0;

    res = reverseNum(num, res);
    return res;
}

int MainWindow::reverseNum(int num, qint64 res)
{
    if (num == 0) {
        return res / TEN;
    }
    res += num % TEN;
    return reverseNum(num / TEN, res * TEN);
}

void MainWindow::on_pushButton_clicked()
{
    int input = ui->Input->value();
    if (isZero(input)) {
        QMessageBox::critical(this, "Ошибка", "Сказано вводить БЕЗ нулей");
    } else {
        ui->Output->setText(QString::number(reverse(input)));
    }
}
