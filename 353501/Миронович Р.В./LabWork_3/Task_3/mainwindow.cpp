#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->calculateButton, &QPushButton::clicked, this, &MainWindow::reverseNumber);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::reverseNumber()
{
    bool ok;
    int n = ui->numberLineEdit->text().toInt(&ok);

    if (!ok)
    {
        QMessageBox::warning(this, "Ошибка", "Некорректное значение числа");
        return;
    }

    if (n == 0 || containsZero(n))
    {
        QMessageBox::warning(this, "Ошибка", "Число не может содержать нули");
        return;
    }

    int reversed = reverseRecursively(n);

    ui->reversedLabel->setText(QString::number(reversed));
}

bool MainWindow::containsZero(int number)
{
    if (number == 0)
        return false;

    if (number % 10 == 0)
        return true;

    return containsZero(number / 10);
}

int MainWindow::reverseRecursively(int n)
{
    if (n < 0)
    {
        return -reverseRecursively(-n);
    }

    if (n < 10)
    {
        return n;
    }
    else
    {
        int lastDigit = n % 10;
        int remainingDigits = n / 10;
        int reversedRemaining = reverseRecursively(remainingDigits);
        int reversed = lastDigit;

        while (reversed >= 10)
        {
            reversed /= 10;
        }

        int orderOfMagnitude = 10;
        while (reversedRemaining >= orderOfMagnitude)
        {
            orderOfMagnitude *= 10;
        }

        return reversed * orderOfMagnitude + reversedRemaining;
    }
}
