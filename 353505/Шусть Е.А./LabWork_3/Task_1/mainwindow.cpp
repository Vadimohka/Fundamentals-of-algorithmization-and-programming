#include "mainwindow.h"
#include <QVBoxLayout>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    QVBoxLayout *layout = new QVBoxLayout(this);

    QLabel *label = new QLabel("Введите число:", this);
    layout->addWidget(label);

    inputLineEdit = new QLineEdit(this);
    layout->addWidget(inputLineEdit);

    QPushButton *button = new QPushButton("Преобразовать", this);
    layout->addWidget(button);

    resultLabel = new QLabel(this);
    layout->addWidget(resultLabel);

    connect(button, &QPushButton::clicked, this, &MainWindow::convertToBinary);
}

void MainWindow::convertToBinary()
{
    QString input = inputLineEdit->text();
    bool ok;
    long double number = input.toDouble(&ok);

    if (ok)
    {
        QString binaryQString = decimalToBinary(number, 1600); // Установите желаемую точность здесь
        resultLabel->setText("Результат: " + binaryQString);
    }
    else
    {
        resultLabel->setText("Ошибка: Введите корректное число");
    }
}

QString MainWindow::decimalToBinary(long double number, int precision)
{
    QString binary;

    // Проверка на отрицательное число
    if (number < 0)
    {
        binary += "-";
        number = -number;
    }

    // Преобразование целой части в двоичное представление
    unsigned long long integerPart = static_cast<unsigned long long>(number);
    binary += QString::number(integerPart, 2);

    // Преобразование дробной части в двоичное представление
    if (precision > 0)
    {
        binary += ".";
        long double fractionalPart = number - static_cast<long double>(integerPart);
        int digitCount = 0;

        while (fractionalPart > 0 && digitCount < precision)
        {
            fractionalPart *= 2;
            unsigned long long bit = static_cast<unsigned long long>(fractionalPart);
            binary += QString::number(bit);
            fractionalPart -= bit;
            digitCount++;
        }
    }

    return binary;
}
