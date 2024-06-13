#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QPushButton>
#include <QMessageBox>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QVBoxLayout *layout = new QVBoxLayout(this);

    inputEdit = new QLineEdit(this);
    layout->addWidget(inputEdit);

    QPushButton *calculateButton = new QPushButton("Преобразовать");
    layout->addWidget(calculateButton);

    answer = new QLabel("Ответ:", this);
    layout->addWidget(answer);

    connect(calculateButton, &QPushButton::clicked, this, &MainWindow::reverseNumber);
    setCentralWidget(new QWidget(this));
    centralWidget()->setLayout(layout);
}

void MainWindow::reverseNumber()
{
    bool ok;
    int n = inputEdit->text().toInt(&ok);

    if (!ok)
    {
        QMessageBox::warning(this, "Ошибка", "Некорректное значение числа");
        return;
    }

    int reversed = reverse(n, 0);

    answer->setText("Ответ: " + QString::number(reversed));
}

int MainWindow::reverse(int n, int reversed)
{
    if (n == 0)
    {
        return reversed;
    }
    else
    {
        int lastDigit = n % 10;
        return reverse(n / 10, reversed * 10 + lastDigit);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
