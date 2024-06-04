#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , validator(static_cast<double>(INT_MIN), static_cast<double>(INT_MAX), 4, this)
{
    ui->setupUi(this);
    validator.setNotation(QDoubleValidator::StandardNotation);
    ui->lineEdit_dec->setValidator(&validator);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_eval_clicked()
{
    QString res = ui->lineEdit_dec->text();
    for (int i = 0; i < res.size(); i++) {
        if (res[i] == ',') {
            res.remove(i, 1);
            res.insert(i, '.');
            break;
        }
    }
    double num = res.toDouble();
    res.clear();
    res = toBin1(static_cast<qint64>(num), res);
    res.append(".");
    res = toBin2(num - static_cast<qint64>(num), res, 0);
    ui->label_bin->setText(res);
}

QString MainWindow::toBin1(qint64 num, QString bin)
{
    if (num == 0) {
        return bin;
    } else {
        bin.insert(0, static_cast<int>(num % 2) + '0');
        num /= 2;
        return toBin1(num, bin);
    }
}

QString MainWindow::toBin2(double num, QString bin, int count)
{
    if (num == 0 || count == MAX_DEC) {
        return bin;
    } else {
        bin.append(static_cast<int>(num * 2) + '0');
        num = num * 2 - static_cast<int>(num * 2);
        count++;
        return toBin2(num, bin, count);
    }
}
