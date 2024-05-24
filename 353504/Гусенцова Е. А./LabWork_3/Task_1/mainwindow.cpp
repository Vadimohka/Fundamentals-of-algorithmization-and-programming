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
const int MAX = 16;
// void MainWindow::on_pushButton_clicked()
// {
//     // QString num = ui-> line->text();
//     double num=ui->spinBox->value();
//     // if (num >=1024)
//     // {
//     //     QMessageBox::information(this, tr("Warning!"), tr(" Your number is too big! "), QMessageBox::Ok | QMessageBox::NoButton);
//     //     return;
//     // }

//     QString binaryString;
//     func::convertToBinary(num, binaryString, 16); // You can adjust precision as needed
//     ui->textBrowser->setText("Binary representation: " + binaryString);


// }


void MainWindow::on_pushButton_clicked()
{
    QString res = ui->line->text();
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
    ui->textBrowser->setText(res);
}

QString MainWindow::toBin1(qint64 num, QString bin)
{
    if (num == 0) {
        return bin;
    } else {
        bin.insert(0, QChar(static_cast<int>(num % 2) + '0'));
        num /= 2;
        return toBin1(num, bin);
    }
}
QString MainWindow::toBin2(double num, QString bin, int count)
{
    if (num == 0 || count == MAX) {
        return bin;
    } else {
        bin.append(QChar(static_cast<int>(num * 2) + '0'));
        num = num * 2 - static_cast<int>(num * 2);
        count++;
        return toBin2(num, bin, count);
    }
}




