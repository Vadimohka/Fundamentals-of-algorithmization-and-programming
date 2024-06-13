#include "mainwindow.h"
#include "reversedigits.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("Reverse Digits");
    setFixedSize(500, 250);

    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    QVBoxLayout *layout = new QVBoxLayout(centralWidget);

    numberLabel = new QLabel("Введите число:", this);
    numberLineEdit = new QLineEdit(this);
    reverseButton = new QPushButton("Перевернуть", this);
    reversedLabel = new QLabel("Число в обратном порядке:", this);
    reversedValueLabel = new QLabel(this);

    layout->addWidget(numberLabel);
    layout->addWidget(numberLineEdit);
    layout->addWidget(reverseButton);
    layout->addWidget(reversedLabel);
    layout->addWidget(reversedValueLabel);

    connect(reverseButton, &QPushButton::clicked, this, &MainWindow::reverseButtonClicked);
}

MainWindow::~MainWindow() {}

void MainWindow::reverseButtonClicked()
{
    bool conversionOk;
    int number = numberLineEdit->text().toInt(&conversionOk);

    if (conversionOk) {
        int reversed = ReverseDigits::reverse(number);
        reversedValueLabel->setText(QString::number(reversed));
    } else {
        reversedValueLabel->setText("Ошибка ввода числа!");
    }
}
