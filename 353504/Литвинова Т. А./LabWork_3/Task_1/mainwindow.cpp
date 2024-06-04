#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //convertButton = new QPushButton("Конвертировать", this);
    //connect(convertButton, SIGNAL(clicked()), this, SLOT(on_convertButton_clicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

/*void MainWindow::on_convertButton_clicked()
{
    double number = ui->lineEdit->text().toDouble();
    QString binary = decimalToBinary(number);
    ui->label->setText(binary);
}*/

QString MainWindow::decimalToBinary(double number)
{
    int integerPart = int(number);
    double decimalPart = number - integerPart;

    QString binaryIntegerPart = QString::number(integerPart, 2);
    QString binaryDecimalPart = decimalPartToBinary(decimalPart);

    return binaryIntegerPart + "." + binaryDecimalPart;
}

QString MainWindow::decimalPartToBinary(double decimalPart)
{
    QString binaryDecimalPart;
    while (decimalPart != 0.0)
    {
        decimalPart *= 2;
        int bit = int(decimalPart);
        decimalPart -= bit;
        binaryDecimalPart.append(QString::number(bit));
    }
    return binaryDecimalPart;
}

void MainWindow::on_pushButton_clicked()
{
    double number = ui->lineEdit->text().toDouble();
    QString binary = decimalToBinary(number);
    ui->label->setText(binary);
}


