#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , lineEdit(new QLineEdit(this))
    , button(new QPushButton("Reverse Number", this))
    , label(new QLabel(this))
{
    setFixedSize(400, 200);

    lineEdit->setGeometry(50, 50, 320, 30);
    button->setGeometry(50, 100, 320, 30);
    label->setGeometry(50, 150, 320, 30);

    connect(button, &QPushButton::clicked, this, &MainWindow::reverseNumber);
}

MainWindow::~MainWindow()
{
}

void MainWindow::reverseNumber()
{
    QString input = lineEdit->text();
    if (isValidInput(input)) {
        int number = input.toInt();
        int reversedNumber = reverse(number);
        if (reversedNumber > INT_MAX) {
            label->setText("The reversed number is too large.");
        } else {
            label->setText(QString::number(reversedNumber));
        }
    } else {
        label->setText("Invalid input. Please enter an integer without 0.");
    }
}

int MainWindow::reverse(int n, int r)
{
    return n == 0 ? r : reverse(n / 10, r * 10 + n % 10);
}

bool MainWindow::isValidInput(const QString &input)
{
    bool ok;
    int number = input.toInt(&ok);
    return ok && !input.contains('0') && number > 0;
}
