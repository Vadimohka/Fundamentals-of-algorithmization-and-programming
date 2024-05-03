#include "mainwindow.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    QVBoxLayout *layout = new QVBoxLayout(this);

    QLabel *mLabel = new QLabel("Введите m:", this);
    layout->addWidget(mLabel);

    mLineEdit = new QLineEdit(this);
    layout->addWidget(mLineEdit);

    QLabel *nLabel = new QLabel("Введите n:", this);
    layout->addWidget(nLabel);

    nLineEdit = new QLineEdit(this);
    layout->addWidget(nLineEdit);

    QPushButton *button = new QPushButton("Вычислить", this);
    layout->addWidget(button);

    resultLabel = new QLabel(this);
    layout->addWidget(resultLabel);

    connect(button, &QPushButton::clicked, this, &MainWindow::calculateAckermann);
}

void MainWindow::calculateAckermann()
{
    int m = mLineEdit->text().toInt();
    int n = nLineEdit->text().toInt();

    if (m > 3)
    {
        QMessageBox::warning(this, "Ошибка", "Значение m должно быть не больше 3");
        return;
    }

    if (n > 9)
    {
        QMessageBox::warning(this, "Ошибка", "Значение n должно быть не больше 9");
        return;
    }

    int result = ackermann(m, n);

    resultLabel->setText("Результат: " + QString::number(result));
}

int MainWindow::ackermann(int m, int n)
{
    if (m == 0)
    {
        return n + 1;
    }
    else if (m > 0 && n == 0)
    {
        return ackermann(m - 1, 1);
    }
    else
    {
        return ackermann(m - 1, ackermann(m, n - 1));
    }
}
