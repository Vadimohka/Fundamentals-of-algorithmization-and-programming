#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->textEdit, &QTextEdit::textChanged, this, &MainWindow::on_textEdit_textChanged);

}

MainWindow::~MainWindow()
{
    delete ui;
}


QString decimalToBinary(double number)
{
    int integerPart = static_cast<int>(number);
    double fractionalPart = number - integerPart;

    QString binary = "";

    // Преобразование целой части в двоичное представление
    if (integerPart == 0) {
        binary = "0";
    } else {
        while (integerPart > 0) {
            binary.prepend(QString::number(integerPart % 2));
            integerPart /= 2;
        }
    }

    binary.append("."); // Добавляем десятичную точку

    // Преобразование дробной части в двоичное представление
    for (int i = 0; i < 16; ++i) {
        fractionalPart *= 2;
        int bit = static_cast<int>(fractionalPart);
        binary.append(QString::number(bit));
        fractionalPart -= bit;
    }

    return binary;
}

void MainWindow::on_textEdit_textChanged()
{
    QString input = ui->textEdit->toPlainText();
    bool ok;
    double number = input.toDouble(&ok);
    if (ok) {
        QString binary = decimalToBinary(number);
        ui->label_4->setText(binary);
    } else {
        ui->label_4->setText(" ");
    }
}
