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

    int reversed = reverseRecursively(n);

    ui->reversedLabel->setText(QString::number(reversed));
}

int MainWindow::reverseRecursively(int n)
{
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
