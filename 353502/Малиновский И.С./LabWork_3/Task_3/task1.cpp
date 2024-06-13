#include "task1.h"

Task1::Task1(QObject *parent)
{
    Q_UNUSED(parent);

    dialog.setWindowTitle("Перевод числа в двоичную СИ");
    labelNumber.setText("Введите целое неотрицательное число:");
    labelResult.setText("Число в двоичной системе счисления:");
    setupInfo.setText("Перевести число в двоичную СИ");
    lineResult.setReadOnly(true);

    QVBoxLayout *layout = new QVBoxLayout(&dialog);
    layout->addWidget(&labelNumber);
    layout->addWidget(&lineNumber);
    connect(&setupInfo, &QPushButton::clicked, this, &Task1::calcResult);
    layout->addWidget(&setupInfo);
    layout->addWidget(&labelResult);
    layout->addWidget(&lineResult);
}

QString Task1::conversion(int x)
{
    if (x == 0) return "";
    return conversion(x / 2) + QChar('0' + x % 2);
}

void Task1::startDialog()
{
    dialog.exec();
}

void Task1::calcResult()
{
    bool correct = true;
    int number = lineNumber.text().toInt(&correct);
    if (number < 0 || !correct)
    {
        QMessageBox::warning(nullptr, "Ошибка", "Введите целое неотрицательное число");
        return;
    }
    lineResult.setText((number == 0 ? "0" : conversion(number)));
}
