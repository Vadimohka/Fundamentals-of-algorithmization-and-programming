#include "mainwindow.h"
#include <string>
#include <algorithm>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), lineEdit(new QLineEdit), label(new QLabel)
{
    QWidget *window = new QWidget;
    QVBoxLayout *layout = new QVBoxLayout;
    QPushButton *button = new QPushButton("Преобразовать");

    QObject::connect(button, &QPushButton::clicked, this, &MainWindow::convert);

    layout->addWidget(lineEdit);
    layout->addWidget(button);
    layout->addWidget(label);

    window->setLayout(layout);
    setCentralWidget(window);
}

MainWindow::~MainWindow()
{
}

void MainWindow::convert() {
    double num = lineEdit->text().toDouble();
    QString binary = decimalToBinary(num, 5); // 5 is the precision
    label->setText(binary);
}

QString MainWindow::decimalToBinary(double num, int precision) {
    bool isNegative = false;
    if (num < 0) {
        isNegative = true;
        num = -num;
    }

    int integral = int(num);
    double fractional = num - integral;

    std::string integralBinary = "";
    std::string fractionalBinary = "";

    // Обработка целой части
    while (integral) {
        int rem = integral % 2;
        integralBinary.push_back(rem +'0');
        integral /= 2;
    }

    std::reverse(integralBinary.begin(), integralBinary.end());

    // Добавление ведущих нулей до 8 бит
    while (integralBinary.size() < 8) {
        integralBinary.insert(integralBinary.begin(), '0');
    }

    // Обработка дробной части
    if (fractional > 0) {
        fractionalBinary.push_back('.');

        while (precision--) {
            fractional *= 2;
            int bit = int(fractional);

            if (bit == 1) {
                fractional -= bit;
                fractionalBinary.push_back(1 + '0');
            } else {
                fractionalBinary.push_back(0 + '0');
            }
        }
    }

    if (isNegative) {
        for (char &c : integralBinary) {
            c = (c == '0') ? '1' : '0';
        }

        // Add 1 to the binary number
        for (int i = integralBinary.size() - 1; i >= 0; --i) {
            if (integralBinary[i] == '1') {
                integralBinary[i] = '0';
            } else {
                integralBinary[i] = '1';
                break;
            }
        }

        // Ensure the first bit is 1 for negative numbers
        integralBinary[0] = '1';
    }

    std::string binary = integralBinary + fractionalBinary;

    return QString::fromStdString(binary);
}
