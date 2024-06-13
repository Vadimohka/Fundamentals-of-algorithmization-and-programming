#include "task2.h"

Task2::Task2(QObject *parent)
{
    Q_UNUSED(parent);

    labelN.setText("Введите N:");
    labelM.setText("Введите M:");
    labelResult.setText("Результат:");
    setupInfo.setText("Посчитать результат");
    dialog.setWindowTitle("Функция Аккермана");
    lineResult.setReadOnly(true);

    QVBoxLayout *layout = new QVBoxLayout(&dialog);

    layout->addWidget(&labelM);
    layout->addWidget(&lineM);
    layout->addWidget(&labelN);
    layout->addWidget(&lineN);
    connect(&setupInfo, &QPushButton::clicked, this, &Task2::calcResult);
    layout->addWidget(&setupInfo);
    layout->addWidget(&labelResult);
    layout->addWidget(&lineResult);
}

int Task2::ackerman(int m, int n)
{
    if (m==0) return n+1;
    if (n==0) return ackerman(m-1, 1);
    return ackerman(m-1, ackerman(m, n-1));
}

void Task2::startDialog()
{
    dialog.exec();
}

void Task2::calcResult()
{
    bool correct = true;
    int m=lineM.text().toInt(&correct);
    if (!correct || m<0)
    {
        QMessageBox::warning(nullptr, "Ошибка", "Введите неотрицательное m");
        return;
    }
    int n=lineN.text().toInt(&correct);
    if (!correct || n<0)
    {
        QMessageBox::warning(nullptr, "Ошибка", "Введите неотрицательное n");
        return;
    }
    lineResult.setText(QString::number(ackerman(m, n)));
}
