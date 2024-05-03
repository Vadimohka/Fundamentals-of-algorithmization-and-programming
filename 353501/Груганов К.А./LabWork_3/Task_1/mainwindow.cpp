#include "mainwindow.h"
#include <QPixmap>
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix(":/img/Double-Precision-IEEE-754-Floating-Point-Standard-1024x266.jpg");
    int w = ui->image->width();
    int h = ui->image->height();
    ui->image->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio, Qt::SmoothTransformation));
}

MainWindow::~MainWindow()
{
    delete ui;
}

QString MainWindow::printBinary(double x)
{
    bool isNegative = x < 0;
    if (isNegative) {
        x = -x;
    }
    double intPart = floor(x);
    double fracPart = x - floor(x);
    QString intPartBin = decimalToBin(intPart);
    QString fracPartBin = fracToBin(fracPart, 10);
    if (isNegative) {
        return "-" + intPartBin + "." + fracPartBin;
    } else {
        return intPartBin + "." + fracPartBin;
    }
}
QString MainWindow::decimalToBin(double n)
{
    if (n == 0) {
        return "";
    } else {
        return decimalToBin((double) floor(n / 2)) + QString::number((int) fmod(n, 2));
    }
}

QString MainWindow::fracToBin(double frac, int bits)
{
    if (bits == 0) {
        return "";
    } else {
        double twoTimesFrac = 2.0 * frac;
        int bit = (int) twoTimesFrac;
        if (twoTimesFrac >= 1.0) {
            twoTimesFrac -= 1.0;
        }
        return QString::number(bit) + fracToBin(twoTimesFrac, bits - 1);
    }
}

QString MainWindow::printIEEE754(double x)
{
    return getSign(x) + " " + getExp(x) + " " + getM(x);
}

QString MainWindow::getM(double x)
{
    ull *p = (ull *) &x;
    ull mantissa = (*p & 0xFFFFFFFFFFFFF);
    QString mantissaBin = decimalToBin(mantissa);
    while (mantissaBin.length() < 52) {
        mantissaBin = "0" + mantissaBin;
    }
    return mantissaBin;
}

QString MainWindow::getExp(double x)
{
    ull *ptr = (ull *) &x;
    ull exp = (*ptr >> 52) & 0x7FF;
    QString expS = decimalToBin(exp);
    while (expS.length() < 11) {
        expS = "0" + expS;
    }
    return expS;
}

QString MainWindow::getSign(double x)
{
    return (x < 0) ? "1" : "0";
}

void MainWindow::on_ieee754convert_clicked()
{
    if (!ui->InputEdit->text().isEmpty()) {
        QString text = ui->InputEdit->text();
        bool ok;
        double num = text.toDouble(&ok);
        if (ok) {
            ui->Output->setText(printIEEE754(num));
            ui->M_2->setText(getM(num));
            ui->exp->setText(getExp(num));
            ui->sign_2->setText(getSign(num));
        } else {
            ui->Output->setText("Неверный ввод!!!");
            ui->M_2->clear();
            ui->exp->clear();
            ui->sign_2->clear();
        }
    } else if (ui->InputEdit->text().isEmpty()) {
        QMessageBox::information(this, "Ошибка", "Введите число.");
    }
}

void MainWindow::on_binaryconvert_clicked()
{
    if (!ui->InputEdit->text().isEmpty()) {
        QString text = ui->InputEdit->text();
        bool ok;
        double num = text.toDouble(&ok);
        if (ok) {
            ui->binaryFormat->setText(printBinary(num));
        } else {
            ui->binaryFormat->setText("Неверный ввод!!!");
        }
    } else if (ui->InputEdit->text().isEmpty()) {
        QMessageBox::information(this, "Ошибка", "Введите число.");
    }
}
