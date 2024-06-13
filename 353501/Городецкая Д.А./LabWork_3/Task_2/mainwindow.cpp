#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QVBoxLayout *layout = new QVBoxLayout(this);

    QLabel *labelM = new QLabel("Введите m:", this);
    layout->addWidget(labelM);

    input1LineEdit = new QLineEdit(this);
    layout->addWidget(input1LineEdit);

    QLabel *labelN = new QLabel("Введите n:", this);
    layout->addWidget(labelN);

    input2LineEdit = new QLineEdit(this);
    layout->addWidget(input2LineEdit);

    QPushButton *pushButton = new QPushButton("Преобразовать", this);
    layout->addWidget(pushButton);

    resultLabel = new QLabel("Ответ: ", this);
    layout->addWidget(resultLabel);

    connect(pushButton, &QPushButton::clicked, this, &MainWindow::computeAckermann);

    setCentralWidget(new QWidget(this));
    centralWidget()->setLayout(layout);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::computeAckermann()
{
    int m = input1LineEdit->text().toInt();
    int n = input2LineEdit->text().toInt();

    if (m < 0 || n < 0)
    {
        QMessageBox::warning(this, "Ошибка", "Значения m и n должны быть неотрицательными целыми числами");
        return;
    }

    int result = ackermann(m, n);

    if (result == -1)
    {
        QMessageBox::warning(this, "Ошибка", "Слишком большие значения m и/или n для вычисления функции Аккермана");
        return;
    }

    resultLabel->setText("Ответ: " + QString::number(result));
}

int MainWindow::ackermann(int m, int n)
{
    if (m == 0)
    {
        return n + 1;
    }
    else if (n == 0)
    {
        if (m == 1)
        {
            return 2;
        }
        else if (m == 2)
        {
            return 3;
        }
        else
        {
            return -1; // Помечаем, что слишком большие значения m и/или n
        }
    }
    else
    {
        int ackermannValue = ackermann(m, n - 1);
        if (ackermannValue == -1) // Если предыдущий вызов вернул -1, передаем этот результат дальше
        {
            return -1;
        }
        return ackermann(m - 1, ackermannValue);
    }
}
