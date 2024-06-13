#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
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
    setCentralWidget(new QWidget(this));

    centralWidget()->setLayout(layout);
}

void MainWindow::convertToBinary() {
    QString input = inputLineEdit->text();
    bool ok;
    long double number = input.toDouble(&ok);
    if (!ok) {
        resultLabel->setText("Ошибка: Введите корректное число");
        return;
    }

    if (number > 1e19) {
        QMessageBox::warning(this, "Ошибка", "Введите число не более чем, 1e19");
        return;
    }

    QString binary;
    if (number < 0) {
        binary += "-";
        number = -number;
    }

    int precision = 30; // желаемая точность для дробной части
    binary += decimalToBinary(static_cast<unsigned long long>(number), precision);

    resultLabel->setText("Результат: " + binary);
}

QString MainWindow::decimalToBinary(unsigned long long number, int precision) {
    if (number == 0) // базовый случай: когда число становится 0, рекурсия завершается
        return "";

    // Рекурсивно вычисляем двоичное представление целой части
    QString binary = decimalToBinary(number / 2, precision);

    // Добавляем текущий остаток в конец двоичной строки
    binary += QString::number(number % 2);

    return binary;
}

MainWindow::~MainWindow() {
    delete ui;
}
