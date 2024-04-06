#include "mainwindow.h"
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), button(new QPushButton("Преобразовать")), lineEdit(new QLineEdit), label(new QLabel) {
    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);
    layout->addWidget(lineEdit);
    layout->addWidget(button);
    layout->addWidget(label);
    setCentralWidget(centralWidget);

    connect(button, &QPushButton::clicked, this, &MainWindow::convertToBinary);
}

MainWindow::~MainWindow() {
    delete button;
    delete lineEdit;
    delete label;
}

void MainWindow::convertToBinary() {
    int decimal = lineEdit->text().toInt();
    QString binary = decimalToBinary(decimal);
    label->setText(binary);
}
QString MainWindow::decimalToBinary(int decimal) {
    if (decimal == 0) {
        return "";
    } else {
        return decimalToBinary(decimal / 2) + QString::number(decimal % 2);
    }
}
