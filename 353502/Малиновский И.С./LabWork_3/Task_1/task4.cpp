#include "task4.h"

Task4::Task4(QObject *parent)
{
    Q_UNUSED(parent);

    reshDialog.setWindowTitle("Шаги решения");
    dialog.setWindowTitle("Ханойские башни");
    labelNumber.setText("Введите количество колец");
    setupInfo.setText("Найти решение");

    QVBoxLayout *layout = new QVBoxLayout(&dialog);
    layout->addWidget(&labelNumber);
    layout->addWidget(&lineNumber);
    connect(&setupInfo, &QPushButton::clicked, this, &Task4::startReshDialog);
    layout->addWidget(&setupInfo);

    scrollArea = new QScrollArea(&reshDialog);
    scrollContent = new QWidget;
    scrollLayout = new QVBoxLayout(scrollContent);
}


void Task4::resh(int n, int start, int finish)
{
    if (n==0) return;

    resh(n-1, start, 6-start-finish);

    QLabel *label = new QLabel("Перенесите диск с столбца " + QString::number(start) + " на столбец " + QString::number(finish));
    labels.push_back(label);
    qDebug() << labels.size();
    scrollLayout->addWidget(labels.back());

    resh(n-1, 6-start-finish, finish);
}

void Task4::startDialog()
{
    lineNumber.setText("");
    dialog.exec();
}

void Task4::startReshDialog()
{
    bool correct = true;
    int n = lineNumber.text().toInt(&correct);
    if (!correct && n <= 0)
    {
        QMessageBox::warning(nullptr, "Ошибка", "Введено неккоректное значение колец");
        return;
    }
    dialog.close();

    while (!labels.empty())
    {
        delete labels.back();
        labels.back() = nullptr;
        labels.pop_back();
    }

    QVBoxLayout *layout = new QVBoxLayout(&reshDialog);
    resh(n, 1, 2);

    qDebug() << labels.size();
    reshDialog.setFixedSize(RESH_DIALOG_WIDTH, qMin(RESH_DIALOG_HIGHT, QLABEL_HIGHT*labels.size()));
    scrollArea->setWidget(scrollContent);
    scrollArea->setWidgetResizable(true);

    layout->addWidget(scrollArea);

    dialog.setLayout(layout);

    connect(&reshDialog, &QDialog::finished, [&]{
        delete layout;
        layout = nullptr;
    });
    reshDialog.exec();
}
