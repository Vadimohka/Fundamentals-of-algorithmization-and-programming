#include "mainwindow.h"
#include <QVBoxLayout>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);

    mInput = new QLineEdit(centralWidget);
    nInput = new QLineEdit(centralWidget);
    QPushButton *calculateButton = new QPushButton("Calculate", centralWidget);
    resultLabel = new QLabel(centralWidget);

    layout->addWidget(mInput);
    layout->addWidget(nInput);
    layout->addWidget(calculateButton);
    layout->addWidget(resultLabel);

    connect(calculateButton, &QPushButton::clicked, this, &MainWindow::calculateAckermann);

    setCentralWidget(centralWidget);
}

MainWindow::~MainWindow()
{
}

void MainWindow::calculateAckermann() {
    int m = mInput->text().toInt();
    int n = nInput->text().toInt();

    if (m < 0 || m >= 4 || n > 10 || n < 0) {
        QMessageBox::warning(this, "Input Error", "Invalid input. Please enter m between 0 and 4, and n between 0 and 10.");
        return;
    }

    int result = ackermann(m, n);
    resultLabel->setText("A(" + QString::number(m) + ", " + QString::number(n) + ") = " + QString::number(result));
}

int MainWindow::ackermann(int m, int n) {
    if (m == 0) {
        return n + 1;
    } else if (m > 0 && n == 0) {
        return ackermann(m - 1, 1);
    } else if (m > 0 && n > 0) {
        return ackermann(m - 1, ackermann(m, n - 1));
    }
    return -1; // Неверные входные данные
}
