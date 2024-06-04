#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_calculate_clicked()
{
    QString inputText = ui->lineEdit->text();
    bool conversionOK;
     long long number=inputText.toLongLong(&conversionOK);
    if (conversionOK) {
         if (inputText.contains('0')) {
             QMessageBox::critical(this, "Ошибка", "Число содержит нули.");
             ui->lineEdit->clear();

             return;
         }
        // Преобразование прошло успешно
        QMessageBox::information(this, "Успех", QString("Значение long long: %1").arg(number));
    } else {
        // Произошла ошибка при преобразовании
        QMessageBox::critical(this, "Ошибка", "Неверный формат числа");
        ui->lineEdit->clear();
    }
    long long result=reverseNumber(number, 0);
    ui->textEdit->setText(QString::number(result) );

}

long long  MainWindow::reverseNumber(long long n, long long reversed) {
    // Базовый случай: когда исходное число становится равным нулю, возвращаем перевернутое число
    if (n == 0) {
        return reversed;
    }

    // Получаем последнюю цифру исходного числа
    long long digit = n % 10;

    // Умножаем текущее перевернутое число на 10 и добавляем к нему последнюю цифру исходного числа
    // Это эффективно добавляет последнюю цифру исходного числа в начало перевернутого числа
    reversed = reversed * 10 + digit;

    // Рекурсивно вызываем функцию для оставшихся цифр исходного числа
    return reverseNumber(n / 10, reversed);
}
