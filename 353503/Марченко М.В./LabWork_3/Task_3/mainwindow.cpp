#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->lineEdit, &QLineEdit::textChanged, this, &MainWindow::lineEdit_userTextChanged);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::lineEdit_userTextChanged(const QString &text)
{
    if (text.isEmpty()) {
        ui->label->clear();
        return;
    }

    bool isNegative = text.startsWith('-');
    QString newText = isNegative ? text.mid(1) : text;

    if (newText.isEmpty()) {
        ui->label->clear();
        return;
    }

    bool ok;
    long long number = newText.toLongLong(&ok);
    if (ok) {
        number = qAbs(number);
        if (!contains0(number)) {
            long long reversedNumber = reverse_number(number);
            QString result = QString::number(reversedNumber);
            if (isNegative) {
                result = "-" + result;
            }
            ui->label->setText(result);
        } else {
            QMessageBox::critical(this, "Ошибка", "Некорректное значение!");
        }
    } else {
        QMessageBox::critical(this, "Ошибка", "Некорректное значение!");
    }

}
bool MainWindow::contains0(long long number) {
    if (number == 0) {
        return false;
    }
    else if (number % 10 == 0) {
        return true;
    }
    else {
        return contains0(number / 10);
    }
}

long long MainWindow::reverse_number(long long number, long long reversed_number)
{
    if (number == 0) {
        return reversed_number;
    } else {
        long long last_digit = number % 10;
        long long remaining_number = number / 10;
        return reverse_number(remaining_number, reversed_number * 10 + last_digit);
    }
}

