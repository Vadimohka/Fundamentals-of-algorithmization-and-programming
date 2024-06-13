#include "task3.h"

Task3::Task3(QObject *parent)
{
    Q_UNUSED(parent);
    dialog.setWindowTitle("Перевернуть число");
    labelX.setText("Введите целое неотрицательное число");
    labelResult.setText("Результат:");
    setupInfo.setText("Перевернуть число");
    lineResult.setReadOnly(true);

    QVBoxLayout *layout = new QVBoxLayout(&dialog);
    layout->addWidget(&labelX);
    layout->addWidget(&lineX);
    connect(&setupInfo, &QPushButton::clicked, this, &Task3::calcResult);
    layout->addWidget(&setupInfo);
    layout->addWidget(&labelResult);
    layout->addWidget(&lineResult);
}

int Task3::reverse(int x, int &step)
{
    if (x==0) return 0;
    int result = reverse(x/10, step)+(x%10)*step;
    step*=10;
    return result;
}

void Task3::startDialog()
{
    dialog.exec();
}

void Task3::calcResult()
{
    bool correct = true;
    int x = lineX.text().toInt(&correct);
    if (!correct && x<0)
    {
        QMessageBox::warning(nullptr, "Ошибка", "Введите целое неотрицательное число");
        return;
    }
    int step = 1;
    lineResult.setText(QString::number(reverse(x, step)));
}
